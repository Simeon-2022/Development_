#pragma once
#include "Product.h"

enum E_ColorPen {

	E_Color_Red,
	E_Color_Blue

};

class Product_Pen : public Product
{

public:
	
	virtual	E_ProductType GetType();
	virtual void DeSerialize(std::istream& in);
	virtual void Serialize(std::ostream& out);
	friend class ProductManager;
	Product_Pen();
private:

	E_ColorPen m_inkColor;
};

