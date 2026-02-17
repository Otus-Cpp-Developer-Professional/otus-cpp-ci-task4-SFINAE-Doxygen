#pragma once

#include <iostream>
#include <sstream>
#include "../concepts.hpp"

template<StringLike T>
std::string to_string_ip(T ip)
{
    return std::string{ip};
}

template<StringLike T>
void print_ip(T ip)
{
    std::cout << ip << std::endl;
}
