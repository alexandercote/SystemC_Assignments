# 2 - Digital Filter as a Single Submodules

Consider the digital filter shown below, where z<sup>-1</sup> means a delay of 1 clock cycle. 

![image](https://user-images.githubusercontent.com/978364/57806557-37c1a680-7714-11e9-80dd-01ea2a4272fb.PNG)

Given the same digital filter from Assignment 1, the task is to create its behavioral description using a single SC_MODULE with two processes:
- SC_METHOD (sensitive to x and the outputs of z<sup>-1</sup> registers as needed, producing y and the inputs for z<sup>-1</sup> registers as needed) 
- SC_CTHREAD (updating the outputs of z<sup>-1</sup> registers at positive clock edges). 

This coding approach is similar to the way we describe Mealy-type FSMs (in our filter, y is directly affected by x).

The code submission must be self-contained.



      Time  X           Y
     11 ns  1            0
     11 ns  1         0.25
     21 ns  0         0.25
     21 ns  0        0.375
     31 ns  0         0.75
     41 ns  0     -0.46875
     51 ns  0     0.046875
     61 ns  0      0.09375
     71 ns  0   -0.0585938
     81 ns  0   0.00585938
     91 ns  0    0.0117188
    101 ns  0  -0.00732422
    111 ns  0  0.000732422
    121 ns  0   0.00146484
    131 ns  0 -0.000915527
    141 ns  0  9.15527e-05
    151 ns  0  0.000183105
    161 ns  0 -0.000114441
    171 ns  0  1.14441e-05
    181 ns  0  2.28882e-05
    191 ns  0 -1.43051e-05
    201 ns  0  1.43051e-06

