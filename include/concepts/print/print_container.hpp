#pragma once

#include <iostream>
#include <sstream>
#include <iterator>
#include "../concepts.hpp"

template<typename T>
requires Iterable<T> && (!MapLike<T>)
std::string to_string_ip(const T& ip)
{
    std::ostringstream ss;

    for (auto it = ip.begin(); it != ip.end(); ++it) {
        ss << *it;
        if (std::next(it) != ip.end())
            ss << '.';
    }
    return ss.str();
}

template<typename T>
requires Iterable<T> && (!MapLike<T>)
void print_ip(const T& ip)
{
    std::cout << to_string_ip(ip) << std::endl;
}
