#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FieldElement_tests
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "FieldElement.cpp"

BOOST_AUTO_TEST_SUITE(initialize_object_tests)

BOOST_AUTO_TEST_CASE(initialize_fieldelement)
{
    FieldElement fieldElement = FieldElement(10, 31);
    BOOST_CHECK(&fieldElement);
};

BOOST_AUTO_TEST_SUITE_END(); // initialize_object_tests


BOOST_AUTO_TEST_SUITE(arithmetic_operations_tests)

BOOST_AUTO_TEST_CASE(check_for_equality)
{
    FieldElement fe1 = FieldElement(10, 31);
    FieldElement fe2 = FieldElement(10, 31);
    BOOST_CHECK(fe1 == fe2);

    FieldElement fe3 = FieldElement(11, 31);
    FieldElement fe4 = FieldElement(10, 31);
    BOOST_CHECK(fe3 != fe4);

    FieldElement fe5 = FieldElement(11, 31);
    FieldElement fe6 = FieldElement(11, 32);
    BOOST_CHECK(fe5 != fe6);
};

BOOST_AUTO_TEST_CASE(adding_field_elements)
{
    FieldElement fe1 = FieldElement(10, 31);
    FieldElement fe2 = FieldElement(10, 31);

    FieldElement fe3 = fe1 + fe2;
    BOOST_CHECK(fe3.getNum() == 20);

    FieldElement fe4 = FieldElement(10, 31);
    FieldElement fe5 = FieldElement(10, 30);
    BOOST_CHECK_THROW(fe4 + fe5, std::runtime_error);

    FieldElement fe6 = FieldElement(30, 31);
    FieldElement fe7 = FieldElement(10, 31);
    FieldElement fe8 = fe6 + fe7;
    BOOST_CHECK(fe8.getNum() == 9);
    
    FieldElement fe9 = FieldElement(10, 11);
    FieldElement fe10 = FieldElement(9, 11);
    FieldElement fe11 = fe9 + fe10;
    BOOST_CHECK(fe11.getNum() == 8);
    
    FieldElement fe12 = FieldElement(134122345, 100000015333);
    FieldElement fe13 = FieldElement(24523452354, 100000015333);
    FieldElement fe14 = fe12 + fe13;
    BOOST_CHECK(fe14.getNum() == 24657574699);
};

BOOST_AUTO_TEST_CASE(number_not_within_field_error)
{
    BOOST_CHECK_THROW(FieldElement(50, 31), std::runtime_error);
    BOOST_CHECK_THROW(FieldElement(-1, 31), std::runtime_error);
};

BOOST_AUTO_TEST_CASE(multiply_field_elements)
{
    FieldElement fe1 = FieldElement(10, 31);
    FieldElement fe2 = FieldElement(3, 31);

    FieldElement fe3 = fe1 * fe2;
    BOOST_CHECK(fe3.getNum() == 30);

    FieldElement fe4 = FieldElement(30, 31);
    FieldElement fe5 = FieldElement(2, 31);
    FieldElement fe6 = fe4 * fe5;
    BOOST_CHECK(fe6.getNum() == 29);

    FieldElement fe7 = FieldElement(30, 31);
    FieldElement fe8 = FieldElement(19, 31);
    FieldElement fe9 = fe7 * fe8;
    BOOST_CHECK(fe9.getNum() == 12);

    FieldElement fe10 = FieldElement(134122345, 100000015333);
    FieldElement fe11 = FieldElement(24523452354, 100000015333);
    FieldElement fe12 = fe10 * fe11;
    BOOST_CHECK(fe12.getNum() == 32890045938);
};

BOOST_AUTO_TEST_CASE(powers_of_field_element)
{
    FieldElement fe1 = FieldElement(9, 11);
    FieldElement fe2 = fe1.pow(2);
    BOOST_CHECK(fe2.getNum() == 4);

    FieldElement fe3 = FieldElement(5, 7);
    FieldElement fe4 = fe3.pow(9);
    BOOST_CHECK(fe4.getNum() == 6);

    FieldElement fe5 = FieldElement(2, 5);
    FieldElement fe6 = fe5.pow(12);
    BOOST_CHECK(fe6.getNum() == 1);

    FieldElement fe7 = FieldElement(13, 100000015333);
    FieldElement fe8 = fe7.pow(77);
    BOOST_CHECK(fe8.getNum() == 68341735965);
};

BOOST_AUTO_TEST_CASE(division)
{
    FieldElement p1 = FieldElement(2, 11);
    FieldElement p2 = FieldElement(3, 11);

    FieldElement p3 = p1 / p2;
    BOOST_CHECK(p3.getNum() == 8);

    FieldElement p4 = FieldElement(6, 7);
    FieldElement p5 = FieldElement(4, 7);

    FieldElement p6 = p4 / p5;
    BOOST_CHECK(p6.getNum() == 5);
};

BOOST_AUTO_TEST_SUITE_END() // arithmetic_operations_tests
