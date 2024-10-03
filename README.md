# Usage details of assembler

The directory should contain 3 files:

1)**assemblytomachine.cpp**:File which contains cpp program to be executed.
2)**input.s**: this file should be present with the assembly instructions ,that are to be given as input.
3)**Makefile**: Which compiles and links the code to produce the executable file riscv_asm in same directory.

## Instructions for Proper Execution

-Every instruction should consist of proper spacing as well as label should be present only at the start of line before instruction.
-In input file every line should consist of single instuction alone.

## Compilation and Execution

-Since we are creating the makefile in same directory (all:calling the compilation command),
    -Command "make all" will create executable file(riscv_asm) and object file(assemblytomachine.o).
-Make clean will delete the above mentioned executable and object file.

In this way our assembler will work giving the hexadecimal form of binary instructions.
