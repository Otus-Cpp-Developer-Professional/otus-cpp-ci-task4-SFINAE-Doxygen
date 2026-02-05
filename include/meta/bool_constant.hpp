#pragma once

template<bool b>
struct my_bool_constant {
    static constexpr bool value = b;
};

using my_true_type  = my_bool_constant<true>;
using my_false_type = my_bool_constant<false>;
