#ifndef storage_h
#define storage_h

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

class Storage{
	private:
		unsigned int _val;
		const unsigned int MAX_VAL;
	public:
		Storage(): _val(0), MAX_VAL(1000) {}
		Storage(unsigned int n_val, unsigned int max_val)
			:_val(n_val%max_val), MAX_VAL(max_val){}
		unsigned int val() const {return _val;}

		Storage& operator=(int n_val){this->_val = n_val%MAX_VAL; return *this;}
		Storage& operator=(const Storage& o);
		bool operator==(const Storage& o){return o.val() == _val;}
		bool operator==(const unsigned int o){return _val == o;}
		Storage& operator+=(const unsigned int o);
		Storage& operator+=(const Storage& o);
		Storage& operator*=(const unsigned int o);
		Storage& operator*=(const Storage& o);
		Storage& operator++();
		Storage operator++(int);
};

class StorageFile {
	private:
		std::vector<Storage> registers;
		const unsigned int MAX_VAL;
	public:
		StorageFile(const unsigned int num_regs, unsigned int max_allowed_val)
			:registers(num_regs, Storage(0, max_allowed_val)),
			MAX_VAL(max_allowed_val)
			{}
		
		unsigned int at(unsigned int index) {return registers.at(index).val();}
		int size() {return registers.size();}

		std::string to_string();
		unsigned int operator[](int index){return registers[index].val();}
};

#endif
