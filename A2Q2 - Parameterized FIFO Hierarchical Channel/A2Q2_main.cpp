#include "systemc.h"
#include "producer.h"
#include "consumer.h"
#include "fifo.h"
#include <iostream>
#include <iomanip>

int sc_main(int argc, char* argv[])
{
	sc_clock ClkFast ("ClkFast", 5,  SC_NS, 0.5, 1, SC_NS);
	sc_clock ClkSlow ("ClkSlow", 10, SC_NS, 0.5, 1, SC_NS);

	fifo Fifo1 (”F1”, int, 8); // 8-integer FIFO
	producer P1 ("P1"); P1.out (Fifo1); P1.Clock (ClkFast);
	consumer C1 ("C1"); C1.in (Fifo1);  C1.Clock (ClkSlow);
	 
    sc_start (210, SC_NS);

    return 0;
}

