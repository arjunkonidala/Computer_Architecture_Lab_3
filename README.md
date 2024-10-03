# Usage details of RISC_V_Simulator

The directory should contain three files:

1. **simulator.cpp**: This file contains the cpp program to be executed.
2. **input.txt**: This file should contain assembly instructions in RISC-V to be given as input.
3. **Makefile**: Which compiles and links the code to produce the executable file riscv_asm in same directory.

## Instructions for Proper Execution

- Every instruction should consist of proper spacing as well as label should be present only at the start of line before instruction.
- In input file every line should consist of single instuction alone.

## Compilation and Execution

- Since we are creating the makefile in same directory (all:calling the compilation command),
- Command "make all" will create executable file(riscv_asm) and object file(assemblytomachine.o).
- Make clean will delete the above mentioned executable and object file.

In this way our assembler will work giving the hexadecimal form of binary instructions.
