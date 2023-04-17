#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void printString(string &str) {
	ofstream myfile;
	myfile.open("D:\\Documents\\GitHub\\simeon-aleksandrov-C03\\2.C++\\C++\\HW_01.txt");
	myfile << str << endl;
	myfile.close();
}

void printString(const char* str[]) {
	ofstream myfile;
	myfile.open("D:\\Documents\\GitHub\\simeon-aleksandrov-C03\\2.C++\\C++\\HW_01_v2.txt");
	myfile << *str << endl;
	myfile.close();
}


int main() {

	string str("Test C++ string.");

	const char* c_string[] = { "Test C string." }; 

	printString(str);
	printString(c_string);


	return 0;
}