#include "systemc.h"

#define RDBLK 0
#define RDBYT 1
#define WTBYT 2
#define WTBLK 3

static sc_logic Z[8] = {SC_LOGIC_Z, SC_LOGIC_Z, SC_LOGIC_Z, SC_LOGIC_Z,
                SC_LOGIC_Z, SC_LOGIC_Z, SC_LOGIC_Z, SC_LOGIC_Z};

SC_MODULE(A2Q1_testbench)
{
    // Ports
    sc_inout <sc_lv<8> > data; // Bidirectional port of logic-vector type
    sc_out < sc_uint<8> > addr;
    sc_out < sc_uint<2> > comm;
    sc_out <bool> new_comm;     // Input port signaling “start”
    sc_in <bool> complete;    // Output port signaling “done”
    sc_in_clk clk;
    sc_out <bool> reset;


    void stimulus()
    {  
        // Temp variables for comparison
        sc_lv <8> data_read;
      
        // Reset system at start.
        reset.write(true); 
        wait();
        reset.write(false);
        wait();
      
		while(true)
		{
		
			// Command 1 - Write 8-bits of data.
			data.write(4);
			addr.write(8);
			comm.write(WTBYT);
			wait();
			new_comm.write(true);
			while( complete.read() == false )
			{
				wait();
			}
			new_comm.write(false);
			data.write(Z);
			wait();
		
		
			// Command 2 - Read 8 bits of data from start.
			addr.write(0);
			comm.write(RDBYT);
			wait();
			new_comm.write(true);
			while( complete.read() == false )
			{
				wait();
			}
			
			data_read = data.read();
			new_comm.write(false);
			wait();
			
		
			// Command 3 - Read 8 bits of data from addr 4.
			addr.write(4);
			comm.write(RDBYT);
			wait();
			new_comm.write(true);
			while( complete.read() == false )
			{
				wait();
			}
			
			data_read = data.read();
			new_comm.write(false);
			wait();
		
			// Command 4 - Write 8-bits of data in 4 address.
			data.write(0xEE); // set-up for WTBLK command
            addr.write(0x00);
            comm.write(WTBLK);
            wait();
            new_comm.write(true);
            wait();
            data.write(0xDD);
            wait();
            data.write(0xCC);
            wait();
            data.write(0xBB);
			while( complete.read() == false )
			{
				wait();
			}
			new_comm.write(false);
			data.write(Z);
			wait();
		  
			
			// Command 5 - Read 8 bits of data from address 0
			addr.write(0);
			comm.write(RDBLK);
			wait();
			new_comm.write(true);
			while( complete.read() == false )
			{
				wait();
			}
			
			new_comm.write(false);
			wait();
			
			
			
		} // end while true loop
			
	}

    SC_CTOR (A2Q1_testbench)
    {
        SC_CTHREAD(stimulus, clk.pos() );
        reset.initialize(false);
    }

};








