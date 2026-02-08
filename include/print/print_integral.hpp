#pragma once
#include <sstream>
#include <iostream>
#include <type_traits>
#include "../meta/enable_if.hpp"
#include "../traits/is_integral.hpp"
#include "../traits/is_string.hpp"

/**
 * @brief Prints a conditional IP address from an integral value
 *
 * This overload is enabled only for integral types using a custom SFINAE
 * mechanism. The value is interpreted as a sequence of bytes and printed
 * in unsigned form, starting from the most significant byte.
 *
 * Each byte is separated by a dot (`.`), similarly to a traditional
 * IP address representation. The number of printed elements depends
 * on the size of the input type.
 *
 * @tparam T Integral input type
 * @param ip Integral value representing the conditional IP address
 */


template<typename T>
my_enable_if_t<my_is_integral_v<T>  && !my_is_string_v<T>, std::string>
to_string_ip(T ip)
{
    using U = std::make_unsigned_t<T>;
    U u = static_cast<U>(ip);

    std::ostringstream ss;
    for (int i = sizeof(T) - 1; i >= 0; --i) {
        ss << ((u >> (i * 8)) & 0xFF);
        if (i) ss << '.';
    }
    return ss.str();
}

template<typename T>
my_enable_if_t<
        my_is_integral_v<T> && !my_is_string_v<T>, void
> print_ip(const T& c)
{
    std::cout << to_string_ip(c) << '\n';
}
