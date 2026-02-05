#pragma once
#include <sstream>
#include <iostream>
#include "../meta/enable_if.hpp"
#include "../traits/is_string.hpp"

template<typename T>
typename my_enable_if<my_is_string<T>::value>::type
print_ip(const T& s)
{
    std::cout << s << '\n';
}
