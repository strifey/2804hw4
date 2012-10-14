#ifndef instruction_h
#define instruction_h

#include <iostream>
#include <string>
#include <vector>
#include "processor.h"

class Instruction {
	private:
		unsigned int _reg_a, _reg_b, _offset;
	public:
		Instruction(unsigned int reg_a, unsigned int reg_b, unsigned int offset):
			_reg_a(reg_a), _reg_b(reg_b), _offset(offset) {}
		const static Instruction parse_next_instr(unsigned int instruction);
		bool execute(Processor proc)=0;
};

#endif
