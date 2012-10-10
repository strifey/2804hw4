#include "register.h"

void Register::val(unsigned int n_val){
	_val = n_val % MAX_VAL;
}

std::string Register::to_string(){
	std::string out = "R%c: %i" , _reg_num, _val;
	return out;
}
