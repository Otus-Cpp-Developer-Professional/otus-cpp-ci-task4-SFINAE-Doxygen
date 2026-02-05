#pragma once
#include <sstream>
#include <iostream>
#include <iterator>
#include "../meta/enable_if.hpp"
#include "../traits/is_container.hpp"
#include "../traits/is_string.hpp"

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
