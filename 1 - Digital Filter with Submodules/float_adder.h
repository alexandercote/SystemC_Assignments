
#include "systemc.h"

SC_MODULE(float_adder)
{
    sc_in <float> input1, input2;
    sc_out <float> outputval;

    void float_add()
    {
        outputval.write( input1.read() + input2.read() );
    }

    SC_CTOR (float_adder)
    {
        SC_METHOD(float_add);
        sensitive << input1 << input2;
    }

};
