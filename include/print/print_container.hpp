#pragma once
#include <sstream>
#include <iostream>
#include <iterator>
#include "../meta/enable_if.hpp"
#include "../traits/is_container.hpp"
#include "../traits/is_string.hpp"


/**
 * @brief Print conditional IP address from a container
 *
 * Enabled only for container types (std::vector, std::list, etc.)
 * excluding strings. Prints all elements of the container separated
 * by dots (`.`), preserving element order.
 *
 * @tparam T Container type
 * @param c Container with IP elements
 *
 * @note Container elements are printed as-is.
 * @note String types are explicitly excluded by SFINAE.
 */


template<typename T>
typename my_enable_if<
        my_is_container<T>::value && !my_is_string<T>::value
>::type
print_ip(const T& c)
{
    std::ostringstream ss;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ss << *it;
        if (std::next(it) != c.end())
            ss << '.';
    }
    std::cout << ss.str() << '\n';
}
