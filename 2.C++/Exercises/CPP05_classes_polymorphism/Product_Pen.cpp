#include "Product_Pen.h"

Product_Pen::Product_Pen() {};

E_ProductType Product_Pen::GetType() 
{
	return E_ProductType_Pen;
}

void Product_Pen::Serialize(std::ostream& out) {

	Product::Serialize(out);
	out << m_inkColor;
}

void Product_Pen::DeSerialize(std::istream& in) {

	Product::DeSerialize(in);

	int inkColor = 0;
	in >> inkColor;
	m_inkColor = static_cast <E_ColorPen> (inkColor);
}