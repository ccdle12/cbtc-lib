#include "../FieldElement/FieldElement.h"

class Point 
{
    private:
        FieldElement *mX;
        FieldElement *mY; 
        FieldElement *mA; 
        FieldElement *mB;

    public:
        // constructor
        Point(FieldElement *x, FieldElement *y, FieldElement *a, FieldElement *b);

        // overload constructor
        // Point(const int _x, const int _y, const int _a, const int _b, const int prime): x(_x, prime), y(_y, prime), a(_a, prime), b(_b, prime) {};

        // setter and getters
        FieldElement* getX();
        FieldElement* getY();

        // arithmetic
        // bool operator==(Point p2);
        // bool operator!=(Point p2);
        // Point operator+(Point p2);
};