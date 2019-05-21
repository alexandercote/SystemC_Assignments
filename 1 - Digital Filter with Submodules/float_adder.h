
#include "systemc.h"

SC_MODULE(float_adder)
{
    sc_in <float> A, B;
    sc_out <float> F;

    void float_add()
    {
        F.write( A.read() + B.read() );
    }

    SC_CTOR (float_adder)
    {
        SC_METHOD(float_add);
        sensitive << A << B;
    }

};
