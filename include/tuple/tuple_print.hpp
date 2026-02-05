#pragma once
#include <tuple>
#include <sstream>

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
