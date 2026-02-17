#pragma once

#include <concepts>
#include <iostream>
#include <sstream>
#include <type_traits>

template<std::integral T>
std::string to_string_ip(T ip)
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

template<std::integral T>
void print_ip(T ip)
{
    std::cout << to_string_ip(ip) << std::endl;
}
