
#include "systemc.h"
#include <iostream>
#include <iomanip>
using namespace std;

SC_MODULE(monitor)
{
    sc_in <float> x_input;
    sc_in <float> y_output;
    sc_in_clk clock;

    void monitor_func()
    {
        cout << setw(10) << "Time";
        cout << setw(2) << "X" << setw(2) << "Y";
        while (true) 
        {
            cout << setw(10) << sc_time_stamp();
            cout << setw(2) << x_input.read() << setw(2) << y_output.read();
            wait(); // wait until next event on x, y
	}
    }

    SC_CTOR (monitor)
    {
        SC_THREAD(monitor_func);
        sensitive << x_input << y_output;
        dont_initialize();
    }
};
