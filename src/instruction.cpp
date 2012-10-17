#include "instruction.h"

using std::cout;
using std::endl;

Instruction* Instruction::decode(unsigned int instr){
	//cout<<"Decoding "<<instr<<endl;
	unsigned int instr_num = instr/100;
	switch(instr_num){
		case 1:
			return new HaltInstr(0,0,0);
		case 2:
			return new SetImmInstr{(instr/10)%10, 0, instr%10};
		case 3:
			return new AddImmInstr((instr/10)%10, 0, instr%10);
		case 4:
			return new MultImmInstr((instr/10)%10, 0, instr%10);
		case 5:
			return new SetRegInstr((instr/10)%10, instr%10, 0);
		case 6:
			return  new AddRegInstr((instr/10)%10, instr%10, 0);
		case 7:
			return new MultRegInstr((instr/10)%10, instr%10, 0);
		case 8:
			return new GetMemInstr((instr/10)%10, instr%10, 0);
		case 9:
			return new SetMemInstr((instr/10)%10, instr%10, 0);
		case 0:
			return new BranchInstr((instr/10)%10, instr%10, 0);
	}
	return nullptr;
}

bool SetImmInstr::execute(StorageFile& regs, StorageFile& mem, Storage& PC){
	//cout<<"SetImm "<<_reg_a<<" "<<_reg_b<<" "<<_offset<<endl;
	regs[_reg_a] = _offset;
	return false;
}

bool AddImmInstr::execute(StorageFile& regs, StorageFile& mem, Storage& PC){
	//cout<<"addimm "<<_reg_a<<" "<<_reg_b<<" "<<_offset<<endl;
	regs[_reg_a] += _offset;
	return false;
}

bool MultImmInstr::execute(StorageFile& regs, StorageFile& mem, Storage& PC){
	//cout<<"multimm "<<_reg_a<<" "<<_reg_b<<" "<<_offset<<endl;
	regs[_reg_a] *= _offset;
	return false;
}

bool SetRegInstr::execute(StorageFile& regs, StorageFile& mem, Storage& PC){
	//cout<<"setreg "<<_reg_a<<" "<<_reg_b<<" "<<_offset<<endl;
	regs[_reg_a] = regs[_reg_b];
	return false;
}

bool AddRegInstr::execute(StorageFile& regs, StorageFile& mem, Storage& PC){
	//cout<<"addreg "<<_reg_a<<" "<<_reg_b<<" "<<_offset<<endl;
	regs[_reg_a] += regs[_reg_b];
	return false;
}

bool MultRegInstr::execute(StorageFile& regs, StorageFile& mem, Storage& PC){
	//cout<<"Multreg "<<_reg_a<<" "<<_reg_b<<" "<<_offset<<endl;
	regs[_reg_a] *= regs[_reg_b];
	return false;
}

bool GetMemInstr::execute(StorageFile& regs, StorageFile& mem, Storage& PC){
	//cout<<"Getmem "<<_reg_a<<" "<<_reg_b<<" "<<_offset<<endl;
	regs[_reg_a] = mem[_reg_b];
	return false;
}

bool SetMemInstr::execute(StorageFile& regs, StorageFile& mem, Storage& PC){
	//cout<<"SetMem "<<_reg_a<<" "<<_reg_b<<" "<<_offset<<endl;
	mem[_reg_b] = regs[_reg_a];
	return false;
}

bool BranchInstr::execute(StorageFile& regs, StorageFile& mem, Storage& PC){
	//cout<<"Branch "<<_reg_a<<" "<<_reg_b<<" "<<_offset<<endl;
	if(regs[_reg_b].val() != 0)
		PC = regs[_reg_a];
	return false;
}
