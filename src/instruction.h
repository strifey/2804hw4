#ifndef instruction_h
#define instruction_h

#include <iostream>
#include <string>
#include <vector>
#include "storage.h"

class Instruction {
	protected:
		unsigned int _reg_a, _reg_b, _offset;
	public:
		Instruction(unsigned int reg_a, unsigned int reg_b, unsigned int offset):
			_reg_a(reg_a), _reg_b(reg_b), _offset(offset) {}
		virtual bool execute(StorageFile& regs, StorageFile& mem, Storage& PC)=0;
		static Instruction* decode(unsigned int instr);
		virtual ~Instruction(){};
};

class HaltInstr : public Instruction{
	public:
		HaltInstr(unsigned int reg_a, unsigned int reg_b, unsigned int offset)
			:Instruction(reg_a, reg_b, offset) {}
		bool execute(StorageFile& regs, StorageFile& mem, Storage& PC){return true;}
};

class SetImmInstr : public Instruction{
	public:
		SetImmInstr(unsigned int reg_a, unsigned int reg_b, unsigned int offset)
			:Instruction(reg_a, reg_b, offset) {}
		bool execute(StorageFile& regs, StorageFile& mem, Storage& PC);
};

class AddImmInstr : public Instruction{
	public:
		AddImmInstr(unsigned int reg_a, unsigned int reg_b, unsigned int offset)
			:Instruction(reg_a, reg_b, offset) {}
		bool execute(StorageFile& regs, StorageFile& mem, Storage& PC);
};

class MultImmInstr : public Instruction{
	public:
		MultImmInstr(unsigned int reg_a, unsigned int reg_b, unsigned int offset)
			:Instruction(reg_a, reg_b, offset) {}
		bool execute(StorageFile& regs, StorageFile& mem, Storage& PC);
};

class SetRegInstr : public Instruction{
	public:
		SetRegInstr(unsigned int reg_a, unsigned int reg_b, unsigned int offset)
			:Instruction(reg_a, reg_b, offset) {}
		bool execute(StorageFile& regs, StorageFile& mem, Storage& PC);
};

class AddRegInstr : public Instruction{
	public:
		AddRegInstr(unsigned int reg_a, unsigned int reg_b, unsigned int offset)
			:Instruction(reg_a, reg_b, offset) {}
		bool execute(StorageFile& regs, StorageFile& mem, Storage& PC);
};

class MultRegInstr : public Instruction{
	public:
		MultRegInstr(unsigned int reg_a, unsigned int reg_b, unsigned int offset)
			:Instruction(reg_a, reg_b, offset) {}
		bool execute(StorageFile& regs, StorageFile& mem, Storage& PC);
};

class GetMemInstr : public Instruction{
	public:
		GetMemInstr(unsigned int reg_a, unsigned int reg_b, unsigned int offset)
			:Instruction(reg_a, reg_b, offset) {}
		bool execute(StorageFile& regs, StorageFile& mem, Storage& PC);
};

class SetMemInstr : public Instruction{
	public:
		SetMemInstr(unsigned int reg_a, unsigned int reg_b, unsigned int offset)
			:Instruction(reg_a, reg_b, offset) {}
		bool execute(StorageFile& regs, StorageFile& mem, Storage& PC);
};

class BranchInstr : public Instruction{
	public:
		BranchInstr(unsigned int reg_a, unsigned int reg_b, unsigned int offset)
			:Instruction(reg_a, reg_b, offset) {}
		bool execute(StorageFile& regs, StorageFile& mem, Storage& PC);
};
#endif
