#pragma once
#include <utility>
#include "../meta/bool_constant.hpp"
#include "../meta/void_t.hpp"

template<typename T, typename = void>
struct my_is_container : my_false_type {};

template<typename T>
struct my_is_container<T,
        my_void_t<
                decltype(std::declval<const T&>().begin()),
                decltype(std::declval<const T&>().end()),
                typename T::value_type
        >
> : my_true_type {};
