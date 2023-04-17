#pragma once
#ifndef CPP_IN_ONE_HOUR_A_DAY_H
#define CPP_IN_ONE_HOUR_A_DAY_H

#define ADD(x,y)((x) * (y))

class Employee {

public:
	Employee();
	Employee(int age, int yearsOfService, double salary);
	~Employee();

	int get_itsAge() const;
	int get_itsYearsOfService() const;
	double get_itsSalary() const;

	void set_itsAge(int age);
	void set_itsyearsOfService(int yearsOfService);
	void set_itsSalary(double salary);

	double get_EarningsRounded();

private:
	unsigned int itsAge;
	unsigned int itsYearsOfService;
	double itsSalary;
};

//=======================================================================================================================================

using namespace std;

class Mammal
{
public:
	Mammal() :itsAge(1) { cout << "Mammal constructor...\n"; }
	virtual ~Mammal() { cout << "Mammal destructor...\n"; }
	Mammal(const Mammal& rhs);
	virtual void Speak() const { cout << "Mammal speak!\n"; }
	virtual Mammal* Clone() { return new Mammal(*this); }
	int GetAge()const { return itsAge; }

protected:
	int itsAge;
};
Mammal::Mammal(const Mammal& rhs) :itsAge(rhs.GetAge())
{
	cout << "Mammal Copy Constructor...\n";
}
class Dog : public Mammal
{
public:
	Dog() { cout << "Dog constructor...\n"; }
	virtual ~Dog() { cout << "Dog destructor...\n"; }
	Dog(const Dog& rhs);
	void Speak()const { cout << "Woof!\n"; }
	virtual Mammal* Clone() { return new Dog(*this); }
};
Dog::Dog(const Dog& rhs) :
	Mammal(rhs)
{
	cout << "Dog copy constructor...\n";
}
class Cat : public Mammal
{
public:
	Cat() { cout << "Cat constructor...\n"; }
	~Cat() { cout << "Cat destructor...\n"; }
	Cat(const Cat&);
	void Speak()const { cout << "Meow!\n"; }
	virtual Mammal* Clone() { return new Cat(*this); }
};
Cat::Cat(const Cat& rhs) :
	Mammal(rhs)
{
	cout << "Cat copy constructor...\n";
}
enum ANIMALS { MAMMAL, DOG, CAT };
const int NumAnimalTypes = 3;

class Shape {

public:

protected:
};
class Rectangle : public Shape {

public:
	Rectangle() {};
	Rectangle(int length) : m_length(length), m_width(0) {};
	Rectangle(int length, int width) : m_length(length), m_width(width) {};

	Rectangle(const Rectangle& obj) : m_width(obj.getWidth()), m_length(obj.getLength()) {};

	virtual Rectangle* clone() { return new Rectangle(*this); }

	unsigned int getWidth() const { return this->m_width; }
	virtual unsigned int getLength() const { return this->m_length; }

protected:
	unsigned int m_width;
	unsigned int m_length;
};

class Square : public Rectangle {

public:
	Square() {};
	Square(int length);
	Square(const Square& objSq) : m_length(objSq.getLength()) {};

	virtual Rectangle* clone() { return new Square(*this); }

	unsigned int getLength() const { return this->m_length; }

private:
	unsigned int m_length;
};
Square::Square(int length) :Rectangle(length) {};

typedef enum TYPE { BOING, SPACESHIP } TYPE;

class Rocket
{
public:
	Rocket() {};
	~Rocket() {};

private:
	TYPE m_type;
};

class Airplane
{
public:
	Airplane() {};
	~Airplane() {};

private:
	TYPE m_type;
};

class JetPlane : public Rocket, public Airplane
{
public:
	JetPlane() {};
	~JetPlane() {};

private:
	TYPE m_type;
};

class Seven47 : public JetPlane
{
public:
	Seven47() {};
	~Seven47() {};

private:

};




typedef enum COLOR { WHITE, BROWN, RED } COLOR;

class Vehicle
{
public:
	Vehicle();
	Vehicle(int mileage, COLOR color);
	virtual ~Vehicle();

	virtual void vehicleMove() const = 0;//{ cout << "Car moves\n"; };
	virtual void vehicleRefuel() const = 0;//{ cout << "Car filling up gas\n"; };
	virtual void vehicleStop() const = 0;//{ cout << "Car slowing down\n"; };

private:
	int m_mileage;
	COLOR m_color;
};

Vehicle::Vehicle()
{
}

Vehicle::Vehicle(int mileage, COLOR color) : m_mileage(mileage), m_color(color)
{
	cout << "Vehicle constructor!\n";
}

Vehicle::~Vehicle()
{
}

class Car
{
public:
	Car() {};
	virtual ~Car() {};

	virtual void vehicleMove() const { cout << "Vehicle moves\n"; };
	//virtual void vehicleRefuel() const { cout << "Vehicle filling up gas\n"; };
	//virtual void vehicleStop() const { cout << "Vehicle slowing down\n"; };



private:

};

class SportsCar : public Car
{
public:



private:

};


class Bus
{
public:
	Bus() {};
	virtual ~Bus() {};

	virtual void vehicleMove() const { cout << "Vehicle moves\n"; };
	virtual void vehicleRefuel() const { cout << "Vehicle filling up gas\n"; };
	virtual void vehicleStop() const { cout << "Vehicle slowing down\n"; };

private:

};

//------------------------------------------------------------------------------------------------------------
class CDate
{
private:
	int m_nDay; // Range: 1 - 30 (lets assume all months have 30 days!
	int m_nMonth; // Range: 1 - 12
	int m_nYear;
	void AddDays(int nDaysToAdd)
	{
		m_nDay += nDaysToAdd;
		if (m_nDay > 30)
		{
			AddMonths(m_nDay / 30);
			m_nDay %= 30; // rollover 30th -> 1st
		}
	}
	void AddMonths(int nMonthsToAdd)
	{
		m_nMonth += nMonthsToAdd;
		if (m_nMonth > 12)
		{
			AddYears(m_nMonth / 12);
			m_nMonth %= 12; // rollover dec -> jan
		}
	}
	void AddYears(int m_nYearsToAdd)
	{
		m_nYear += m_nYearsToAdd;
	}

	void SubDays(int nDaysToAdd)
	{
		m_nDay -= nDaysToAdd; // 30 - 31 = - 1
		if (m_nDay < 1)
		{
			SubMonths(m_nDay / 30);
			m_nDay %= 30; // rollover 30th -> 1st
		}
	}
	void SubMonths(int nMonthsToAdd)
	{
		m_nMonth -= nMonthsToAdd;
		if (m_nMonth < 12)
		{
			SubYears(m_nMonth / 12);
			m_nMonth %= 12; // rollover dec -> jan
		}
	}
	void SubYears(int m_nYearsToAdd)
	{
		m_nYear -= m_nYearsToAdd;
	}
public:
	// Constructor that initializes the object to a day, month and year
	CDate(int nDay, int nMonth, int nYear)
		: m_nDay(nDay), m_nMonth(nMonth), m_nYear(nYear) {};

	// Unary increment operator (prefix)
	CDate& operator ++ ()
	{
		AddDays(1);
		return *this;
	}

	//Unary decrement operator (prefix)

	CDate& operator-- ()
	{
		SubDays(1);
		return *this;
	}
	// postfix operator: differs from prefix in return-type and parameters
	CDate operator ++ (int)
	{
		// Create a copy of the current object, before incrementing day
		CDate mReturnDate(m_nDay, m_nMonth, m_nYear);
		AddDays(1);
		// Return the state before increment was performed
		return mReturnDate;
	}
	void DisplayDate()
	{
		std::cout << m_nDay << " / " << m_nMonth << " / " << m_nYear;
	}
};

class CMyArray
{
private:
	int* m_pnInternalArray;
	int m_nNumElements;
public:
	CMyArray(int nNumElements);
	~CMyArray();
	// declare a subscript operator
	int& operator [] (int nIndex);
	int& operator [] (int nIndex) const;
	bool operator == (CMyArray& nIndex);
	bool operator < (CMyArray& nIndex);
};

// subscript operator: allows direct access to an element given an index
int& CMyArray::operator [] (int nIndex)
{
	return m_pnInternalArray[nIndex];
}
int& CMyArray::operator [] (int nIndex) const
{
	return m_pnInternalArray[nIndex];
}

bool CMyArray::operator == (CMyArray& nIndex) {
	if (nIndex.m_nNumElements == this->m_nNumElements)
	{
		int arrSize = nIndex.m_nNumElements;
		for (int i = 0; i < arrSize; i++)
		{
			if (nIndex[i] != this->m_pnInternalArray[i])
			{
				return false;
			}
		}

		return true;
	}
	return false;
}

bool CMyArray::operator < (CMyArray& nIndex) {

	int sumArr1 = 0;

	int arrSize1 = nIndex.m_nNumElements;
	for (int i = 0; i < arrSize1; i++)
	{
		sumArr1 += nIndex[i];
	}

	int sumArr2 = 0;

	int arrSize2 = this->m_nNumElements;
	for (int i = 0; i < arrSize2; i++)
	{
		sumArr2 += this->m_pnInternalArray[i];

	}

	return static_cast<bool>((nIndex.m_nNumElements >= this->m_nNumElements) && (sumArr1 == sumArr2));

}


CMyArray::CMyArray(int nNumElements)
{
	m_pnInternalArray = new int[nNumElements];
	m_nNumElements = nNumElements;
}

CMyArray::~CMyArray()
{
	delete[] m_pnInternalArray;
}


template <typename T1 = int, typename T2 = double>
class CHoldsPair {

private:
	T1 m_Value1;
	T2 m_Value2;

public:
	CHoldsPair(const T1& value1, const T2& value2) {
		m_Value1 = value1;
		m_Value2 = value2;
	};
	const T1& getValue1() const { return this->m_Value1; }
	const T2& getValue2() const { return this->m_Value2; }
};

template<typename T>
const T Add(const T& var1, const T& var2) {
	return (var1 * var2);
}

template<typename T=int >
void Swap(T& var1, T& var2) {
	
	T var3 = var1;
	var1 = var2;
	var2 = var3;
}

template<typename T>
class MyClass
{
public:
	MyClass() {};
	~MyClass() {};

	void setArr(T& m_arr1) { 
	
		for (int i = 0; i < 10; i++)
		{
			T fillArray;
			cin << fillArray;
				m_arr1[i] = fillArray;
		}
	}

private:
	T m_arr1[10];
	T m_arr2[10];
};

enum MenuOptionSelection
{
	InsertContactsetEntry = 0,
	DisplayEntries = 1,
	FindNumber = 2,
	EraseEntry = 3,
	QuitApplication = 4
};

struct ContactItem
{
	string strContactsName;
	string strPhoneNumber;
	// Constructor
	ContactItem(const string& strName, const string& strNumber)
	{
		strContactsName = strName;
		strPhoneNumber = strNumber;
	}
	bool operator == (const ContactItem& itemToCompare) const
	{
		return (itemToCompare.strContactsName == this->strContactsName);
	}
	bool operator < (const ContactItem& itemToCompare) const
	{
		return (this->strPhoneNumber < itemToCompare.strPhoneNumber);
	}

};
struct wordProperty
{
	string strWord;
	bool bIsFromLatin;
};

//struct fPredicate
//{
//	bool operator< (const wordProperty& lsh, const wordProperty& rsh) const//??
//	{
//		return (lsh.strWord < rsh.strWord);
//	}
//};
//
//map <wordProperty, string, greater<wordProperty> fPredicate;
//

#endif // !CPP
