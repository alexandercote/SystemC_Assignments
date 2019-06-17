# 2 - Memory Module - New Command

Provided with a memory module with the functions to read a byte (RDBYT), write a byte (WTBYT), and write a block of 4 bytes (WTBLK), the goal is to write a function that reads a block of 4 bytes (RDBLK). Then, a testbench must be written to test all cases.

The output of the testbench is shown below:



TEST STRUCTURE: Tests 1-3 are RDBYT, WRBYT. Tests 4-6 are RDBLK, WRBLK.
TEST METHODOLOGY: Read from address, write to same address different value, read back address to validate.

TEST 1: READ 8-bits of data from address 3. Expected XXXXXXXX
Validating that RDBYT will read unintialized memory, and return garbage.
@ 41 ns: MEM MODULE : RDBYT, address = 3, data = XXXXXXXX
@ 61 ns: TST MODULE : RDBYT, address = 3, data = XXXXXXXX

TEST 2: Write 8-bits of data to address 3.
Validating WTBYT by writing to the memory just read from, knowing its previous state was garbage.
@ 81 ns: TST MODULE : WTBYT, address = 3, data = 00000100
@ 91 ns: MEM MODULE : WTBYT, address = 3, data = 00000100

TEST 3: READ 8-bits of data from address 3. Expected 00000100
Validating RDBYT by reading the address just written to. Should be different result than Test 1.
@141 ns: MEM MODULE : RDBYT, address = 3, data = 00000100
@161 ns: TST MODULE : RDBYT, address = 3, data = 00000100

TEST 4: Read 4 x 8bits of data from 4 consecutive memory address, starting at address 0.
Expected: XXXXXXXX , XXXXXXXX, XXXXXXXX, 00000100
@191 ns: MEM MODULE : RDBLK-0, address = 0, data = XXXXXXXX
@201 ns: MEM MODULE : RDBLK-1, address = 1, data = XXXXXXXX
@211 ns: MEM MODULE : RDBLK-2, address = 2, data = XXXXXXXX
@221 ns: MEM MODULE : RDBLK-3, address = 3, data = 00000100

TEST 5: Write 4 x 8bits of data into 4 consecutive memory address, starting from address 0.
@271 ns: MEM MODULE : WTBLK-0, address = 0, data = 11101110
@281 ns: MEM MODULE : WTBLK-1, address = 1, data = 11011101
@291 ns: MEM MODULE : WTBLK-2, address = 2, data = 11001100
@301 ns: MEM MODULE : WTBLK-3, address = 3, data = 10111011

TEST 6: Read 4 x 8bits of data from 4 consecutive memory address, starting at address 0.
@351 ns: MEM MODULE : RDBLK-0, address = 0, data = 11101110
@361 ns: MEM MODULE : RDBLK-1, address = 1, data = 11011101
@371 ns: MEM MODULE : RDBLK-2, address = 2, data = 11001100
@381 ns: MEM MODULE : RDBLK-3, address = 3, data = 10111011
