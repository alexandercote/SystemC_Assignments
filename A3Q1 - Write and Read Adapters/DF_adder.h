#include "systemc.h"


// Simple dataflow adder
template <class T> SC_MODULE (DF_Adder) {
	sc_fifo_in <T> input1, input2;
	sc_fifo_out <T> output;
	
	void process() {
		while (1) output.write (input1.read() + input2.read());
	}
	
	SC_CTOR (DF_Adder) {
		SC_THREAD (process);
	}
}; 


// This adapter converts the FIFO write interface into a bi-directional handshake protocol
// It is a hierarchical channel that implements the sc_fifo_out_if interface
// It has 4 ports: 1 for the data, 1 for the clock, and 2 for the control lines
template <class T> class FIFO_WRITE_HS : public sc_module, public sc_fifo_out_if <T> {
	public:
	sc_in_clk clock; sc_out <T> data; sc_out <bool> valid; sc_in <bool> ready;
	void write (const T& x) { // blocking write
		data.write (x) ; valid.write (true); // drive data line, signal that data is valid
		// Wait until data is read
		do { wait (clock->posedge_event()); } while (ready.read() != true);
		valid.write (false); // make sure data is not read twice
	}
	
	SC_CTOR (FIFO_WRITE_HS) { valid.initialize (false); }
	// Here, provide dummy implementations for unneeded sc_fifo_out_if <T> methods
};



