#ifndef register_h
#define register_h

#include <string>

class Register {
	private:
		char _reg_num;
		unsigned int _val;
		static const unsigned int MAX_VAL = 1000;
	public:
		Register(char reg_num, int val) :_reg_num(reg_num), _val(val) {}

		int val() {return _val;}
		void val(unsigned int n_val);

		std::string to_string();
};

#endif
