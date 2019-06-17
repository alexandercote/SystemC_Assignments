# A2Q2 - Parameterized FIFO Hierarchical Channel

Create a SystemC implementation of a FIFO a.k.a. queue, with a size of 8, with a producer that generates values at twice a rate they are read at.


The output of the testbench is shown below:

@  1 ns : Read     , Wrote  0  
@  6 ns : Read     , Wrote  1  
@ 11 ns : Read   0 , Wrote   
@ 11 ns : Read     , Wrote  2  
@ 16 ns : Read     , Wrote  3  
@ 21 ns : Read   1 , Wrote   
@ 21 ns : Read     , Wrote  4  
@ 26 ns : Read     , Wrote  5  
@ 31 ns : Read   2 , Wrote   
@ 31 ns : Read     , Wrote  6  
@ 36 ns : Read     , Wrote  7  
@ 41 ns : Read   3 , Wrote   
@ 41 ns : Read     , Wrote  8  
@ 46 ns : Read     , Wrote  9  
@ 51 ns : Read   4 , Wrote   
@ 51 ns : Read     , Wrote  0  
@ 56 ns : Read     , Wrote  1  
@ 61 ns : Read   5 , Wrote   
@ 61 ns : Read     , Wrote  2  
@ 66 ns : Read     , Wrote  3  
@ 71 ns : Read   6 , Wrote   
@ 71 ns : Read     , Wrote  4  
@ 81 ns : Read   7 , Wrote   
@ 81 ns : Read     , Wrote  5  
@ 91 ns : Read   8 , Wrote   
@ 91 ns : Read     , Wrote  6  
@101 ns : Read   9 , Wrote   
@101 ns : Read     , Wrote  7  
@111 ns : Read   0 , Wrote   
@111 ns : Read     , Wrote  8  
@121 ns : Read   1 , Wrote   
@121 ns : Read     , Wrote  9  
@131 ns : Read   2 , Wrote   
@131 ns : Read     , Wrote  0  
@141 ns : Read   3 , Wrote   
@141 ns : Read     , Wrote  1  
@151 ns : Read   4 , Wrote   
@151 ns : Read     , Wrote  2  
@161 ns : Read   5 , Wrote   
@161 ns : Read     , Wrote  3  
@171 ns : Read   6 , Wrote   
@171 ns : Read     , Wrote  4  
@181 ns : Read   7 , Wrote   
@181 ns : Read     , Wrote  5  
@191 ns : Read   8 , Wrote   
@191 ns : Read     , Wrote  6  
@201 ns : Read   9 , Wrote   
@201 ns : Read     , Wrote  7  




