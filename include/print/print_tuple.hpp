#pragma once
#include <sstream>
#include <iostream>
#include "../meta/enable_if.hpp"
#include "../traits/is_tuple.hpp"
#include "../traits/tuple_all_integral.hpp"
#include "../tuple/tuple_print.hpp"

/**
 * @brief Print conditional IP address from a tuple
 *
 * Enabled only for tuple types whose all element types are integral.
 * The tuple elements are printed in order and separated by dots (`.`).
 *
 * Type validation is performed at compile time using a custom
 * SFINAE-based trait. If the tuple contains non-integral elements,
 * the function is excluded from overload resolution.
 *
 * @tparam T Tuple type with all elements being integral
 * @param t Tuple representing the conditional IP address
 */


template<typename T>
typename my_enable_if<my_tuple_all_integral<T>::value>::type
print_ip(const T& t)
{
    std::ostringstream os;
    append_tuple_dotted<0>(t, os);
    std::cout << os.str() << '\n';
}
