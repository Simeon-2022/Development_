#include <cstring>
#include <iostream>
#include <string.h>
#include <vector>


template<typename T>

T sum(const T& temp1, const T& temp2) {

	return temp1 + temp2;
}

template<typename T>
size_t diff(const T& temp1, const T& temp2) {

	return temp1 - temp2;
}

template<typename T>
typename T::value_type  sum(const T& c) {

	typename T::value_type result = typename T::value_type();
	for ( typename T::const_iterator it = c.begin(); it < c.end(); it++)
	{
		result = result + *it;
	}
	return result;
}

template<typename T,size_t Size>
class Array8 {

public:
	T& operator[](size_t idx) { return arr[idx];}
	const T& operator[](size_t idx) const { return arr[idx]; }
private:
	T arr[Size];

};

int main() {
	std::string str(0);
	//int i(5);
	int i = int();
	//const Array8<int, 8>var;
	//var[5];
	//var.operator[](3);

	//std::string result = sum(std::string("5"), std::string("6"));
	//std::size_t result1 = diff((const char*)("5"), (const char*)("6"));

	std::vector<int>vec(5,5);
	std::vector<std::string>vec1(5,"123");
	std::cout << sum(vec1);

	return 0;
}