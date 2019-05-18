#include "systemc.h"
#include "float_adder.h"
#include "float_multiplier.h"
#include "float_register.h"

SC_MODULE( a1_digital_filter )
{
    sc_in <float> x_input;
    sc_in <bool> reset;
    sc_in_clk clock;

    sc_out <float> y_output;

    float_register zdelay_1, zdelay_2;
    float_adder add_1, add_2, add_3, add_4;
    float_multiplier mult_1, mult_2, mult_3

    sc_signal <float> output_reg_1;
    sc_signal <float> output_reg_2;
    sc_signal <float> output_add_1;
    sc_signal <float> output_add_2;
    sc_signal <float> output_add_3;
    sc_signal <float> output_add_4;
    sc_signal <float> output_mult_1;
    sc_signal <float> output_mult_2;
    sc_signal <float> output_mult_3;


    SC_CTOR (a1_digital_filter):
        zdelay_1("Leftmost Delay Filter"),
        zdelay_2("Rightmost Delay Filter"),
        add_1("X with Feedback"),
        add_2("Delay And Add Result"),
        add_3("2nd Delay and Feedforward"),
        add_4("2nd Delay and Add_2"),
        mult_1("Add_2 to Add_1"),
        mult_2("Delay to Add_2"),
        mult_3("Add_3 to Add_2")

    {
        // Registers

        //float_register zdelay_1("Leftmost Delay Filter");
        zdelay_1.reset(reset);
        zdelay_1.clock(clock);
        zdelay_1.inputval(output_add_1);
        zdelay_1.outputval(output_reg_1);

        //float_register zdelay_2("Rightmost Delay Filter");
        zdelay_2.reset(reset);
        zdelay_2.clock(clock);
        zdelay_2.inputval(output_reg_1);
        zdelay_2.outputval(output_reg_2);


        // Adders

        //float_adder add_1("X with Feedback")
        add_1.input1(x_input);
        add_1.input2(output_mult_1);
        add_1.outputval(output_add_1);

        //float_adder add_2("Delay And Add Result")
        add_2.input1(output_mult_2);
        add_2.input2(output_mult_3);
        add_2.outputval(output_add_2);

        //float_adder add_3("2nd Delay and Feedforward")
        add_3.input1(output_reg_2);
        add_3.input2(x_input);
        add_3.outputval(output_add_3);

        //float_adder add_4("2nd Delay and Add_2")
        add_4.input1(output_reg_2);
        add_4.input2(output_add_2);
        add_4.outputval(output_add_4);


        // Multipliers
        mult_1.input1(output_add_2);
        mult_1.input2(-1);
        mult_1.outputval(output_mult_1);

        mult_2.input1(output_reg_1);
        mult_2.input2(0.5);
        mult_2.outputval(output_mult_2);

        mult_3.input1(output_add_3);
        mult_3.input2(0.25);
        mult_3.outputval(output_mult_3);




    }
}