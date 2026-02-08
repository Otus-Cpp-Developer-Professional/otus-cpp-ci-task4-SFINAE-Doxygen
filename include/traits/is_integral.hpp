#pragma once
#include "../meta/bool_constant.hpp"

template<typename T>
struct my_is_integral : my_false_type {};

template<> struct my_is_integral<char> : my_true_type {};
template<> struct my_is_integral<bool> : my_true_type {};
template<> struct my_is_integral<unsigned char> : my_true_type {};
template<> struct my_is_integral<signed char> : my_true_type {};
template<> struct my_is_integral<unsigned short > : my_true_type {};
template<> struct my_is_integral<short > : my_true_type {};
template<> struct my_is_integral<int> : my_true_type {};
template<> struct my_is_integral<unsigned int> : my_true_type {};
template<> struct my_is_integral<long> : my_true_type {};
template<> struct my_is_integral<unsigned long> : my_true_type {};
template<> struct my_is_integral<long long> : my_true_type {};
template<> struct my_is_integral<unsigned long long> : my_true_type {};

template<typename T>
inline constexpr bool my_is_integral_v = my_is_integral<T>::value;
