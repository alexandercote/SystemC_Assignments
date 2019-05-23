
#include "systemc.h"

SC_MODULE(float_register)
{
    sc_in <bool> reset;
    sc_in_clk clock;

    sc_in <float> inputval;
    sc_out <float> outputval;

    sc_signal<float> delay_store;

    void delay_output()
    {
        delay_store.write(0);
        outputval.write(0);  

        while(true)
        {
	     delay_store.write(inputval);
	     wait();   
	     outputval.write(delay_store);
        }
    }

    SC_CTOR (float_register){
        SC_CTHREAD(delay_output, clock.pos() );
        reset_signal_is(reset, true);
    }

};
