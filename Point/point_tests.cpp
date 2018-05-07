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

BOOST_AUTO_TEST_CASE(constructor_with_FieldElement)
{
    FieldElement x = FieldElement(18, 1031);
    FieldElement y = FieldElement(77, 1031);
    FieldElement a = FieldElement(5, 1031);
    FieldElement b = FieldElement(7, 1031);

    Point point = Point(x, y, a, b);
    BOOST_CHECK_EQUAL(point.getX().getNum(), 18);
    BOOST_CHECK_EQUAL(point.getX().getPrime(), 1031);
    BOOST_CHECK(point.getX().getNum() < point.getX().getPrime());
};

BOOST_AUTO_TEST_CASE(constructor_with_int)
{
    Point point = Point(18, 77, 5, 7, 1031);
    BOOST_CHECK_EQUAL(point.getX().getNum(), 18);
};

BOOST_AUTO_TEST_CASE(runtime_error_point_not_on_curve)
{
    BOOST_CHECK_THROW(Point(2, 7, 5, 7, 1031), std::runtime_error);

    FieldElement x = FieldElement(2, 1031);
    FieldElement y = FieldElement(7, 1031);
    FieldElement a = FieldElement(5, 1031);
    FieldElement b = FieldElement(7, 1031);

    BOOST_CHECK_THROW(Point(x, y, a, b), std::runtime_error);
};

BOOST_AUTO_TEST_CASE(equality_operator)
{
    Point p1 = Point(18, 77, 5, 7, 1031);
    Point p2 = Point(18, 77, 5, 7, 1031);
    BOOST_CHECK(p1 == p2);

    FieldElement x = FieldElement(18, 1031);
    FieldElement y = FieldElement(77, 1031);
    FieldElement a = FieldElement(5, 1031);
    FieldElement b = FieldElement(7, 1031);

    Point p3 = Point(x, y, a, b);
    Point p4 = Point(x, y, a, b);
    BOOST_CHECK(p3 == p4);
};

BOOST_AUTO_TEST_CASE(not_equal_operator)
{
    Point p1 = Point(18, 77, 5, 7, 1031);
    Point p2 = Point(3, 7, 5, 7, 1031);
    BOOST_CHECK(p1 != p2);
};

BOOST_AUTO_TEST_CASE(addition_operator)
{
    Point p1 = Point(18, 77, 5, 7, 1031);
    Point p2 = Point(-1, -1, 5, 7, 1031);
    Point p3 = p1 + p2;
    BOOST_CHECK(p3.getX().getNum() == 2 && p3.getY().getNum() == -5);

    // point doubling
    // Point p4 = Point(-1, 1, 5, 7);
    // Point p5 = p4 + p4;
    // BOOST_CHECK(p5.getX() == 18 && p5.getY() == -77);
};

// BOOST_AUTO_TEST_CASE(multiplying_points)
// {
//     int prime = 223;code .
//     FieldElement a = FieldElement(0, prime);
//     FieldElement b = FieldElement(7, prime);

//     Point p1 = Point(192, 105, a, b);
//     Point p2 = Point(49, 71, a, b);
// }

