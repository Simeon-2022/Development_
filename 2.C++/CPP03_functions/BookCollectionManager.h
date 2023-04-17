#pragma once
#include "BookCollection.h"

class BookCollectionManager {

private:
	std::vector<BookCollection> m_seriesList;
public:
	void addBookCollection(BookCollection& series); 

	const std::vector<BookCollection> getBookCollection() const;

};

