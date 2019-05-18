
#include "systemc.h"
#include <iomanip>

SC_MODULE(a1_monitor)
{
    sc_in <float> x_input, y_output;
    sc_in <bool> reset;
    sc_in_clk clock;

    void monitor()
    {
        cout << setw(10) << "Time";
        cout << setw(2) << "X" << setw(2) << "Y";
        cout << setw(4) << "RST" << endl;
        while (true) 
        {
            cout << setw(10) << sc_time_stamp();
            cout << setw(2) << x_input.read() << setw(2) << y_output.read();
            cout << setw(4) << reset.read() << endl;
            wait(); // wait until next event on x, y or reset
        }
    }

    SC_CTOR (a1_monitor)
    {
        SC_CTHREAD(monitor, clock.pos() );
        sensitive ( reset, x_input, y_output );
        dont_initialize();
    }
};
