#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Point_tests

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "Point.cpp"
#include "../FieldElement/FieldElement.cpp"

BOOST_AUTO_TEST_SUITE(initialize_object_tests)

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

BOOST_AUTO_TEST_SUITE_END(); // initialize_object_tests

BOOST_AUTO_TEST_SUITE(run_time_error_initalization_tests)

BOOST_AUTO_TEST_CASE(runtime_error_point_not_on_curve)
{
    BOOST_CHECK_THROW(Point(2, 7, 5, 7, 1031), std::runtime_error);

    FieldElement x = FieldElement(2, 1031);
    FieldElement y = FieldElement(7, 1031);
    FieldElement a = FieldElement(5, 1031);
    FieldElement b = FieldElement(7, 1031);

    BOOST_CHECK_THROW(Point(x, y, a, b), std::runtime_error);
};

BOOST_AUTO_TEST_SUITE_END(); // run_time_error_initalization_tests

BOOST_AUTO_TEST_SUITE(arithmetic_operations_tests)

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
    mp::cpp_int a = 0;
    mp::cpp_int b = 7;
    mp::cpp_int prime = 223;

    Point p1 = Point(192, 105, a, b, prime);
    Point p2 = Point(49, 71, a, b, prime);
    Point p3 = p1 + p2;
    BOOST_CHECK_EQUAL(p3.getX().getNum(), 18);
    BOOST_CHECK_EQUAL(p3.getY().getNum(), 189);

    // Point Doubling
    Point p4 = Point(192, 105, a, b, prime);
    Point p5 = p4.pointDoubling();
    BOOST_CHECK_EQUAL(p5.getX().getNum(), 49);
    BOOST_CHECK_EQUAL(p5.getY().getNum(), 71);

    Point p6 = Point(192, 105, a, b, prime);
    Point p7 = p6 + p6;
    BOOST_CHECK_EQUAL(p7.getX().getNum(), 49);
    BOOST_CHECK_EQUAL(p7.getY().getNum(), 71);

    Point p8 = Point(143, 98, a, b, prime);
    Point p9 = p8 + p8;
    BOOST_CHECK_EQUAL(p9.getX().getNum(), 64);
    BOOST_CHECK_EQUAL(p9.getY().getNum(), 168);
};

BOOST_AUTO_TEST_CASE(multiplying_points)
{
    mp::cpp_int a = 0;
    mp::cpp_int b = 7;
    mp::cpp_int prime = 223;

    Point p1 = Point(192, 105,  a, b, prime);
    Point expected = Point(49, 71,  a, b, prime);

    Point p2 = p1.rmul(2);
    BOOST_CHECK_EQUAL(p2.getX().getNum(), 49);

    Point p3 = Point(143, 98, a, b, prime);
    Point p4 = p3.rmul(2);
    BOOST_CHECK_EQUAL(p4.getX().getNum(), 64);
    BOOST_CHECK_EQUAL(p4.getY().getNum(), 168);

    Point p5 = Point(47, 71, a, b, prime);
    Point p6 = p5.rmul(2);
    BOOST_CHECK_EQUAL(p6.getX().getNum(), 36);
    BOOST_CHECK_EQUAL(p6.getY().getNum(), 111);

    Point p7 = Point(47, 71, a, b, prime);
    Point p8 = p7.rmul(4);
    BOOST_CHECK_EQUAL(p8.getX().getNum(), 194);
    BOOST_CHECK_EQUAL(p8.getY().getNum(), 51);

    Point p9 = Point(47, 71, a, b, prime);
    Point p10 = p9.rmul(8);
    BOOST_CHECK_EQUAL(p10.getX().getNum(), 116);
    BOOST_CHECK_EQUAL(p10.getY().getNum(), 55);
    // (21, 47, 71, None, None),
}

BOOST_AUTO_TEST_SUITE_END(); // arithmetic_operations_tests
