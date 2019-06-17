#include "systemc.h"
#include "fifo_if.h"
#include <iostream>
#include <iomanip>
using namespace std;

template <class T> class consumer : public sc_module 
{
	public:
		sc_port < fifo_in_if<T> > in;
		sc_in <bool> Clock;
			  
		void do_reads()
		{
			T data;
			while (true) 
			{

				if (in->read(data))
				{	
					cout << "R " << data << " at " << sc_time_stamp() << endl;
				}
			
				wait();
			} // end while
		} // end do reads
		
		SC_CTOR (consumer) 
		{
			SC_THREAD (do_reads);
			sensitive << Clock.pos();
		}
};