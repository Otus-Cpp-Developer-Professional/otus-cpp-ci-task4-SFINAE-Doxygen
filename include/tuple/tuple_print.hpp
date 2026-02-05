#pragma once

/**
 * @file tuple_print.hpp
 * @brief Helper for printing tuple elements separated by dots
 *
 * Provides a recursive compile-time function to append tuple elements
 * to an output stream, separating them with a dot (`.`).
 *
 * The implementation uses `if constexpr` to terminate recursion at
 * compile time and avoids runtime branching.
 */


#include <tuple>
#include <sstream>

/**
 * @brief Append tuple elements to stream separated by dots
 *
 * Recursively processes tuple elements starting from index `I` and
 * appends them to the given output stream. A dot (`.`) is inserted
 * between elements.
 *
 * Recursion is resolved entirely at compile time using `if constexpr`
 * and template instantiation.
 *
 * @tparam I Current tuple index
 * @tparam Tuple Tuple type
 * @param t Tuple whose elements are appended
 * @param out Output stream to append the elements to
 */
template<std::size_t I, typename Tuple>
void append_tuple_dotted(const Tuple& t, std::ostringstream& out)
{
    if constexpr (I < std::tuple_size_v<Tuple>)
    {
        out << std::get<I>(t);

        if constexpr (I + 1 < std::tuple_size_v<Tuple>)
            out << '.';

        append_tuple_dotted<I + 1>(t, out);
    }
}
