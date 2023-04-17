#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void printByRef(const string &str = "No argument passed!") {

	cerr << str << endl;

}

int main() {

	string str = "Some error message!";

	printByRef();
	printByRef(str);


	return 0;
}