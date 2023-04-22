#include "Product.h"
#include <iostream>


void Product::Serialize(std::ostream& out) {

	out << m_price << ' ';
}

void Product::DeSerialize(std::istream& in) {

	in >> m_price;
}