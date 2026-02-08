#pragma once
#include <sstream>
#include <iostream>
#include "../meta/enable_if.hpp"
#include "../traits/is_string.hpp"


/**
 * @brief Print conditional IP address from a string
 *
 * Enabled only for string types. The value is printed
 * exactly as provided, without any parsing or validation.
 *
 * @tparam T String type
 * @param s IP address represented as a string
 */


template<typename T>
my_enable_if_t<my_is_string_v<T>, std::string>
to_string_ip(const T& s)
{
    return s;
}

template<typename T>
my_enable_if_t<my_is_string_v<T>, void>
print_ip(const T& s)
{
    std::cout << to_string_ip(s) << '\n';
}
