#include <iostream>
#include <cmath>

class FieldElement
{   
    // variables
    private:
        int mNum, mPrime;
        bool check_primes_the_same(int prime);

    public:
        // setters and getters
        int getNum();
        int getPrime();

        // constructor
        FieldElement(int num, int prime);

        // arithmetic
        bool operator==(FieldElement fe2);
        bool operator!=(FieldElement fe2);
        FieldElement operator+(FieldElement fe2);
        FieldElement operator*(FieldElement fe2);
        FieldElement powers(int power);
        FieldElement operator/(FieldElement fe2);
        FieldElement operator-(FieldElement fe2);
};