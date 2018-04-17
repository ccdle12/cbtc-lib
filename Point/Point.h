#include "../FieldElement/FieldElement.cpp"

class Point 
{
    private:
        FieldElement x, y, a, b;

    public:
        // constructor
        Point(FieldElement x, FieldElement y, FieldElement a, FieldElement b);

        // setter and getters
        FieldElement getX();
        FieldElement getY();

        // arithmetic
        bool operator==(Point p2);
        bool operator!=(Point p2);
        Point operator+(Point p2);
};