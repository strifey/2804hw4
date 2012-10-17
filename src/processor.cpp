#include "processor.h"

using std::string;
using std::ifstream;
using std::stringstream;
using std::cout;
using std::endl;

void Processor::fetch(){
	//if(curr_instr != nullptr){
		//cout<<"deleting instr"<<endl;
		//delete curr_instr;
	//}
	curr_instr = Instruction::decode(memory[PC.val()].val());
	PC++;
	instr_run++;
}

void Processor::next_step(){
	fetch();
	halted = curr_instr->execute(registers, memory, PC);
}

int Processor::run(){
	while(!halted){
		next_step();
		//dump();
	}
	return instr_run;
}

void Processor::load(ifstream& fr){
	int instr, cnt = 0;
	string str_instr = "";
	getline(fr, str_instr);
	while(str_instr.length() >0 && cnt< memory.size()){
		stringstream(str_instr)>>instr;
		memory[cnt]= instr;
		//cout<<"str: "<<str_instr<<"  val: "<<instr<<endl;
		getline(fr, str_instr);
		cnt++;
	}
}
