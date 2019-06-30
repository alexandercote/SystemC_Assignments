#include "systemc.h"


// Simple dataflow adder
template <class T> SC_MODULE (HW_Adder) {
	sc_fifo_in <T> input1, input2;
	sc_in_clk clock; 
	sc_out <T> data; 
	sc_out <bool> valid; 
	sc_in <bool> ready;
	
	void write (const T& x) { // blocking write
		data.write (x) ; valid.write (true); // drive data line, signal that data is valid
		// Wait until data is read
		do { wait (clock->posedge_event()); } while (ready.read() != true);
		valid.write (false); // make sure data is not read twice
	}
	
	void process() {
		while (1) write (input1.read() + input2.read());
	}
	
	SC_CTOR (HW_Adder) {
		SC_THREAD (process);
		valid.initialize (false);
	}
}; 



