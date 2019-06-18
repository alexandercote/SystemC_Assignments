#include "systemc.h"
#include "fifo_if.h"
#include <iostream>
#include <iomanip>
using namespace std;

template <class T> class producer : public sc_module 
{
	public:
		sc_port < fifo_out_if<T> > out;
		sc_in <bool> Clock; 


		void do_writes()
		{
			T data = 0;
			while (true) 
			{
				wait();
				if (out->write(data))
				{
					cout << "@" << setw(6) << sc_time_stamp() << " : Read    "
						    << " , Wrote " << setw(2) << data << "  " << endl; 
					
				}
				data = (data + 1) % 10;
				
			} // end while
		} // end do writes
		
		SC_CTOR (producer) 
		{
			SC_THREAD (do_writes);
			sensitive << Clock.pos();
		}
};
	  
