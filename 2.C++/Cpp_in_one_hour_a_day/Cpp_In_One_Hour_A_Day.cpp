#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <list>
#include <set>
#include <limits>
#include <cmath>
#include <algorithm>
#include "Cpp_In_One_Hour_A_Day.h"
#include <map>

Employee::Employee() {};
Employee::~Employee() {}

Employee::Employee(int age, int yearsOfService, double salary) {
	this->itsAge = age;
	this->itsYearsOfService = yearsOfService;
	this->itsSalary = salary;
}

inline int Employee::get_itsAge() const { return this->itsAge; }
inline int Employee::get_itsYearsOfService() const { return this->itsYearsOfService; }
inline double Employee::get_itsSalary() const { return this->itsSalary; }

inline void Employee::set_itsAge(int age) { this->itsAge = age; }
inline void Employee::set_itsyearsOfService(int yearsOfService) { this->itsYearsOfService = yearsOfService; }
inline void Employee::set_itsSalary(double salary) { this->itsSalary = salary; }

inline double Employee::get_EarningsRounded() { return round(this->itsSalary); }

bool predicate_reverse(const string& item1, const string& item2) {

	return (item1 > item2);
}

int ShowMenu() {

	cout << " ***What would you like to do next ? ***" << endl << endl;
	cout << "Enter 0 to feed a name and phone number" << endl;
	cout << "Enter 1 to Display all entries" << endl;
	cout << "Enter 2 to find an entry" << endl;
	cout << "Enter 3 to erase an entry" << endl;
	cout << "Enter 4 to quit this application" << endl << endl;
	cout << " > ";
	int nOptionSelected = 0;
	// Accept user input
	cin >> nOptionSelected;
	cout << endl;
	return nOptionSelected;
}
ContactItem GetContactInfo() {

	cout << " ***Feed contact information ***" << endl;
	string strName;
	string strPhoneNumber;
	cout << "Please enter the person’s name and phone number, split by interval" << endl;
	cout << " > ";
	cin >> strName >> strPhoneNumber;
	return ContactItem(strName, strPhoneNumber);

}
void DisplayContactset(const set <ContactItem>& setContacts) {

	cout << "***Displaying contact information ***" << endl;

	set <ContactItem>::const_iterator contact;
	for (contact = setContacts.begin(); contact != setContacts.end(); contact++)
	{
		cout << contact->strContactsName << " : " << contact->strPhoneNumber << endl;
	}
}

void FindContact(const set <ContactItem>& setContacts) {
	cout << "***Looking for contact information ***" << endl;
	cout << "Type in phone number >> ";
	string number;
	cin >> number;

	set <ContactItem>::iterator it = setContacts.find(ContactItem("",number));
	if (it != setContacts.end())
	{
		cout << "\nOwner of of phone number: " << it->strPhoneNumber << " is: " << it->strContactsName << endl << endl;
	}
	else
	{
		cout << "\nNo name, no face, no number..\n\n";
	}
}

void EraseContact(set <ContactItem>& setContacts) {};

//	Extend the telephone directory example in this lesson to find a person’s name
//	given a phone number, without changing structure ContactItem. (Hint: Define the
//	set with a binary predicate that sorts items in accordance with the number, thus
//	overriding the default sort based on the < operator.)
int main()
{

	//set <ContactItem> setContacts;
	//int nUserSelection = InsertContactsetEntry;
	//while ((nUserSelection = ShowMenu()) != (int)QuitApplication)
	//{
	//	switch (nUserSelection)
	//	{
	//	case InsertContactsetEntry:
	//		setContacts.insert(GetContactInfo());
	//		cout << "Contacts set updated!" << endl << endl;
	//		break;
	//	case DisplayEntries:
	//		DisplayContactset(setContacts);
	//		break;
	//	case FindNumber:
	//		FindContact(setContacts);
	//		break;
	//	case EraseEntry:
	//		EraseContact(setContacts);
	//		DisplayContactset(setContacts);
	//		break;
	//	default:
	//		cout << "Invalid input ‘" << nUserSelection;
	//		cout << ".’ Please choose an option between 0 and 4";
	//		break;
	//	}
	//}
	//cout << "Quitting!Bye!" << endl;


	//Empyoyee employeeOne;
	//employeeOne.set_itsAge(35);
	//employeeOne.set_itsyearsOfService(3);
	//employeeOne.set_itsSalary(2333.33);

	//Employee employeeTwo;
	//employeeTwo.set_itsAge(36);
	//employeeTwo.set_itsyearsOfService(4);
	//employeeTwo.set_itsSalary(1033.33);

	//Employee employeeThree(27, 4, 3333.55);

	//std::cout << "EmployeeOne, age : \t\t" << employeeOne.get_itsAge() << std::endl;
	//std::cout << "EmployeeOne, years of service : " << employeeOne.get_itsYearsOfService() << std::endl;
	//std::cout << "EmployeeOne, salary : \t\t" << employeeOne.get_itsSalary() << std::endl;
	//
	//std::cout << "EmployeeTwo, age : \t\t" << employeeTwo.get_itsAge() << std::endl;
	//std::cout << "EmployeeTwo, years of service : " << employeeTwo.get_itsYearsOfService() << std::endl;
	//std::cout << "EmployeeTwo, salary : \t\t" << employeeTwo.get_itsSalary() << std::endl;

	//std::cout << "EmployeeThree, salary : \t" << employeeThree.get_EarningsRounded() << std::endl;

	//Mammal* theArray[NumAnimalTypes];
	//Mammal* ptr;
	//int choice, i;
	//for (i = 0; i < NumAnimalTypes; i++)
	//{
	//	cout << "(1)dog(2)cat(3)Mammal: ";
	//	cin >> choice;
	//	switch (choice)
	//	{
	//	case DOG: ptr = new Dog;
	//		break;
	//	case CAT: ptr = new Cat;
	//		break;
	//	default: ptr = new Mammal;
	//		break;
	//	}
	//	theArray[i] = ptr;
	//}
	//Mammal* OtherArray[NumAnimalTypes];
	//for (i = 0; i < NumAnimalTypes; i++)
	//{
	//	theArray[i]->Speak();
	//	OtherArray[i] = theArray[i]->Clone();
	//}
	//for (i = 0; i < NumAnimalTypes; i++)
	//	OtherArray[i]->Speak();

	// Instantiate and initialize a date object to 25 May 2008
	CDate mDate(25, 6, 2008);
	std::cout << "The date object is initialized to : ";
	// Display initial date
	mDate.DisplayDate();
	std::cout << std::endl;
	// Applying the prefix increment operator
	++mDate;
	std::cout << "Date after prefix - increment is : ";
	// Display date after incrementing
	mDate.DisplayDate();
	std::cout << std::endl;

	CHoldsPair <> obj(2, 22);
	cout << "Obj.value1: " << obj.getValue1() << endl;
	cout << "Obj.value2: " << obj.getValue2() << endl;

	CHoldsPair <float, string> objS(2.2f, "Tralala");
	cout << "Obj.value1: " << objS.getValue1() << endl;
	cout << "Obj.value2: " << objS.getValue2() << endl;

	cout << ADD(5 + 5, 6 + 4) << endl;
	cout << Add <int>(5 + 5, 6 + 4) << endl;
	int x = 55;
	int y = 10;
	Swap <int>(x, y);
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	string str("ATOYOTB");
	string strOriginal(str);
	reverse(str.begin(), str.end());
	cout << str.c_str() << endl;;
	if (str == strOriginal)
	{
		cout << "Palindrom\n";
	}
	else
	{

		cout << "Not a Palindrom\n";
	}

	multimap <int, string> MAP_INT_STRING;
	//MAP_INT_STRING.insert(1, "one");
	MAP_INT_STRING.insert(make_pair(2, "two"));
	MAP_INT_STRING.insert(pair<int,string>(2, "twooo"));
	//MAP_INT_STRING[2] = "thousand";
	multimap <int, string>::iterator itii = MAP_INT_STRING.find(2);
	MAP_INT_STRING.erase(2);
	MAP_INT_STRING.size();
	//MAP_INT_STRING.erase(MAP_INT_STRING.lower_bound(1), MAP_INT_STRING.upper_bound(3));

	for (itii = MAP_INT_STRING.begin()
		; itii != MAP_INT_STRING.end()
		; ++itii)
	{
		cout << "Key: " << itii->first;
		cout << ", Value: " << itii->second.c_str() << endl;
	}

	vector <int> vecMultiplicand = { 1,2,43,4 };

	bitset<8> bits(9);
	bitset<8> bits2(bits);
	bits = bits & bits2;
	cout << bits[7] << endl;
	cout << bits[0] << endl;
	cout << bits << endl;
	bits.set(2, 1);
	cout << bits << endl;
	bits.flip();
	cout << bits << endl;
	bits.set();
	cout << bits << endl;
	bits.set(1,0);
	cout << (bits) << endl;
	cout << bits.size() - bits.count() << endl;
	cout << bits.to_ullong() << endl;

	cout.width(3);
	cout << "A\n";
	cout << "A\n";
	return 0;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting 1Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
