#ifndef FieldElement_hpp
#define FieldElement_hpp
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
        FieldElement(int num, int prime): mNum(num), mPrime(prime) 
        {
            if (mNum > mPrime || mNum < 0) 
                throw std::runtime_error("Num must be within field of prime");
        }

        // arithmetic
        bool operator==(FieldElement fe2);
        bool operator!=(FieldElement fe2);
        FieldElement operator+(FieldElement fe2);
        FieldElement operator*(FieldElement fe2);
        FieldElement powers(int power);
        FieldElement operator/(FieldElement fe2);
        FieldElement operator-(FieldElement fe2);
};
#endif /* FieldElement_hpp */