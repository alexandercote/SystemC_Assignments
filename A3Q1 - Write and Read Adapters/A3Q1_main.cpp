#include "systemc.h"
#include "modules.h"

int sc_main (int argc, char* argv[]) {
	DF_Const <int> constant ("constant", 1); // constant = 1
	DF_Adder <int> adder ("adder");
	DF_Fork <int> fork("fork");
	DF_Printer <int> printer ("printer", 10); // 10 interations
	sc_fifo <int> const_out ("const_out", 1); // FIFO of size 1
	sc_fifo <int> adder_out ("adder_out", 1); // FIFO of size 1
	sc_fifo <int> printer_in ("printer_in", 1); // FIFO of size 1
	sc_fifo <int> feedback ("feedback", 1); // FIFO of size 1
	feedback.write (40); // do not forget about initialization!
	
	constant.output (const_out); printer.input (printer_in);
	adder.input1 (const_out); adder.input2 (feedback); adder.output (adder_out);
	fork.input (adder_out); fork.output1 (feedback); fork.output2 (printer_in);
	// Start simulation without time limit
	// The printer module is responsible for stopping the simulation
	sc_start (-1);
	return 0;
}