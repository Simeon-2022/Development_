#include "BookCollectionManager.h"


void BookCollectionManager::addBookCollection(BookCollection& series) { m_seriesList.push_back(series); }

const std::vector<BookCollection> BookCollectionManager::getBookCollection() const { return m_seriesList; }

