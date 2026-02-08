#pragma once
#include <string>
#include "../meta/bool_constant.hpp"

template<typename T>
struct my_is_string : my_false_type {};

template<>
struct my_is_string<std::string> : my_true_type {};

template<typename T>
inline constexpr bool my_is_string_v = my_is_string<T>::value;
