#include "storage.h"

std::string StorageFile::to_string(){
	std::stringstream out;
	out<<"Storage contents: "<<std::endl;
	for(unsigned int i = 0; i<registers.size(); i++)
		out<<"At "<<i<<": "<<registers[i].val()<<std::endl;
	return out.str();
}

Storage& Storage::operator=(const Storage& o){
	if(&o != this)
		_val = o.val();
	return *this;
}

Storage& Storage::operator+=(const unsigned int o){
	_val+=o;
	return *this;
}

Storage& Storage::operator+=(const Storage& o){
	_val+=o.val();
	return *this;
}

Storage& Storage::operator*=(const unsigned int o){
	_val*=o;
	return *this;
}

Storage& Storage::operator*=(const Storage& o){
	_val*=o.val();
	return *this;
}

Storage& Storage::operator++(){
	++_val;
	_val%=MAX_VAL;
	return *this;
}

Storage Storage::operator++(int){
	Storage tmp(*this);
	++(*this); 
	return tmp;
}
