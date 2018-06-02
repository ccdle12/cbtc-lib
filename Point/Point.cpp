#include <iostream>
#include "Point.h"
#include <cmath>

namespace mp = boost::multiprecision;

// Public:
Point::Point(FieldElement x, FieldElement y, FieldElement a, FieldElement b): mX(x), mY(y), mA(a), mB(b) 
{
	if (0 == x.getNum() && 0 == y.getNum())
		return;

	if (mY.pow(2) != mX.pow(3) + (mA * mX) + mB)
		throw std::runtime_error("Point not on curve");
};

Point::Point(const boost::multiprecision::cpp_int x, const boost::multiprecision::cpp_int y, 
			 const boost::multiprecision::cpp_int a, const boost::multiprecision::cpp_int b, 
			 const boost::multiprecision::cpp_int prime)
	: mX(FieldElement(x, prime)), mY(FieldElement(y, prime)), 
	  mA(FieldElement(a, prime)), mB(FieldElement(b, prime))
{
	if (0 == x && 0 == y)
		return;

	if (mY.pow(2) != mX.pow(3) + (mA * mX) + mB)
		throw std::runtime_error("Point not on curve");
};

FieldElement Point::getX() { return mX; };
FieldElement Point::getY() { return mY; };
FieldElement Point::getA() { return mA; };
FieldElement Point::getB() { return mB; };

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
	if (mA != p2.getA() || mB != p2.getB())
		throw std::runtime_error("Points are using different curves");

	if (mX.getNum() == 0)
		return p2;

	if (p2.getX().getNum() == 0)
		return *this;

	// Point at infinity
	if (mX == p2.getX() && mY != p2.getY())
		return Point(0, 0, mA.getNum(), mB.getNum(), mX.getPrime());

	if (mX != p2.getX())
	{
		FieldElement slope = (mY - p2.getY()) / (mX - p2.getX());
		FieldElement x3 = slope.pow(2) - mX - p2.getX();
		FieldElement y3 = slope * (mX - x3) - mY;

		return Point(x3, y3, mA, mB);
	} else {
		return p2.pointDoubling();
	}
};

Point Point::pointDoubling()
{
	// (3 * x1^2 + a) / (2 * y1)
	FieldElement numeratorCoefficient = FieldElement(3, mX.getPrime());
	FieldElement denominatorCoefficient = FieldElement(2, mX.getPrime());

	FieldElement slope = (numeratorCoefficient * (mX.pow(2)) + mA) / (denominatorCoefficient * mY);

	// slope^2 - 2 * x1
	FieldElement x3 = slope.pow(2) - denominatorCoefficient * mX;

	// slope * (x1 - x3) - y1
	FieldElement y3 = slope * (mX - x3) - mY;

	return Point(x3, y3, mA, mB);
};

Point Point::rmul(const boost::multiprecision::cpp_int scalar)
{
	mp::cpp_int xPrime = mX.getPrime();
	
	FieldElement x = FieldElement(0, xPrime);
	FieldElement y = FieldElement(0, xPrime);
	FieldElement a = FieldElement(0, xPrime);
	FieldElement b = FieldElement(7, xPrime);
	Point point = Point(x, y, a, b);

	for (int i = 0; i < scalar; ++i)
		point = point + *this;
	
	return point;
};