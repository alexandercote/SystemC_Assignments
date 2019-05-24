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
        zdelay_1_in.write( x_input.read() - ( 0.5*zdelay_1_out.read() + 0.25(zdelay_2_out.read() + x_input.read() ) ) );
        zdelay_2_in.write( zdelay_1_out.read() );
        y_output.write( zdelay_2_out.read() + ( 0.5*zdelay_1_out.read() + 0.25(zdelay_2_out.read() + x_input.read() ) ) );
    }

    void update_signals()
    {
        //sc_signal<float> delay_store_1, delay_store_2;
        //delay_store_1.write(0);
        //delay_store_2.write(0);
        zdelay_1_out.write(0);
        zdelay_2_out.write(0);

        while(true)
        {
            zdelay_1_out.write(zdelay_1_in.read());
            zdelay_2_out.write(zdelay_2_in.read());
            wait();
            /*
            delay_store_1.write(zdelay_1_in.read());
            delay_store_2.write(zdelay_2_in.read());

            wait();

            zdelay_1_out.write(delay_store_1.read());
            zdelay_2_out.write(delay_store_2.read());
            */
        }
    }


    SC_CTOR (a2_digital_filter):
        SC_METHOD(digital_filter);
        sensitive << x_input << zdelay_1 << zdelay_2;
        SC_CTHREAD(update_signals, clock.pos());
        reset_signal_is(reset, true);

    {
 




    }
};
