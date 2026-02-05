#pragma once

#include <tuple>
#include <type_traits>
#include "../meta/bool_constant.hpp"
#include "../meta/void_t.hpp"
#include "is_integral.hpp"

template<typename Tuple, std::size_t I, typename = void>
struct tuple_all_integral_impl;


template<typename Tuple, std::size_t I>
struct tuple_all_integral_impl<
        Tuple, I,
        std::enable_if_t<I == std::tuple_size_v<Tuple>>
> : my_true_type {};


template<typename Tuple, std::size_t I>
struct tuple_all_integral_impl<
        Tuple, I,
        std::enable_if_t<(I < std::tuple_size_v<Tuple>)>
> : my_bool_constant<
        my_is_integral<std::tuple_element_t<I, Tuple>>::value &&
        tuple_all_integral_impl<Tuple, I + 1>::value
> {};

template<typename T, typename = void>
struct my_tuple_all_integral : my_false_type {};

template<typename T>
struct my_tuple_all_integral<
        T,
        my_void_t<decltype(std::tuple_size<T>::value)>
> : tuple_all_integral_impl<T, 0> {};
