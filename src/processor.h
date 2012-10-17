#ifndef processor_h
#define processor_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "storage.h"
#include "instruction.h"

class Processor {
	private:
		StorageFile registers;
		StorageFile memory;
		Storage PC;
		Instruction *curr_instr;
		bool halted;
		unsigned int instr_run;
	public:
		Processor(int reg_size, int mem_size, int max_size):
			registers(reg_size, max_size),
			memory(mem_size, max_size),
			PC(mem_size, max_size), 
			halted(false), instr_run(0){}
		void next_step();
		void fetch();
		int run();
		void dump(){std::cout<<registers.to_string()<<std::endl;}
		void load(std::ifstream& fr);
};
#endif
