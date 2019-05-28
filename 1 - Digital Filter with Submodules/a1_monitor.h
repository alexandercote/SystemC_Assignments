
#include "systemc.h"
#include <iostream>
#include <iomanip>
using namespace std;

SC_MODULE(a1_monitor)
{
    sc_in <float> x_input;
    sc_in <float> y_output;
    sc_in_clk clock;

    void monitor_func()
    {
        cout << setw(10) << "Time";
        cout << setw(3) << "X" << setw(12) << "Y";
	cout << endl;
        while (true) 
        {
            cout << setw(10) << sc_time_stamp();
            cout << setw(3) << x_input.read() << setw(12) << y_output.read();
	    cout << endl;
            wait(); // wait until next event on x, y
	}
    }

    SC_CTOR (a1_monitor)
    {
        SC_THREAD(monitor_func);
        sensitive << x_input << y_output;
        dont_initialize();
    }
};
