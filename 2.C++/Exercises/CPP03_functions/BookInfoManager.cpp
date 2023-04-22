#include "BookInfoManager.h"
#include<vector>

void BookInfoManager::addBook(BookInfo& book) { m_books.push_back(book); }

const std::vector< BookInfo>& BookInfoManager::getBooks() const { return m_books; }


