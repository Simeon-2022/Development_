#pragma once
#include<vector>
#include "Product.h"
class Product_Manager
{
private:

	std::vector <Product*> m_products;

		
public:

	void SerializeProducts(const std::string& filename);
	void DeSerializeProducts(const std::string& filename);
};

