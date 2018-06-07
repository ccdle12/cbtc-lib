#ifndef FieldElement_H
#define FieldElement_H
#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

class FieldElement
{   
    private:
        boost::multiprecision::cpp_int mNum, mPrime;
        boost::multiprecision::cpp_int powers(boost::multiprecision::cpp_int coefficient, boost::multiprecision::cpp_int exponent);
        boost::multiprecision::cpp_int euclidean_remainder(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int b);
        bool check_primes_the_same(boost::multiprecision::cpp_int prime);

    public:
        boost::multiprecision::cpp_int getNum();
        boost::multiprecision::cpp_int getPrime();

        FieldElement();
        FieldElement(const boost::multiprecision::cpp_int num, const boost::multiprecision::cpp_int prime);
        ~FieldElement(){};

        bool operator==(FieldElement fe2);
        bool operator!=(FieldElement fe2);
        FieldElement operator+(FieldElement fe2);
        FieldElement operator-(FieldElement fe2);
        FieldElement operator*(FieldElement fe2);
        FieldElement pow(boost::multiprecision::cpp_int exponent);
        FieldElement operator/(FieldElement fe2);
};

#endif /* FieldElement_H */
