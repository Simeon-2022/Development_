// StarCraft.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
#include<cctype>
#include<ostream>
#include<istream>
#include<bitset>
#include<array>
#include<string.h>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// extern int sss;
extern  int sss;

std::ostream& operator<<(std::ostream& os, const vector<int>& vec) {

	vector<int>::const_iterator it = vec.begin();

	for (; it != vec.end(); it++)
	{
		os << *it << " ";
	}

	return os;
}

std::ostream& operator<<(std::ostream& os, const vector<string>& vec) {

	vector<string>::const_iterator it = vec.begin();

	for (; it != vec.end(); it++)
	{
		os << *it << " ";
	}

	return os;
}

std::istream& operator>>(std::istream& is, vector<int>& vec) {

	int num;
	while (is >> num)
	{
		vec.push_back(num);
	}
	return is;
}
void PrintCharArray(const char* arr, size_t& size) {

	const char* arrPtrBegin = arr;
	const char* arrPtrEnd = arr + size;
	cout << "{";
	for (; arrPtrBegin != arrPtrEnd; arrPtrBegin++)
	{
		cout << *arrPtrBegin << " ";
	}
	cout << "}" << endl;
}

int arr[2];
int main()
{
	//cout << sizeof(string::size_type);
	/*vector<int> vec;
	int a;
	while (cin >> a)
	{
		vec.push_back(a);
	}

	int sum = 0;
	vector<int>::const_iterator it = vec.begin();
	int last = *it;
	it++;
	for (; it != vec.end(); it++)
	{
		if (last % 2 != 0 || *it % 2 != 0)
		{
			cout << "Odd element found!" << endl;
			cout << last << endl;
			break;
		}

		sum += (last + *it);
		cout << sum << endl;
		sum = 0;
		last = *it;
	}

	sum = 0;
	it = vec.begin();
	vector<int>::const_iterator itend = vec.end();
	for (; it != (vec.begin() + (vec.size() / 2)); it++)
	{
		sum += (*it + *(--itend));

		cout << sum << endl;
		sum = 0;
	}*/

	/*vector<string> vec1;
	string b;

	while (cin >> b)
	{
		for (string::iterator i = b.begin(); i != b.end(); i++)
		{
			*i = toupper(*i);
		}

		vec1.push_back(b);
	}

	int i = 0;
	for (vector<string>::const_iterator it = vec1.begin(); it != vec1.end(); i++, it++)
	{
		if ((it - vec1.begin()) % 8 == 0)
		{
			cout << endl;
		}
		cout << *it << " ";
	}*/

	vector<int> t(10, 2);
	vector<int>::iterator i = t.begin();
	vector<int>::iterator ii = t.end();
	vector<int>::iterator iii = t.begin() + 2;
	vector<int>::difference_type type = ii - i;

	cout << type << endl;
	for (; i != t.end(); i++)
	{
		*i = *i * 2;
	}


	//vector<int> vecc(10, 42);
	//vector<int> vecc;
	//cin >> vecc;
	cout << t;
	string strval;
	std::bitset<32> bitvec(strval);
	//bitvec.set(1);
	cout << endl;
	cout << bitvec << endl;

	int a = 1;
	int b = 2;
	int temp = 0;
	bitvec.reset();
	while (a <= 21)
	{
		bitvec.set(a);
		cout << bitvec << endl;
		temp = b;
		b = a + b;
		a = temp;

	}

	int arr[10];
	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		arr[i] = static_cast<int>(i);
	}
	cout << arr[0] << endl;
	string arrr = { 'a','a','d' };

	vector<int> vec1(10, 1);
	vector<int> vec2(11, 1);
	cout << (vec1 == vec2) << endl;
	int ch = 48;
	char chh = '0';
	bool check = (ch == chh);
	cout << check << endl;
	string r = "adi ve!!";
	string d = "really??";
	string& p = d;
	string* pp = &p;
	string* pc = &r;
	pp = pc;
	*pp = "opa";
	//p = "ne moi da bude";
	//p = d;

	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int* ip = ia, *ip2 = ip + sizeof(ia) / sizeof(int); ip != ip2; ip++)
	{
		*ip = 0;
	};

	int input;
	vector<int> vec;
	//while (cin >> input)
	{
		vec.push_back(input);
	}
	//int* arr1 = new int[vec.size()]();
	int* arr1 = new int[4 * sizeof(int)]();
	for (size_t i = 0; i < 4 * sizeof(int); i++)
	{
		cout << arr1[i] << " ";
	}

	int* arr_idx = arr1;
	for (vector<int>::iterator it_begin = vec.begin(), it_end = vec.end(); it_begin != it_end; it_begin++)
	{
		*arr_idx = *it_begin;
		cout << *arr_idx << " ";
		arr_idx++;
	}
	delete[] arr1;
	arr1 = NULL;
	cout << arr1;
	const char arrOne[] = "String One";
	const char arrTwo[] = "String Two";
	rsize_t size = strlen(arrOne) + strlen(arrTwo) + strlen(" + ") + 1;
	char* charThree = new char[size];
	strcpy_s(charThree, size, arrOne);
	strcat_s(charThree, size, " + ");
	strcat_s(charThree, size, arrTwo);

	cout << "\n" << charThree << endl;
	string strtt = arrOne;
	strtt += " + ";
	strtt += arrTwo;
	cout << strtt << endl;

	//int charInput;
	//cin >> sizeArr;
	//int* charArr = new int[sizeArr];

	int charArr[] = { 1,2,3,4,5 };
	size_t sizeArr = sizeof(charArr) / sizeof(int);
	vector<int> intVec(charArr, charArr + sizeArr);



	//delete[] charArr;

	string newInput;
	vector<string> newVector = { "T1","T2","T3" };
	//while (cin >> newInput)
	//{
	//	newVector.push_back(newInput);
	//}

	char** newArrPtr = new char* [newVector.size()];
	vector<string>::const_iterator c_it = newVector.begin();
	int vecIdx = 0;
	for (char** i = newArrPtr; i != newArrPtr + newVector.size(); i++, vecIdx++, c_it++)
	{
		string::size_type size = newVector[vecIdx].size();

		*i = new char[size + 1];

		int j = 0;
		

		for (char* y = *i; y != (*i + size); y++)
		{
			*y = c_it[0][j++]; 
		}
		(*i)[size] = '\0';
	}

	string::size_type vec_size = newVector.size();
	for (char** i = newArrPtr; i != newArrPtr + newVector.size(); i++)
	{
		cout << *i << " ";

	}

	for (size_t i = 0; i < newVector.size(); i++)
	{
		delete[] newArrPtr[i];
		
	}
	delete[] newArrPtr;
	
	const size_t rowSize = 3;
	const size_t colSize = 4;

	int iaa[rowSize][colSize] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};

	for (int (*p)[colSize] = iaa; p != iaa + 3; ++p) {
		for (int* q = *p; q != *p + 4; ++q) {
			cout << *q << " ";
		}
		cout << endl;
	}
	// pi_ptr is const and points to a const object
	//const double* const pi_ptr;
	//ptrdiff_t diff =  ip2 - ip;
	//cout << diff; 
	unsigned long int ts = 1;
	//cout << ts << endl;
	unsigned long ul1 = 3, ul2 = 7;
	std::bitset<30> bitttsss(ul1);
	std::bitset<30> bitttsss1(ul2);
	std::bitset<30> bitttsss2(ul1 | ul2);
	bitttsss[10] = 0;
	cout << bitttsss << "\n";
	cout << bitttsss1 << "\n";
	cout << bitttsss1 << " : " << (ul1 | ul2) << "\n";
	


	vector<string*> vec_str_ptr;
	string inputstr;
	while (cin >> inputstr)
	{
		string* newstrptr = new string(inputstr);
		vec_str_ptr.push_back(newstrptr);
	}

	for (size_t i = 0; i < vec_str_ptr.size(); i++)
	{
	cout << "\n" << *vec_str_ptr[i] << ": " << (vec_str_ptr[i])->size();

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
