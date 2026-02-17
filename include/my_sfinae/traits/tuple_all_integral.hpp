#pragma once
/**
 * @file tuple_all_integral.hpp
 * @brief Compile-time trait to check that all elements of a std::tuple are integral
 *
 * This header defines a custom type trait that evaluates to `true`
 * if and only if:
 *
 *   1. The given type is a `std::tuple`
 *   2. The tuple is NOT empty
 *   3. All element types of the tuple are integral
 *
 * For any non-tuple type, or for an empty tuple, the trait evaluates to `false`.
 *
 * The implementation intentionally avoids recursion, `std::enable_if`,
 * and `std::tuple_size`-based SFINAE, and instead relies on:
 *
 *   - Partial specialization for `std::tuple`
 *   - Fold expressions (C++17)
 *
 * This makes the trait:
 *   - simpler
 *   - safer
 *   - easier to reason about
 *   - impossible to accidentally apply to non-tuple types
 */

#include <tuple>

#include "../meta/bool_constant.hpp"
#include "is_integral.hpp"

/**
 * @brief Primary template: false for all non-tuple types
 *
 * This is the default case. Any type that is not explicitly specialized
 * below will be treated as "not a tuple of integral types".
 */
template<typename T>
struct my_tuple_all_integral : my_false_type {};

/**
 * @brief Specialization for std::tuple
 *
 * This specialization is selected ONLY when the type is exactly
 * `std::tuple<Ts...>`.
 *
 * The condition checks:
 *   - The tuple is not empty (`sizeof...(Ts) > 0`)
 *   - All element types are integral
 *
 * The fold expression:
 *
 *     (my_is_integral_v<Ts> && ...)
 *
 * expands to:
 *     my_is_integral_v<T1> && my_is_integral_v<T2> && ...
 *
 * For an empty parameter pack, a fold expression would evaluate to `true`
 * (vacuous truth), so we explicitly forbid empty tuples.
 */
template<typename... Ts>
struct my_tuple_all_integral<std::tuple<Ts...>>
        : my_bool_constant<
                (sizeof...(Ts) > 0) &&
                (my_is_integral_v<Ts> && ...)
        >
{};

/**
 * @brief Convenience variable template
 *
 * Allows usage like:
 *
 *     my_tuple_all_integral_v<T>
 *
 * instead of:
 *
 *     my_tuple_all_integral<T>::value
 */
template<typename T>
inline constexpr bool my_tuple_all_integral_v = my_tuple_all_integral<T>::value;
