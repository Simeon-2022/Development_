//#pragma once
#ifndef BOOK_COLLECTION_H
#define BOOK_COLLECTION_H

#include<iostream>
#include<vector>
#include "BookInfo.h"

class BookCollection {

private:
	std::vector< BookInfo*> m_books;
	std::string m_name;
public:
	BookCollection();

	BookCollection(const std::string& m_name, const std::vector< BookInfo*>& m_books);

	const std::string& getName() const;

	std::vector< BookInfo*> getBooks() const;

};



#endif // !BOOK_COLLECTION_H
