#include <iostream>
#include "Point.h"
#include <cmath>

// constructor
Point::Point(FieldElement &x, FieldElement &y, FieldElement &a, FieldElement &b)
	: mX(&x), mY(&y), mA(&a), mB(&b) 
{
	// unsure how to handle point at infinity
	// if (x.getNum() == NULL && y.getNum() == NULL)
	// 	throw std::runtime_error("Poiny at Infinity");
	
	// if (y.powers(2) != x.powers(3) + (a * x) + b)
	// 	throw std::runtime_error("Point not on curve");
};
	
Point::Point(const int x, const int y, const int a, const int b, const int prime)
	: mX(new FieldElement(x, prime)), mY(new FieldElement(y, prime)), 
	  mA(new FieldElement(a, prime)), mB(new FieldElement(b, prime))
	  {};

// setter and getters
FieldElement Point::getX() { return *mX; };
FieldElement Point::getY() { return *mY; };

// // arithmetic
// bool Point::operator==(Point p2)
// {
// 	return this->x == p2.x && this->y == p2.y && this->a == p2.a && this->b == p2.b;
// };

// bool Point::operator!=(Point p2)
// {
// 	return this->x == p2.x && this->y == p2.y && this->a == p2.a && this->b == p2.b ? false : true;
// };

// Point Point::operator+(Point p2)
// {
// 	if (this->a != p2.a || this->b != p2.b)
// 		throw std::runtime_error("Points are using different curves");

// 	if (this->x != p2.getX())
// 	{
// 		FieldElement slope = (p2.getY() - this->y) / (p2.getX() - this->x);

// 		// slope^2 - x1 - x2
// 		FieldElement x3 = slope.powers(2) - this->x - p2.getX();

// 		// slope * (x1 - x3) - y1
// 		FieldElement y3 = slope * (this->x - x3) - this->y;

// 		return Point(&x3, &y3, &this->a, &this->b);
// 	} else {
// 		// point doubling
// 		// (3 * x1^2 + a) / (2 * y1)
// 		// Hacky solution to using prime for FieldElement
// 		FieldElement slope = (FieldElement(3, this->x.getPrime()) * this->x.powers(2) + this->a) / (FieldElement(2, this->x.getNum()) * this->y);

// 		// slope^2 - 2 * x1
// 		FieldElement x3 = slope.powers(2) - FieldElement(2, this->x.getPrime()) * this->x;

// 		// slope * (x1 - x3) - y1
// 		FieldElement y3 = slope * (this->x - x3) - this->y;

// 		return Point(&x3, &y3, &this->a, &this->b);
// 	}
// };