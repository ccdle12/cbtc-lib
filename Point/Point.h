#ifndef Point_H
#define Point_H
#include "../FieldElement/FieldElement.h"

class Point 
{
    private:
        FieldElement mX;
        FieldElement mY; 
        FieldElement mA; 
        FieldElement mB;

    public:
        // constructor
        Point(FieldElement x, FieldElement y, FieldElement a, FieldElement b);

        // overload constructor
        Point(const int _x, const int _y, const int _a, const int _b, const int prime);

        // setter and getters
        FieldElement getX();
        FieldElement getY();
        FieldElement getA();
        FieldElement getB();

        // arithmetic
        bool operator==(Point p2);
        bool operator!=(Point p2);
        Point operator+(Point p2);
};

#endif /* Point_H */
