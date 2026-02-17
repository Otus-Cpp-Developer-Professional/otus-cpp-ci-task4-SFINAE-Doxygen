#pragma once

#include <iostream>
#include <sstream>
#include <tuple>
#include <concepts>
#include <utility>
#include "../concepts.hpp"

template<typename T>
concept NonEmptyTuple =
TupleLike<T> &&
(std::tuple_size_v<std::remove_reference_t<T>> > 0);


template<typename T>
concept TupleAllIntegral =
NonEmptyTuple<T> &&
[]<std::size_t... I>(std::index_sequence<I...>)
{
    return (std::integral<
            std::tuple_element_t<I, std::remove_reference_t<T>>
    > && ...);
}(std::make_index_sequence<
        std::tuple_size_v<std::remove_reference_t<T>>
>{});




template<TupleLike T, std::size_t... I>
std::string to_string_ip_impl(const T& t, std::index_sequence<I...>)
{
    std::ostringstream ss;
    ((ss << (I == 0 ? "" : ".") << std::get<I>(t)), ...);
    return ss.str();
}

template<TupleLike T>
requires (TupleAllIntegral<T>)
std::string to_string_ip(const T& t)
{
    constexpr std::size_t N = std::tuple_size_v<std::remove_reference_t<T>>;
    return to_string_ip_impl(t, std::make_index_sequence<N>{});
}

template<TupleLike T, std::size_t... I>
void print_tuple_impl(const T& t, std::index_sequence<I...>)
{
    ((std::cout << (I == 0 ? "" : ".") << std::get<I>(t)), ...);
    std::cout << '\n';
}

template<TupleLike T>
requires (TupleAllIntegral<T>)
void print_ip(const T& t)
{
    constexpr std::size_t N = std::tuple_size_v<std::remove_reference_t<T>>;
    print_tuple_impl(t, std::make_index_sequence<N>{});
}
