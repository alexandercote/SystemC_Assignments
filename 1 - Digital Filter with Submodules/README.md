# 1 - Digital Filter with Submodules

Consider the digital filter shown below, where z<sup>-1</sup> means a delay of 1 clock cycle. 

![image](https://user-images.githubusercontent.com/978364/57806557-37c1a680-7714-11e9-80dd-01ea2a4272fb.PNG)

In addition to the clock and reset inputs, the filter has one float-type input x and one float-type output y. Assume that the (multiplication) coefficients have the constant values a<sub>1</sub> = 0.5 and a<sub>2</sub> = 0.25, with a<sub>0</sub> = –1.
- First, create individual SystemC modules for the float-type adder, multiplier, and clocked z<sup>-1</sup> register with reset. 
- Then, create instances of these modules as needed and connect them together to obtain a top-level structural description of our filter.
- Next, introduce a clocked stimulus generator and a clocked result monitor: your testbench must start with a reset, then send a 1-cycle unit pulse to x and observethe pulse response on y. 
- Finally, write sc_main() with waveform tracing of reset, clock, x, and y over 20 data samples. 

The code submission must be self-contained.
