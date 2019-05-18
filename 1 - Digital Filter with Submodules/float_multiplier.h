
#include "systemc.h"

SC_MODULE(float_multiplier)
{
    sc_in <float> A, B;
    sc_out <float> F;

    void float_mult()
    {
        F.write( A.read() * B.read() );
    }

    SC_CTOR (float_multiplier)
    {
        SC_METHOD(float_mult);
        sensitive ( A, B )
    }

};
