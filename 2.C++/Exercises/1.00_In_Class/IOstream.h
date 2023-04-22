#pragma once
#include <cstring>
#include <iostream>
#include <string>

class Student {

public:

	friend std::istream& operator>>(std::istream& in, Student& student);
	friend std::ostream& operator<<(std::ostream& in, const Student& student);
private:

	std::string m_name;
	int m_fn;
	bool m_hasHomeWork;
	float m_StudyTime;

};


