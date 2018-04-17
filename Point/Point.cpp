#include <iostream>
#include "Point.h"
#include <cmath>

// constructor
Point::Point(FieldElement x, FieldElement y, FieldElement a, FieldElement b)
{
	// unsure how to handle point at infinity
	if (x == NULL && y == NULL)
		throw std::runtime_error("Poiny at Infinity");
		 
	if (std::pow(y, 2) != std::pow(x, 3) + (a*x) + b)
		throw std::runtime_error("Point not on curve");

    this->x = x;
    this->y = y;
    this->a = a;
    this->b = b;
};

// setter and getters
int Point::getX() { return this->x; };
int Point::getY() { return this->y; };

// arithmetic
bool Point::operator==(Point p2)
{
	return this->x == p2.x && this->y == p2.y && this->a == p2.a && this->b == p2.b;
};

bool Point::operator!=(Point p2)
{
	return this->x == p2.x && this->y == p2.y && this->a == p2.a && this->b == p2.b ? false : true;
};

Point Point::operator+(Point p2)
{
	if (this->a != p2.a || this->b != p2.b)
		throw std::runtime_error("Points are using different curves");
		
	int x3, y3;

	if (this->x != p2.getX())
	{
		int slope = (p2.getY() - this->y) / (p2.getX() - this->x);

		// slope^2 - x1 - x2
		x3 = std::pow(slope, 2) - this->x - p2.getX();

		// slope * (x1 - x3) - y1
		y3 = slope * (this->x - x3) - this->y;
	} else {
		// point doubling
		// (3 * x1^2 + a) / (2 * y1)
		int slope = (3 * std::pow(this->x, 2) + this->a) / (2 * this->y);

		// slope^2 - 2 * x1
		x3 = std::pow(slope, 2) - 2 * this->x;

		// slope * (x1 - x3) - y1
		y3 = slope * (this->x - x3) - this->y;
	}

	return Point(x3, y3, this->a, this->b);
};