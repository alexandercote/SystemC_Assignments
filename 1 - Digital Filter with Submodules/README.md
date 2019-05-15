# 1 - Digital Filter with Submodules

Consider the digital filter shown below, where z^–1 means a delay of 1 clock cycle. 


In addition to the clock and reset inputs, the filter has one float-type input x and one float-type output y. Assume that the (multiplication) coefficients have the constant values a_1 = 0.5 and a_2 = 0.25, with a_0 = –1.
- First, create individual SystemC modules for the float-type adder, multiplier, and clocked z^–1 register with reset. 
- Then, create instances of these modules as needed and connect them together to obtain a top-level structural description of our filter.
- Next, introduce a clocked stimulus generator and a clocked result monitor: your testbench must start with a reset, then send a 1-cycle unit pulse to x and observethe pulse response on y. 
- Finally, write sc_main() with waveform tracing of reset, clock, x, and y over 20 data samples. 

The code submission must be self-contained.
