#include "BookInfo.h"
#include "BookCollection.h"
#include<vector>

BookCollection::BookCollection() {};

BookCollection::BookCollection(	  const std::string& m_name
								, const std::vector< BookInfo*>& m_books)
								: m_name(m_name)
								, m_books(m_books) {};

	const std::string& BookCollection::getName() const { return m_name; };

std::vector<BookInfo*> BookCollection::getBooks() const { return this->m_books; };

				//  void BookCollection::addBook(const BookInfo& book) { m_books.push_back(&book); };