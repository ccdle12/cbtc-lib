#include <iostream>
#include "Point.h"
#include <cmath>

// constructor
Point::Point(FieldElement &x, FieldElement &y, FieldElement &a, FieldElement &b)
	: mX(&x), mY(&y), mA(&a), mB(&b) 
{
	if (mY->powers(2) != mX->powers(3) + (*mA * *mX) + *mB)
			throw std::runtime_error("Point not on curve");
	
	// unsure how to handle point at infinity
	// if (x.getNum() == NULL && y.getNum() == NULL)
	// 	throw std::runtime_error("Poiny at Infinity");
};
	
Point::Point(const int x, const int y, const int a, const int b, const int prime)
	: mX(new FieldElement(x, prime)), mY(new FieldElement(y, prime)), 
	  mA(new FieldElement(a, prime)), mB(new FieldElement(b, prime))
{
	if (mY->powers(2) != mX->powers(3) + (*mA * *mX) + *mB)
		throw std::runtime_error("Point not on curve");
};

// setter and getters
FieldElement Point::getX() { return *mX; };
FieldElement Point::getY() { return *mY; };
FieldElement Point::getA() { return *mA; };
FieldElement Point::getB() { return *mB; };

// arithmetic
bool Point::operator==(Point p2)
{
	return *mX == p2.getX() && *mY == p2.getY() && *mA == p2.getA() && *mB == p2.getB();
};

bool Point::operator!=(Point p2)
{
	return *mX == p2.getX() && *mY == p2.getY() && *mA == p2.getA() && *mB == p2.getB() ? false : true;
};

Point Point::operator+(Point p2)
{
	// if (this->a != p2.a || this->b != p2.b)
	// 	throw std::runtime_error("Points are using different curves");

	if (*mX != p2.getX())
	{
		FieldElement slope = (p2.getY() - *mY) / (p2.getX() - *mX);

		// slope^2 - x1 - x2
		FieldElement x3 = slope.powers(2) - *mX - p2.getX();

		// slope * (x1 - x3) - y1
		FieldElement y3 = slope * (*mX - x3) - *mY;

		return Point(x3.getNum(), y3.getNum(), mA->getNum(), mB->getNum(), x3.getPrime());
	} 
	// else {
	// 	// point doubling
	// 	// (3 * x1^2 + a) / (2 * y1)
	// 	// Hacky solution to using prime for FieldElement
	// 	FieldElement slope = (FieldElement(3, this->x.getPrime()) * this->x.powers(2) + this->a) / (FieldElement(2, this->x.getNum()) * this->y);

	// 	// slope^2 - 2 * x1
	// 	FieldElement x3 = slope.powers(2) - FieldElement(2, this->x.getPrime()) * this->x;

	// 	// slope * (x1 - x3) - y1
	// 	FieldElement y3 = slope * (this->x - x3) - this->y;

	// 	return Point(&x3, &y3, &this->a, &this->b);
	// }
};