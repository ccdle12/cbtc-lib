#include <iostream>
#include "S256Point.h"
#include <cmath>

namespace mp = boost::multiprecision;

// Public
S256Point::S256Point()
{
    this->P = (mp::cpp_int) pow(2.0, 256) - (mp::cpp_int) pow(2.0, 32) - (mp::cpp_int) pow(2.0, 97);
    this->A = (mp::cpp_int) 0;
    this->B = (mp::cpp_int) 7;
};
