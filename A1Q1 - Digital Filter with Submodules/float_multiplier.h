
#include "systemc.h"

SC_MODULE(float_multiplier)
{
    sc_in <float> input1, input2;
    sc_out <float> outputval;

    void float_mult()
    {
        outputval.write( input1.read() * input2.read() );
    }

    SC_CTOR (float_multiplier)
    {
        SC_METHOD(float_mult);
        sensitive <<  input1  << input2;
    }

};
