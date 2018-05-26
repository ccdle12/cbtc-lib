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
        Point(FieldElement x, FieldElement y, FieldElement a, FieldElement b);
        Point(const int _x, const int _y, const int _a, const int _b, const int prime);

        FieldElement getX();
        FieldElement getY();
        FieldElement getA();
        FieldElement getB();

        bool operator==(Point p2);
        bool operator!=(Point p2);
        Point operator+(Point p2);
};

#endif /* Point_H */
