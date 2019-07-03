#include "systemc.h"
#include "Hardware_FIFO.h"
#include "HW_adder.h"
#include "DF_fork.h"
#include "DF_printer.h"
#include "DF_const.h"
#include "read_adapter.h"

int sc_main (int argc, char* argv[]) {
	sc_clock TestClk ("Testclock", 10, SC_NS, 0.5, 1, SC_NS);
	
	DF_Const<int>     constant   ("constant", 1); // constant = 1
	HW_Adder<int>     adder      ("adder");
	FIFO_READ_HS<int> Radapter   ("Radapt");
	DF_Fork<int>      fork       ("fork");
	DF_Printer<int>   printer    ("printer", 10); // 10 interations
	sc_fifo<int>      const_out  ("const_out", 1); // FIFO of size 1
	hw_fifo<int>      adder_out  ("adder_out", 1); // FIFO of size 1
	sc_fifo<int>      printer_in ("printer_in", 1); // FIFO of size 1
	sc_fifo<int>      feedback   ("feedback", 1); // FIFO of size 1
	feedback.write (40); // do not forget about initialization!
	
	// Temp signals
	sc_signal <int>  adder_data    ("adder_data");
	sc_signal <bool> adder_valid   ("adder_valid");
	sc_signal <bool> adder_ready   ("adder_ready");
	sc_signal <int>  fork_data     ("fork_data");
	sc_signal <bool> adapter_valid ("adapter_valid");
	sc_signal <bool> adapter_ready ("adapter_ready");


	// 1 - Constant Block
	constant.output (const_out); 
	
	
	// 2 - Adder Block
	adder.input1 (const_out);
	adder.input2 (feedback);
	adder.clock  (TestClk);	
	adder.data   (adder_data);    // output
	adder.valid  (adder_valid);   // output
	adder.ready  (adder_ready);   // input
	
	// 3 - Hardware FIFO
	adder_out.clk       (TestClk);
	adder_out.data_in   (adder_data ); // input
	adder_out.valid_in  (adder_valid); // input
	adder_out.ready_in  (adapter_ready);  // input
	adder_out.data_out  (fork_data  );     // output
	adder_out.valid_out (adapter_valid );  // output
	adder_out.ready_out (adder_ready );    // output
	
	// 4 - Read Adapter
	Radapter.clock  (TestClk); 
	Radapter.data   (fork_data);      // input
	Radapter.valid  (adapter_valid);  // input
	Radapter.ready  (adapter_ready);     // output

	// 5 - Fork
	fork.input (Radapter); 
	fork.output1 (feedback); 
	fork.output2 (printer_in);
	
	// 6 - Printer
	printer.input (printer_in);
	
	// Start simulation without time limit
	// The printer module is responsible for stopping the simulation
	sc_start ();
	return 0;
}
