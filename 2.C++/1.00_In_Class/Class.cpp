#include "Class.h"

A::A()
{

}
A::A(const std::string& defString, int defint) :strName(defString), age(defint)
{

}
A::~A()
{
}
A::A(const A& a) :strName(a.strName), age(a.age)
{

}
A::E_neshto A::getNeshto(E_neshto n)
{
	return Ok;
}

void A::setName(const std::string& newName) 
{
	strName = newName;
}
const std::string& A::getName(void) const 
{
	return strName;
}