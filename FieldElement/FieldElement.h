#ifndef FieldElement_H
#define FieldElement_H
#include <iostream>
#include <cmath>

class FieldElement
{   
    private:
        int mNum, mPrime;
        bool check_primes_the_same(int prime);

    public:
        int getNum();
        int getPrime();

        FieldElement();
        FieldElement(int num, int prime);

        bool operator==(FieldElement fe2);
        bool operator!=(FieldElement fe2);
        FieldElement operator+(FieldElement fe2);
        FieldElement operator*(FieldElement fe2);
        FieldElement powers(int power);
        FieldElement operator/(FieldElement fe2);
        FieldElement operator-(FieldElement fe2);
};

#endif /* FieldElement_H */
