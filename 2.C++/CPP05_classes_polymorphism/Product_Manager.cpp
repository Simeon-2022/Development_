#include "Product_Manager.h"
#include "Product_Book.h"
#include "Product.h"
#include "Product_Pen.h"

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

void Product_Manager::SerializeProducts(const std::string& filenameRead)
{
	//Open file
	std::ofstream outputFile(filenameRead);
	if (!outputFile)
	{
		return;
	}

	for (int i = 0; i < m_products.size(); i++)
	{
		outputFile << m_products[i]->GetType() << '#';
		
	}
};

void Product_Manager::DeSerializeProducts(const std::string& filenameWrite)
{
	//Open file
	std::ifstream inputFile(filenameWrite);
	if (!inputFile)
	{
		return;
	}

	std::string str;
	while (std::getline(inputFile, str))
	{
		int prodType = 0;
		std::istringstream iss(str);
		iss >> prodType;
		Product* product = 0;

		switch (prodType)
		{
		case E_ProductType_Book:
			product = new Product_Book();

			break;
		case E_ProductType_Pen:
			product = new Product_Pen();

			break;
		//To do
		//case E_ProductType_Series:
		//	product = new BookSeriesProduct();
		//	break;
		default:
			break;
		}
		product->DeSerialize(iss);
		m_products.push_back(product);

	}

};
