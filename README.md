## Task 4 Conditional IP Printer

This project implements a function for printing a conditional IP address using template overloading and SFINAE.

Supported input types:

integral types (printed byte-wise, from most significant byte)

strings (printed as-is)

std::vector and std::list (elements separated by .)

(optional) std::tuple with identical element types (checked at compile time)

All type traits, overload resolution logic, and SFINAE mechanisms are implemented manually for educational purposes.
The standard library type traits and helpers were intentionally not used to better understand how these mechanisms work internally.

The project also includes Doxygen integration for documentation generation.
