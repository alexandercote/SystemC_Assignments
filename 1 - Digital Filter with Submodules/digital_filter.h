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
    float_multiplier mult_1, mult_2, mult_3;

    sc_signal <float> output_reg_1;
    sc_signal <float> output_reg_2;
    sc_signal <float> output_add_1;
    sc_signal <float> output_add_2;
    sc_signal <float> output_add_3;
    sc_signal <float> output_mult_1;
    sc_signal <float> output_mult_2;
    sc_signal <float> output_mult_3;

    sc_signal <float> mult_1_const;
    sc_signal <float> mult_2_const;
    sc_signal <float> mult_3_const;


    SC_CTOR (a1_digital_filter):
        zdelay_1("Leftmost_Delay_Filter"),
        zdelay_2("Rightmost_Delay_Filter"),
        add_1("X_with_Feedback"),
        add_2("Delay_And_Add_Result"),
        add_3("Second_Delay_and_Feedforward"),
        add_4("Second_Delay_and_Add_2"),
        mult_1("Add_2_to_Add_1"),
        mult_2("Delay_to_Add_2"),
        mult_3("Add_3_to_Add_2")

    {
        // Constant Variable Definitions
        mult_1_const.write(-1);
        mult_2_const.write(0.5);
        mult_3_const.write(0.25);


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

        //float_adder add_3("2nd_Delay_and_Feedforward")
        add_3.input1(output_reg_2);
        add_3.input2(x_input);
        add_3.outputval(output_add_3);

        //float_adder add_4("2nd_Delay_and_Add_2")
        add_4.input1(output_reg_2);
        add_4.input2(output_add_2);
        add_4.outputval(y_output);


        // Multipliers
        mult_1.input1(output_add_2);
        mult_1.input2(mult_1_const);
        mult_1.outputval(output_mult_1);

        mult_2.input1(output_reg_1);
        mult_2.input2(mult_2_const);
        mult_2.outputval(output_mult_2);

        mult_3.input1(output_add_3);
        mult_3.input2(mult_3_const);
        mult_3.outputval(output_mult_3);

    }
};
