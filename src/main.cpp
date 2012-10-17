#include <fstream>
#include <string>
#include <sstream>
#include "processor.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;

int main(int argc, char*argv[]){
	if(argc<2){
		cout<<"Need to give filename as argument"<<endl;
		exit(1);
	}
	string filename{argv[1]};
	ifstream fr{filename};
	int num_programs = 0;
	string line = "";
	getline(fr, line);
	stringstream(line)>>num_programs;
	//cout<<"num p: "<<num_programs<<endl;
	getline(fr, line);
	for(int i = 0; i<num_programs; i++){
		Processor proc(10,1000,1000);
		proc.load(fr);
		cout<<proc.run()<<endl;
		//Uncomment out line below to see register contents of processor before running the next one.
		//proc.dump()
	}
	return 0;
}
