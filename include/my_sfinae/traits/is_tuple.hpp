#pragma once
#include <tuple>
#include "../meta/bool_constant.hpp"
#include "../meta/void_t.hpp"

template<typename T, typename = void>
struct my_is_tuple : my_false_type {};

template<typename T>
struct my_is_tuple<T,
        my_void_t<decltype(std::tuple_size<T>::value)>
> : my_true_type {};

template<typename T>
inline constexpr bool my_is_tuple_v = my_is_tuple<T>::value;
