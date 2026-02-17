#pragma once

template<bool, typename T = void>
struct my_enable_if {};

template<typename T>
struct my_enable_if<true, T> {
    using type = T;
};

template<bool b, typename T>
using my_enable_if_t = typename my_enable_if<b, T>::type;
