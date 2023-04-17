#pragma once
#include <string>
#include "Product.h"

enum E_Book_Genre {

	E_Book_Genre_Drama,
	E_Book_Genre_Comedy

};

class Product_Book : public Product
{
public:

	virtual	E_ProductType GetType();
	friend class ProductManager;
	Product_Book();
private:

	E_Book_Genre m_genre;
	std::string m_author;
	std::string m_title;
};



