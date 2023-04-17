#pragma once
#include <string>
#include "Product.h"

enum E_BookSeriesProduct {


	E_Trilogy,
	E_Sequel,
	E_Saga,
	E_Anthology,
	E_Collection,
	E_Chronicles

};

class BookSeriesProduct : public Product
{

public:

	virtual	E_ProductType GetType() = 0;
	friend class ProductManager;
private:
	E_BookSeriesProduct m_seriesType;
	std::string m_seriesTitle;
	std::string m_seriesAuthor;
};

