#pragma once

template<bool, typename T = void>
struct my_enable_if {};

template<typename T>
struct my_enable_if<true, T> {
    using type = T;
};
