#include "FieldElement.h"

namespace mp = boost::multiprecision;

// Private:
bool FieldElement::check_primes_the_same(mp::cpp_int prime)
{
    if (mPrime != prime)
        throw std::runtime_error("Primes must be the same");

    return true;
};

mp::cpp_int FieldElement::powers(mp::cpp_int coefficient, mp::cpp_int exponent)
{
    mp::cpp_int result = 1;

    for (int i = 0; i < exponent; ++i) result *= coefficient;
    return result;
};

mp::cpp_int FieldElement::euclidean_remainder(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int b) 
 {
    assert(b != 0);
    mp::cpp_int r = a % b;

    return r >= 0 ? r : r + b;
 };

// Public:
FieldElement::FieldElement() {};
FieldElement::FieldElement(mp::cpp_int num,mp::cpp_int prime): mNum(num), mPrime(prime) 
{
    if (mNum > mPrime || mNum < 0) 
        throw std::runtime_error("Num must be within field of prime");
};
  
mp::cpp_int FieldElement::getNum() { return mNum; }
mp::cpp_int FieldElement::getPrime() { return mPrime; }

bool FieldElement::operator==(FieldElement fe2)
{
    return mNum == fe2.getNum() && mPrime == fe2.getPrime();
};

bool FieldElement::operator!=(FieldElement fe2)
{
    return mNum == fe2.getNum() && mPrime == fe2.getPrime() ? false : true;
};

FieldElement FieldElement::operator+(FieldElement fe2)
{
    check_primes_the_same(fe2.getPrime());

    mp::cpp_int product = mNum + fe2.getNum();
    mp::cpp_int num = euclidean_remainder(product, mPrime);
    return FieldElement(num, mPrime);
};

FieldElement FieldElement::operator*(FieldElement fe2)
{
    check_primes_the_same(fe2.getPrime());

    mp::cpp_int product = mNum * fe2.getNum();
    mp::cpp_int num = euclidean_remainder(product, mPrime);
    return FieldElement(num, mPrime);
};

FieldElement FieldElement::operator-(FieldElement fe2)
{
    check_primes_the_same(fe2.getPrime());

    mp::cpp_int product = mNum - fe2.getNum();
    mp::cpp_int num = euclidean_remainder(product, mPrime);
    return FieldElement(num, mPrime);
};

FieldElement FieldElement::pow(mp::cpp_int exponent)
{   
    mp::cpp_int powProduct = FieldElement::powers(mNum, exponent);
    mp::cpp_int num = euclidean_remainder(powProduct, mPrime);

    return FieldElement(num, mPrime);
};

FieldElement FieldElement::operator/(FieldElement fe2)
{   
    check_primes_the_same(fe2.getPrime());
    
    /**
     * Formula
     * -------
     *  n = numerator
     *  d = denominator
     *  normal div := n/d
     *  modulo div := (n * (d**p-2)) % p
     */
    mp::cpp_int exponent = FieldElement::powers(fe2.getNum(), mPrime - 2);
    mp::cpp_int product = (mNum * exponent); 
    mp::cpp_int result = euclidean_remainder(product, mPrime);

    return FieldElement(result, mPrime);
};
