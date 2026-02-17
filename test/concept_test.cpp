#define BOOST_TEST_MODULE concept_tests

/**
 * @brief Unit tests for print_ip library using C++20 concepts
 *
 * This file contains Boost.Test unit tests that verify the correctness
 * of the print_ip / to_string_ip overloads implemented with C++20 concepts
 * for all supported types:
 *  - integral values
 *  - strings
 *  - standard containers
 *
 * The tests focus on pure formatting logic and do not test
 * output to std::cout.
 */

#include <boost/test/included/unit_test.hpp>

#include <string>
#include <string_view>
#include <vector>
#include <list>
#include <tuple>

#include "concepts/print_ip.hpp"

// -------- integral --------

BOOST_AUTO_TEST_CASE(ip_int8)
{
    BOOST_TEST(to_string_ip(int8_t{-1}) == "255");
}

BOOST_AUTO_TEST_CASE(ip_int16)
{
    BOOST_TEST(to_string_ip(int16_t{0}) == "0.0");
}

BOOST_AUTO_TEST_CASE(ip_int32)
{
    BOOST_TEST(to_string_ip(int32_t{2130706433}) == "127.0.0.1");
}

BOOST_AUTO_TEST_CASE(ip_int64)
{
    BOOST_TEST(
            to_string_ip(int64_t{8875824491850138409LL}) ==
            "123.45.67.89.101.112.131.41"
    );
}

BOOST_AUTO_TEST_CASE(ip_unsigned_int)
{
    BOOST_TEST(to_string_ip(unsigned int{0xFFFFFFFF}) == "255.255.255.255");
}

// -------- string --------

BOOST_AUTO_TEST_CASE(ip_string)
{
    BOOST_TEST(
            to_string_ip(std::string{"Hello, World!"}) ==
            "Hello, World!"
    );
}

BOOST_AUTO_TEST_CASE(ip_string_view)
{
    std::string_view sv{"Test String"};
    BOOST_TEST(to_string_ip(sv) == "Test String");
}

// -------- containers --------

BOOST_AUTO_TEST_CASE(ip_vector)
{
    BOOST_TEST(
            to_string_ip(std::vector<int>{100, 200, 300, 400}) ==
            "100.200.300.400"
    );
}

BOOST_AUTO_TEST_CASE(ip_list)
{
    BOOST_TEST(
            to_string_ip(std::list<short>{400, 300, 200, 100}) ==
            "400.300.200.100"
    );
}

BOOST_AUTO_TEST_CASE(ip_vector_empty)
{
    BOOST_TEST(to_string_ip(std::vector<int>{}) == "");
}

BOOST_AUTO_TEST_CASE(ip_list_single_element)
{
    BOOST_TEST(to_string_ip(std::list<int>{42}) == "42");
}

// -------- tuple --------

BOOST_AUTO_TEST_CASE(ip_tuple)
{
    BOOST_TEST(
            to_string_ip(std::make_tuple(123, 456, 789, 0)) ==
            "123.456.789.0"
    );
}

BOOST_AUTO_TEST_CASE(ip_tuple_two_elements)
{
    BOOST_TEST(
            to_string_ip(std::make_tuple(10, 20)) ==
            "10.20"
    );
}

BOOST_AUTO_TEST_CASE(ip_tuple_single_element)
{
    BOOST_TEST(
            to_string_ip(std::make_tuple(42)) ==
            "42"
    );
}
