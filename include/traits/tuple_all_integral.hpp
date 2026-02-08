#pragma once
/**
 * @file tuple_all_integral.hpp
 * @brief Compile-time trait to check that all tuple elements are integral
 *
 * Provides a custom type trait that evaluates to true if and only if
 * all element types of a given std::tuple are integral.
 *
 * The implementation is based on recursive template instantiation and
 * SFINAE techniques and is intentionally written without using standard
 * library type traits for educational purposes.
 */

#include <tuple>
#include <type_traits>
#include "../meta/bool_constant.hpp"
#include "../meta/void_t.hpp"
#include "is_integral.hpp"

/**
 * @brief Recursive helper to check tuple element types
 *
 * Iterates over tuple elements at compile time and verifies that each
 * element type is integral.
 *
 * @tparam Tuple Tuple type being checked
 * @tparam I Current element index
 */

template<typename Tuple, std::size_t I, typename = void>
struct tuple_all_integral_impl;

/**
 * @brief Terminal case for tuple recursion
 *
 * Reached when the index equals the tuple size.
 * Indicates that all previous element types were integral.
 */

template<typename Tuple, std::size_t I>
struct tuple_all_integral_impl<
        Tuple, I,
        std::enable_if_t<I == std::tuple_size_v<Tuple>>
> : my_true_type {};

/**
 * @brief Recursive case for tuple element checking
 *
 * Checks whether the current element type is integral and continues
 * recursion with the next tuple index.
 */

template<typename Tuple, std::size_t I>
struct tuple_all_integral_impl<
        Tuple, I,
        std::enable_if_t<(I < std::tuple_size_v<Tuple>)>
> : my_bool_constant<
        my_is_integral<std::tuple_element_t<I, Tuple>>::value &&
        tuple_all_integral_impl<Tuple, I + 1>::value
> {};

/**
 * @brief Trait to determine whether all tuple element types are integral
 *
 * Evaluates to my_true_type if the given type is a std::tuple and all
 * its element types are integral. Otherwise evaluates to my_false_type.
 *
 * @tparam T Type to be checked
 */

template<typename T, typename = void>
struct my_tuple_all_integral : my_false_type {};

/**
 * @brief Specialization enabled for tuple types
 *
 * Uses detection of std::tuple_size to ensure that the type is a tuple,
 * then delegates the check to the recursive implementation.
 */

template<typename T>
struct my_tuple_all_integral<
        T,
        my_void_t<decltype(std::tuple_size<T>::value)>
> : tuple_all_integral_impl<T, 0> {};
