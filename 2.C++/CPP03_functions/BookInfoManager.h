#pragma once
#include "BookInfo.h"

class BookInfoManager
{
private:
	std::vector< BookInfo> m_books;
public:
	void addBookInfos(std::istream& fileName)
	{

	}

	void addBook(BookInfo& book);
	const std::vector< BookInfo>& getBooks() const;
};

