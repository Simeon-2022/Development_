#pragma once
#include <string>
#include <iostream>

class A
{
public:
	A();
	A(const std::string& defString, int defint);
	~A();
	inline void setName(const std::string& newName);
	inline const std::string getName(void) const;
	enum E_neshto {Ok,Error};
	E_neshto getNeshto(E_neshto);
	A(const A& a);
private:
	std::string strName;
	int age;

protected:


};


void  f()
{
	A objA;
	A objB("Ivan", 35);
	const std::string& varName = objA.getName();


}