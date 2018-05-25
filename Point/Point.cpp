#include <iostream>
#include "Point.h"
#include <cmath>

// Public:
Point::Point(FieldElement x, FieldElement y, FieldElement a, FieldElement b)
	: mX(x), mY(y), mA(a), mB(b) 
{
	if (mY.powers(2) != mX.powers(3) + (mA * mX) + mB)
			throw std::runtime_error("Point not on curve");
	
	// unsure how to handle point at infinity
	// if (x.getNum() == NULL && y.getNum() == NULL)
	// 	throw std::runtime_error("Poiny at Infinity");
};
	
Point::Point(const int x, const int y, const int a, const int b, const int prime)
	: mX(FieldElement(x, prime)), mY(FieldElement(y, prime)), 
	  mA(FieldElement(a, prime)), mB(FieldElement(b, prime))
{
	if (mY.powers(2) != mX.powers(3) + (mA * mX) + mB)
		throw std::runtime_error("Point not on curve");
};

FieldElement Point::getX() { return mX; };
FieldElement Point::getY() { return mY; };
FieldElement Point::getA() { return mA; };
FieldElement Point::getB() { return mB; };

// arithmetic
bool Point::operator==(Point p2)
{
	return mX == p2.getX() && mY == p2.getY() && mA == p2.getA() && mB == p2.getB();
};

bool Point::operator!=(Point p2)
{
	return mX == p2.getX() && mY == p2.getY() && mA == p2.getA() && mB == p2.getB() ? false : true;
};

Point Point::operator+(Point p2)
{
	// if (this->a != p2.a || this->b != p2.b)
	// 	throw std::runtime_error("Points are using different curves");
	std::cout << "Before if: " << std::endl;
	if (mX != p2.getX())
	{
		std::cout << "Is this ever called?: " << std::endl;
		FieldElement slope = (mY - p2.getY()) / (mX - p2.getX());
		std::cout << "Result of mY - p2 Y: " << mY.getNum() << std::endl;

		// slope should be 217
		std::cout << "Slope: " << slope.getNum() << std::endl;

		// slope^2 - x1 - x2
		FieldElement x3 = slope.powers(2) - mX - p2.getX();

		// slope * (x1 - x3) - y1
		FieldElement y3 = slope * (mX - x3) - mY;

		std::cout << "X3 VALUE: " << x3.getNum() << std::endl;

		return Point(x3.getNum(), y3.getNum(), mA.getNum(), mB.getNum(), x3.getPrime());
	}
}; 
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
