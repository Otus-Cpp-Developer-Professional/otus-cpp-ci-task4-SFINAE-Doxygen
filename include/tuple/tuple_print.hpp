#pragma once

/**
 * @file tuple_print.hpp
 * @brief Helper for printing tuple-like objects separated by dots.
 *
 * Provides a recursive compile-time implementation that appends
 * tuple elements to an output stream separated by '.'.
 *
 * Recursion termination is achieved via SFINAE and template
 * instantiation based on std::tuple_size.
 */



#include <tuple>
#include <sstream>

/**
 * @brief Appends tuple elements to the stream separated by dots.
 *
 * Recursively processes tuple elements starting from index I and
 * appends them to the given output stream. A dot ('.') is inserted
 * between elements.
 *
 * Recursion is controlled at compile time using SFINAE and
 * std::tuple_size.
 *
 * @tparam I Current tuple index.
 * @tparam Tuple Tuple-like type (supports std::tuple_size and std::get).
 * @param t Tuple whose elements are appended.
 * @param out Output stream.
 */


template<std::size_t I, typename Tuple>
my_enable_if_t<I + 1 == std::tuple_size_v<Tuple>, void>
append_tuple_dotted(const Tuple& t, std::ostringstream& out)
{
    out << std::get<I>(t);
}

template<std::size_t I, typename Tuple>
my_enable_if_t<I + 1 < std::tuple_size_v<Tuple>, void>
append_tuple_dotted(const Tuple& t, std::ostringstream& out)
{
    out << std::get<I>(t);

    if (I + 1 < std::tuple_size_v<Tuple>)
        out << '.';

    append_tuple_dotted<I + 1>(t, out);
}


