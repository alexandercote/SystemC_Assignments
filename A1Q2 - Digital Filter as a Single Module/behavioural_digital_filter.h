#include "systemc.h"

SC_MODULE( a2_digital_filter )
{
    sc_in <float> x_input;
    sc_in <bool> reset;
    sc_in_clk clock;

    sc_out <float> y_output;

    // Register variables
    sc_signal <float> zdelay_1_in, zdelay_2_in;
    sc_signal <float> zdelay_1_out, zdelay_2_out;

    void digital_filter()
    {
        zdelay_1_in.write( x_input.read() - ( 0.5*zdelay_1_out.read() + 0.25*(zdelay_2_out.read() + x_input.read() ) ) );
        zdelay_2_in.write( zdelay_1_out.read() );
        y_output.write( zdelay_2_out.read() + ( 0.5*zdelay_1_out.read() + 0.25*(zdelay_2_out.read() + x_input.read() ) ) );
    }

    void update_signals()
    {
        zdelay_1_out.write(0);
        zdelay_2_out.write(0);

        while(true)
        {
            zdelay_1_out.write(zdelay_1_in.read());
            zdelay_2_out.write(zdelay_2_in.read());
            wait();
        }
    }


    SC_CTOR (a2_digital_filter)
    {
        SC_METHOD(digital_filter);
        sensitive << x_input << zdelay_1_out << zdelay_2_out;
        SC_CTHREAD(update_signals, clock.pos());
        reset_signal_is(reset, true);
    }
};
