#include <iostream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

struct InvalidNumber {

	//InvalidNumber() {};
	string errorStr;
	
};

template<typename T>
typename T::value_type ff(const T& c) {

	typename T::value_type result = typename T::value_type();

	for (typename T::const_iterator it = c.begin(); it < c.end(); it++)
	{
		if (*it < 0)
		{
			//throw string("Negative number!");

			InvalidNumber f;
			f.errorStr = "Negative number!";
			throw f;
		}

		result += *it;
	}

	return result/ static_cast<typename T::value_type>(c.size());

}


int main() {

	//try
	//{

	//	vector<int> vect(5, 5);
	//	vect.push_back(-1);
	//	cout << ff(vect);
	//}
	//catch (const std::string& c)
	//{
	//	cout << c;
	//}

	try
	{

		vector<int> vect(5, 5);
		vect.push_back(-1);
		cout << ff(vect);
	}
	catch (const InvalidNumber& exc)
	{
		cout << exc.errorStr;
	}


	//vector<int> vect(5, 5);

	//cout << ff(vect);

	return 0;
}