#define _CRT_SECURE_NO_WARNINGS
#include "HW_CPP04.h"
#include "String.h"
#include <cstring>
#include <iostream>


// No.4 Classes Methods Constructors;
namespace ca {

	const char* String::c_str() const {
		return m_data;
	}

	String::String() :m_data(0), m_size(0) {};
	String::String(const char* data) :m_data(0), m_size(strlen(data)) {
		
		m_data = new char[m_size + 1];
		strcpy_s(m_data, m_size + 1, data);

	}

	String::~String() {

		delete[] m_data;
	}

	String::String(const String& data) :m_data(0), m_size(data.m_size) {

		m_data = new char[m_size + 1];
		strcpy_s(m_data, m_size + 1, data.m_data);
	}

	size_t String::size() const {
		return m_size;
	}

	String& String::operator=(const String& other) 
	{
		if (this == &other)
		{
			return *this;
		}

		delete[] m_data;
		m_data = new char[other.m_size + 1];
		m_size = other.m_size;
		strcpy_s(m_data, m_size + 1, other.c_str());

		return *this;
	};

}

	int main() {

		ca::String a("hello ");
		ca::String b("world");
		b = a;
		
		std::cout << a.size() << std::endl;
		std::cout << std:: string("hello ").size() << std::endl;

		return 0;
	}