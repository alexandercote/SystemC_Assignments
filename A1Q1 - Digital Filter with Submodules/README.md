# 1 - Digital Filter with Submodules

Consider the digital filter shown below, where z<sup>-1</sup> means a delay of 1 clock cycle. 

![image](https://user-images.githubusercontent.com/978364/57806557-37c1a680-7714-11e9-80dd-01ea2a4272fb.PNG)

In addition to the clock and reset inputs, the filter has one float-type input x and one float-type output y. Assume that the (multiplication) coefficients have the constant values a<sub>1</sub> = 0.5 and a<sub>2</sub> = 0.25, with a<sub>0</sub> = –1.
- First, create individual SystemC modules for the float-type adder, multiplier, and clocked z<sup>-1</sup> register with reset. 
- Then, create instances of these modules as needed and connect them together to obtain a top-level structural description of our filter.
- Next, introduce a clocked stimulus generator and a clocked result monitor: your testbench must start with a reset, then send a 1-cycle unit pulse to x and observethe pulse response on y. 
- Finally, write sc_main() with waveform tracing of reset, clock, x, and y over 20 data samples. 

The code submission must be self-contained.




Outputs:

      Time  X           Y
     11 ns  1           0
     11 ns  1        0.25
     21 ns  0        0.25
     21 ns  0       0.625
     21 ns  0       0.375
     31 ns  0       1.125
     31 ns  0      0.5625
     31 ns  0        0.75
     41 ns  0      -0.375
     41 ns  0     -0.1875
     41 ns  0    -0.46875
     51 ns  0    -0.09375
     51 ns  0   -0.046875
     51 ns  0    0.046875
     61 ns  0    0.140625
     61 ns  0   0.0703125
     61 ns  0     0.09375
     71 ns  0   -0.046875
     71 ns  0  -0.0234375
     71 ns  0  -0.0585938
     81 ns  0  -0.0117188
     81 ns  0 -0.00585938
     81 ns  0  0.00585938
     91 ns  0   0.0175781
     91 ns  0  0.00878906
     91 ns  0   0.0117188
    101 ns  0 -0.00585938
    101 ns  0 -0.00292969
    101 ns  0 -0.00732422
    111 ns  0 -0.00146484
    111 ns  0-0.000732422
    111 ns  0 0.000732422
    121 ns  0  0.00219727
    121 ns  0  0.00109863
    121 ns  0  0.00146484
    131 ns  0-0.000732422
    131 ns  0-0.000366211
    131 ns  0-0.000915527
    141 ns  0-0.000183105
    141 ns  0-9.15527e-05
    141 ns  0 9.15527e-05
    151 ns  0 0.000274658
    151 ns  0 0.000137329
    151 ns  0 0.000183105
    161 ns  0-9.15527e-05
    161 ns  0-4.57764e-05
    161 ns  0-0.000114441
    171 ns  0-2.28882e-05
    171 ns  0-1.14441e-05
    171 ns  0 1.14441e-05
    181 ns  0 3.43323e-05
    181 ns  0 1.71661e-05
    181 ns  0 2.28882e-05
    191 ns  0-1.14441e-05
    191 ns  0-5.72205e-06
    191 ns  0-1.43051e-05


