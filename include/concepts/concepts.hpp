#pragma once

#include <concepts>
#include <ranges>
#include <string>
#include <string_view>
#include <tuple>

template<typename T>
concept StringLike =
    std::same_as<std::decay_t<T>, std::string> ||
    std::same_as<std::decay_t<T>, std::string_view>;

template<typename T>
concept Iterable =
    std::ranges::input_range<T> && !StringLike<T>;

template<typename T>
concept MapLike =
    std::ranges::input_range<T> &&
    requires {
        typename std::ranges::range_value_t<T>::first_type;
        typename std::ranges::range_value_t<T>::second_type;
    };

template<typename T>
concept TupleLike =
    requires {
        typename std::tuple_size<std::remove_reference_t<T>>::type;
    };
