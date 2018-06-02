#ifndef Point_H
#define Point_H
#include "../FieldElement/FieldElement.h"
#include <boost/multiprecision/cpp_int.hpp>

class Point 
{
    private:
        FieldElement mX;
        FieldElement mY; 
        FieldElement mA; 
        FieldElement mB;

    public:
        Point();
        Point(FieldElement x, FieldElement y, FieldElement a, FieldElement b);
        Point(const boost::multiprecision::cpp_int x, const boost::multiprecision::cpp_int y, 
              const boost::multiprecision::cpp_int a, const boost::multiprecision::cpp_int b, 
              const boost::multiprecision::cpp_int prime);

        FieldElement getX();
        FieldElement getY();
        FieldElement getA();
        FieldElement getB();

        bool operator==(Point p2);
        bool operator!=(Point p2);
        Point operator+(Point p2);
        Point rmul(const boost::multiprecision::cpp_int scalar);
        Point pointDoubling();
};

#endif /* Point_H */
