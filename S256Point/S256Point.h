#ifndef S256Point_H
#define S256Point_H
#include <boost/multiprecision/cpp_int.hpp>

class S256Point
{
    public:
        const boost::multiprecision::cpp_int P;
        const boost::multiprecision::cpp_int A;
        const boost::multiprecision::cpp_int B;
        S256Point();
};

#endif /* Point_H */