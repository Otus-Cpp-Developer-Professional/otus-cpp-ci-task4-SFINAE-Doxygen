#pragma once
#include <sstream>
#include <iostream>
#include <type_traits>
#include "../meta/enable_if.hpp"
#include "../traits/is_integral.hpp"

template<typename T>
typename my_enable_if<my_is_integral<T>::value>::type
print_ip(T ip)
{
    using U = std::make_unsigned_t<T>;
    U u = static_cast<U>(ip);

    std::ostringstream ss;
    for (int i = sizeof(T) - 1; i >= 0; --i) {
        ss << ((u >> (i * 8)) & 0xFF);
        if (i) ss << '.';
    }
    std::cout << ss.str() << '\n';
}
