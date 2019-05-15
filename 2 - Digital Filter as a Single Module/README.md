# 2 - Digital Filter as a Single Submodules

Consider the digital filter shown below, where z<sup>-1</sup> means a delay of 1 clock cycle. 

![image](https://user-images.githubusercontent.com/978364/57806557-37c1a680-7714-11e9-80dd-01ea2a4272fb.PNG)

Given the same digital filter from Assignment 1, the task is to create its behavioral description using a single SC_MODULE with two processes:
- SC_METHOD (sensitive to x and the outputs of z<sup>-1</sup> registers as needed, producing y and the inputs for z<sup>-1</sup> registers as needed) 
- SC_CTHREAD (updating the outputs of z<sup>-1</sup> registers at positive clock edges). 

This coding approach is similar to the way we describe Mealy-type FSMs (in our filter, y is directly affected by x).

The code submission must be self-contained.
