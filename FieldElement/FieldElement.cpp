#include "./FieldElement.h"

// private
bool FieldElement::check_primes_the_same(int prime)
{
    if (this->prime != prime)
        throw std::runtime_error("Primes must be the same");

        return true;
}

// constructor
FieldElement::FieldElement(int num, int prime)
{
    if (num > prime || num < 0)
        throw std::runtime_error("Num must be within field of prime");

    this->num = num;
    this->prime = prime;
};

// public    
int FieldElement::getNum() { return this->num; }
int FieldElement::getPrime() { return this->prime; }

// arithmetic
bool FieldElement::operator==(FieldElement fe2)
{
    return this->num == fe2.getNum() && this->prime == fe2.getPrime();
};

bool FieldElement::operator!=(FieldElement fe2)
{
    return this->num == fe2.getNum() && this->prime == fe2.getPrime() ? false : true;
};

FieldElement FieldElement::operator+(FieldElement fe2)
{
    check_primes_the_same(fe2.getPrime());

    int num = (this->num + fe2.getNum()) % this->prime;
    return FieldElement(num, getPrime());
};

FieldElement FieldElement::operator*(FieldElement fe2)
{
    check_primes_the_same(fe2.getPrime());

    int num = (this->num * fe2.getNum()) % this->prime;
    return FieldElement(num, getPrime());
};

FieldElement FieldElement::powers(int power)
{   
    int exponent = power % (this->prime - 1);

    int pow_product = std::pow(this->num, exponent);
    int num = pow_product % this->prime;

    return FieldElement(num, this->prime);
};

FieldElement FieldElement::operator/(FieldElement fe2)
{   
    check_primes_the_same(fe2.getPrime());

    // formula
    // this->num * std::pow(fe2.getNum(), this->prime - 2) % this->prime
    int b = std::pow(fe2.getNum(), this->prime - 2);
    int num = (this->num * b) % this->prime;

    return FieldElement(num, this->prime);
};