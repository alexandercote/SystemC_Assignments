#include "systemc.h"
#include <iostream>
#include <iomanip>

using namespace std;

#define RDBYT 1
#define WTBYT 2
#define WTBLK 3
#define RDBLK 0

static sc_logic Z[8] = {SC_LOGIC_Z, SC_LOGIC_Z, SC_LOGIC_Z, SC_LOGIC_Z, SC_LOGIC_Z, SC_LOGIC_Z, SC_LOGIC_Z, SC_LOGIC_Z};

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
		        cout << "------------------------------------------------------------" << endl;
			cout << "TEST STRUCTURE: Tests 1-3 are RDBYT, WRBYT. Tests 4-6 are RDBLK, WRBLK." << endl;
			cout << "TEST METHODOLOGY: Read from address, write to same address different value, read back address to validate." << endl;
		
			// TEST 1 - RDBYT - Read 8 bits of data from address 3.
			cout << "------------------------------------------------------------" << endl;
			cout << "TEST 1: READ 8-bits of data from address 3. Expected XXXXXXXX" << endl;
			cout << "Validating that RDBYT will read unintialized memory, and return garbage." << endl;
			addr.write(3);
			comm.write(RDBYT);
			wait();
			new_comm.write(true);
			while( complete.read() == false )
			{
				wait();
			}
			data_read = data.read();
			cout << "@"<< setw(6) << sc_time_stamp() << ": TST MODULE : RDBYT, address = "
				 << addr << ", data = " << data_read << endl;
			new_comm.write(false);
			wait();
		  
		  
			// TEST 2 - WTBYT - Write 8-bits of data to address 3.
		        cout << "------------------------------------------------------------" << endl;
			cout << "TEST 2: Write 8-bits of data to address 3." << endl;
			cout << "Validating WTBYT by writing to the memory just read from, knowing its previous state was garbage." << endl;
			data.write(4);
			addr.write(3);
			comm.write(WTBYT);
			wait();
			cout << "@" << setw(6) << sc_time_stamp() << ": TST MODULE : WTBYT, address = "
			     << addr << ", data = " << data << endl;
			new_comm.write(true);
			while( complete.read() == false )
			{
				wait();
			}
			new_comm.write(false);
			data.write(Z);
			wait();
		
			
			// TEST 3 - RDBYT - Read 8 bits of data from addr 3.
			cout << "------------------------------------------------------------" << endl;
			cout << "TEST 3: READ 8-bits of data from address 3. Expected 00000100" << endl;
			cout << "Validating RDBYT by reading the address just written to. Should be different result than Test 1." << endl;
			addr.write(3);
			comm.write(RDBYT);
			wait();
			new_comm.write(true);
			while( complete.read() == false )
			{
				wait();
			}
			data_read = data.read();
			cout << "@"<< setw(6) << sc_time_stamp() << ": TST MODULE : RDBYT, address = "
			     << addr << ", data = " << data_read << endl;
			new_comm.write(false);
			wait();
		
			
			// TEST 4 - RDBLK -  Read 8 bits of data from address 0
			cout << "------------------------------------------------------------" << endl;
			cout << "TEST 4: Read 4 x 8bits of data from 4 consecutive memory address, starting at address 0." << endl;
			cout << "Expected: XXXXXXXX , XXXXXXXX, XXXXXXXX, 00000100" << endl;
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
			
			
			// TEST 5 - WRBLK -  Write 8-bits of data in 4 addresses starting from 0.
			cout << "------------------------------------------------------------" << endl;
			cout << "TEST 5: Write 4 x 8bits of data into 4 consecutive memory address, starting from address 0." << endl;
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
		  
			
			// TEST 6 - RDBLK -  Read 8 bits of data from address 0
			cout << "------------------------------------------------------------" << endl;
			cout << "TEST 6: Read 4 x 8bits of data from 4 consecutive memory address, starting at address 0." << endl;
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
			
			
			// end simulation
			sc_stop();
			wait();
			
			
			
		} // end while true loop
			
	}

    SC_CTOR (A2Q1_testbench)
    {
        SC_CTHREAD(stimulus, clk.pos() );
    }

};








