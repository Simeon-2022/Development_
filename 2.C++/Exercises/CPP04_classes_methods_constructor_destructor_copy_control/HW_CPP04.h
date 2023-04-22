#pragma once
#define _CRT_SECURE_NO_WARNINGS

namespace ca {
	class String
	{
	public:

		inline const char* c_str() const;

		String();
		String(const char* data);
		~String();
		String(const String & data);

		inline size_t size() const;

		String& operator=(const String& other);

	private:
		char* m_data;
		size_t m_size;
	};

	//void test() {
	//	String a("hello");
	//	String b;
	//	String c("");
	//}
};
