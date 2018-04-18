#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Point_tests
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "./Point.cpp"
#include "../FieldElement/FieldElement.cpp"

BOOST_AUTO_TEST_CASE(sanitycheck)
{
    std::cout << "Point tests" << std::endl;
};

BOOST_AUTO_TEST_CASE(point_constructor_throw)
{
    BOOST_CHECK_THROW(Point(FieldElement(2, 31), FieldElement(7, 31), FieldElement(5, 31), FieldElement(7, 31)), std::runtime_error);
    // BOOST_CHECK_THROW(Point(4358934, 1948234, 0, 7), std::runtime_error);
    // BOOST_CHECK_THROW(Point(NULL, NULL, 0, 7), std::runtime_error);
};

// BOOST_AUTO_TEST_CASE(equality_operator)
// {
//     Point p1 = Point(18, 77, 5, 7);
//     Point p2 = Point(18, 77, 5, 7);
//     BOOST_CHECK(p1 == p2);

//     Point p3 = Point(3, 7, 5, 7);
//     Point p4 = Point(3, 7, 5, 7);
//     BOOST_CHECK(p3 == p4);
// };

// BOOST_AUTO_TEST_CASE(not_equal_operator)
// {
//     Point p1 = Point(18, 77, 5, 7);
//     Point p2 = Point(3, 7, 5, 7);
//     BOOST_CHECK(p1 != p2);
// };

// BOOST_AUTO_TEST_CASE(addition_operator)
// {
//     Point p1 = Point(3, 7, 5, 7);
//     Point p2 = Point(-1, -1, 5, 7);
//     Point p3 = p1 + p2;
//     BOOST_CHECK(p3.getX() == 2 && p3.getY() == -5);

//     // point doubling
//     Point p4 = Point(-1, 1, 5, 7);
//     Point p5 = p4 + p4;
//     BOOST_CHECK(p5.getX() == 18 && p5.getY() == -77);
// };

// BOOST_AUTO_TEST_CASE(multiplying_points)
// {
//     int prime = 223;
//     FieldElement a = FieldElement(0, prime);
//     FieldElement b = FieldElement(7, prime);

//     Point p1 = Point(192, 105, a, b);
//     Point p2 = Point(49, 71, a, b);
// }

