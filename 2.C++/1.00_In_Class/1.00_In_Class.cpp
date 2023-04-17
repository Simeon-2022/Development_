#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class Foo {

public:

	Foo(int m_int){};

private:

	//int m_int;
	//Foo() {};

};


int main()
{
	//std::vector<int>intVector(10, 5);

	//std::list<int>intList(intVector.begin(), intVector.begin() + intVector.size() / 2);
	//std::list<int>intList(intVector.begin(), intVector.begin() + (intVector.end() - intVector.begin()) / 2);

	//std::list<Foo>fo(1,4);
	//std::list<Foo>fo(3);
	//fo.push_back(3);
	
	std::list<std::vector<std::string>> words;

	std::vector<std::string> vec1 = { "abc"};
	std::vector<std::string> vec2 = { "def"};
	std::vector<std::string> vec3 = { "ghi"};
	
	words.push_back(vec1);
	words.push_back(vec2);
	words.push_back(vec3);

	for (std::list<std::vector<std::string>> ::iterator it = words.rbegin()  ; it != words.rend(); it--)
	{
		for (vector<std::string > ::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			std::cout << *it2 << std::endl;
		}
	
	
	}
	
	
	//Foo f(1);


}

