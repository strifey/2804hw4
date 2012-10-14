#ifndef processor_h
#define processor_h

#include <iostream>
#include <string>
#include "storage.h"
#include "instruction.h"

class Processor {
	private:
		StorageFile registers;
		StorageFile memory;
		Storage PC;
		Instruction curr_instr;
	public:
		Processor(int reg_size, int mem_size, int max_size):
			registers(reg_size, max_size),
			memory(mem_size, max_size),
			PC(mem_size, max_size) {}
		bool next_step();
		bool fetch();
		bool execute();
};
#endif
