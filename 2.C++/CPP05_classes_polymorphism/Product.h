#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

enum E_ProductType {

	E_ProductType_Book = 1,
	E_ProductType_Pen,
	E_ProductType_Series
};

class Product
{
private:
	Product();

protected:
	typedef double moneyType;
	moneyType m_price;

public:
	//Product();
	virtual	E_ProductType GetType() = 0;
	virtual void DeSerialize(std::istream& in );
	virtual void Serialize(std::ostream& out);
	friend class ProductManager;
	virtual ~Product() {};
};

