#include <cstring>
#include <iostream>
#include <string.h>

void printString(const std::string& test) {

	for (int i = 0; i < test.length(); i++)
	{
		std::cout << test[i] << std::endl;
	}

}

void printString1(const std::string& test) {

	for (std::string::const_reverse_iterator it = test.rbegin(); it != test.rend(); it++)
	{
		std::cout << *it << " ";
	}

}

std::string hideSubstr(const std::string& str, const std::string& subStr) {

	std::string result(str);

	std::string::size_type point = str.find(subStr);
	while ((point = str.find(subStr)) != std::string::npos)
	{
		std::string::size_type indx = str.find(subStr);
		


	}

	return result;
}

int main() {

	std::string str("Code AcademY");
	//printString(str);
	//printString1(str);
	char ch = tolower(str[str.size() - 1]);
	std::cout << static_cast<char> (tolower(str[str.size() - 1]));



	return 0;
}