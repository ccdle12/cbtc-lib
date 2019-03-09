#include <iostream>
#include "S256Point.h"
#include <cmath>

namespace mp = boost::multiprecision;

// Public
S256Point::S256Point(): P(pow(2.0, 256) - pow(2.0, 32) - pow(2.0, 97)), A(0), B(7) {};
