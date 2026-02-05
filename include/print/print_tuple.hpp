#pragma once
#include <sstream>
#include <iostream>
#include "../meta/enable_if.hpp"
#include "../traits/is_tuple.hpp"
#include "../traits/tuple_all_integral.hpp"
#include "../tuple/tuple_print.hpp"

template<typename T>
typename my_enable_if<my_tuple_all_integral<T>::value>::type
print_ip(const T& t)
{
    std::ostringstream ss;
    append_tuple_dotted<0>(t, ss);
    std::cout << ss.str() << '\n';
}
