#include <cstring>
#include <iostream>
#include <string>
#include "IOstream.h"


std::istream& operator>>(std::istream& in, Student& student) {

	return in >> student.m_name >> student.m_fn  >> student.m_hasHomeWork >> student.m_StudyTime;
}

std::ostream& operator<<(std::ostream& out, const Student& student) {

	return out << student.m_name << " " << student.m_fn << " " << student.m_hasHomeWork << " " << student.m_StudyTime;
}



int main() {

	Student student;
	Student student2;

	//std::cin >> student;
	//std::cout << student; //<< student2;
		
	int a, b;
	std::cout << "Enter two integers separated by space: >> ";
	std::cin >> a >> b;
	std::cout << a << " " << b;

	return 0;
}