
#include "systemc.h"

SC_MODULE(float_register)
{
    sc_in <bool> reset;
    sc_in_clk clock;

    sc_in <float> inputval;
    sc_out <float> outputval;

    void delay_output()
    {
        sc_signal<float> delay_store = 0;
        output.write(0);  

        while(true)
        {
            if(reset.read() == true)
            {
                delay_store.write(0);
                output.write(0);
            }
            else
            {
                if(delay_store != 0)
                {
                    outputval.write(delay_store);
                }
                delay_store.write(inputval);
            }
        wait();   
        }
    }

    SC_CTOR (float_register){
        SC_CTHREAD(delay_output);
        sensitive ( reset, clock )
    }

};
