#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;
#include "randNumGen.h"

string generate(int count){
	srand(time(NULL));
	ofstream write;
	std::string fileName = std::to_string(count) + ".txt";
	write.open(fileName);
	for(int i=0;i<count;i++){
		write << rand() % 1000000 << endl;
	}
	return fileName;
}

string generate2(int count){
	ofstream write;
	std::string fileName = std::to_string(count) + ".txt";
	write.open(fileName);
	for(int i=0;i<count;i++){
		write << (i+1) << endl;
	}
	return fileName;
}
