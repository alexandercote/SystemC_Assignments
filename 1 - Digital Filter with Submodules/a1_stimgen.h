
#include "systemc.h"
#include <iomanip>

SC_MODULE(a1_stim)
{
    sc_out <float> x_input;
    sc_out <bool> reset;
    sc_in_clk clock;

    void stimgen()
    {
        // Pulse 1 - Reset goes high
        reset.write(true); 
        wait();
        // Pulse 2 - Reset goes low, X goes high.
        reset.write(false)
        x_input.write(1);
        wait();
        // Pulse 3 - Set X low
        x_input.write(0);
        wait();

        sc_stop();
    }

    SC_CTOR (a1_stim)
    {
        SC_CTHREAD(stimgen, clock.pos() );
        x_input.initialize(0);
        reset.initialize(false);
    }

};
