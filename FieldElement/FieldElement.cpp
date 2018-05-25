#include "./FieldElement.h"

// Private:
bool FieldElement::check_primes_the_same(int prime)
{
    if (FieldElement::mPrime != prime)
        throw std::runtime_error("Primes must be the same");

    return true;
};

// Public:
FieldElement::FieldElement() {};
FieldElement::FieldElement(int num, int prime): mNum(num), mPrime(prime) 
{
    if (mNum > mPrime || mNum < 0) 
    {   
        std::cout << "Field Element: " << num << std::endl;
        throw std::runtime_error("Num must be within field of prime");
    }
};
  
int FieldElement::getNum() { return mNum; }
int FieldElement::getPrime() { return mPrime; }

// arithmetic
bool FieldElement::operator==(FieldElement fe2)
{
    return FieldElement::mNum == fe2.getNum() && FieldElement::mPrime == fe2.getPrime();
};

bool FieldElement::operator!=(FieldElement fe2)
{
    return FieldElement::mNum == fe2.getNum() && FieldElement::mPrime == fe2.getPrime() ? false : true;
};

FieldElement FieldElement::operator+(FieldElement fe2)
{
    check_primes_the_same(fe2.getPrime());

    int num = (FieldElement::mNum + fe2.getNum()) % FieldElement::mPrime;
    return FieldElement(num, getPrime());
};

FieldElement FieldElement::operator*(FieldElement fe2)
{
    check_primes_the_same(fe2.getPrime());

    int num = (FieldElement::mNum * fe2.getNum()) % FieldElement::mPrime;
    return FieldElement(num, getPrime());
};

FieldElement FieldElement::operator-(FieldElement fe2)
{
    check_primes_the_same(fe2.getPrime());

    int num = (FieldElement::mNum - fe2.getNum()) % FieldElement::mPrime;
    return FieldElement(num, getPrime());
};

FieldElement FieldElement::powers(int power)
{   
    int exponent = power % (FieldElement::mPrime - 1);

    int pow_product = std::pow(FieldElement::mNum, exponent);
    int num = pow_product % FieldElement::mPrime;

    return FieldElement(num, FieldElement::mPrime);
};

FieldElement FieldElement::operator/(FieldElement fe2)
{   
    check_primes_the_same(fe2.getPrime());

    // formula
    // FieldElement::mNum * std::pow(fe2.getNum(), FieldElement::mPrime - 2) % FieldElement::mPrime
    int b = std::pow(fe2.getNum(), FieldElement::mPrime - 2);
    int num = (FieldElement::mNum * b) % FieldElement::mPrime;

    return FieldElement(num, FieldElement::mPrime);
};
