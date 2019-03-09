#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE S256Point_tests

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "S256Point.cpp"

namespace mp = boost::multiprecision;

BOOST_AUTO_TEST_SUITE(intialize_object_test)

BOOST_AUTO_TEST_CASE(default_constructor)
{
    S256Point point = S256Point();
    BOOST_CHECK_EQUAL(point.A, 0);
    BOOST_CHECK_EQUAL(point.B, 7);
};

BOOST_AUTO_TEST_CASE(P_initalization)
{
    S256Point point = S256Point();

    mp::cpp_int less_than_N = (mp::cpp_int) pow(10.0, 22);
    BOOST_CHECK(point.P > less_than_N);
};

BOOST_AUTO_TEST_SUITE_END(); // initialize_object_tests
