all:assemblytomachine.o
	@g++  assemblytomachine.o -o riscv_asm


assemblytomachine.o:assemblytomachine.cpp
	@g++ -c assemblytomachine.cpp 
	
clean:
	@rm riscv_asm assemblytomachine.o 

