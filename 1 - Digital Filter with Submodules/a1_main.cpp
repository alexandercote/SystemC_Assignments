#include "systemc.h"
#include "a1_monitor.h"
#include "a1_stimgen.h"
#include "float_adder.h"
#include "float_multiplier.h"
#include "float_register.h"
#include <iostream>
#include <iomanip>

int sc_main()
{
    sc_signal <float> XSig;
    sc_signal <float> YSig;
    sc_signal <bool> RstSig;
    sc_clock TestClk ("Testclock", 10, SC_NS, 0.5, 0, SC_NS);


    stimgen Stimulus1 ("Stimulator");
    Stimulus1.x_input(XSig); 
    Stimulus1.reset(RstSig);
    Stimulus1.clock(TestClk);

    monitor Monitor1 ("MonitorTask");
    Monitor1.x_input(XSig);
    Monitor1.y_output(YSig);
    Monitor1.reset(RstSig);
    Monitor1.clock(TestClk);

    digital_filter DF1 ("A1_Digital_Filter");
    DF1.x_input(XSig);
    DF1.y_output(YSig);
    DF1.reset(RstSig);
    DF1.clock(TestClk);


    sc_trace_file* Tf = sc_create_vcd_trace_file ("a1_digital_filter_traces");
    Tf->set_time_unit(1, SC_NS); // Time unit is 1 ns
    sc_trace(Tf, XSig, "X");
    sc_trace(Tf, YSig, "Y");
    sc_trace(Tf, RstSig, "RST");


    sc_start (20, SC_NS);

    sc_close_vcd_trace_file(Tf);

    return 0;
};
