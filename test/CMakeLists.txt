find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(tests sfinae_test.cpp)

target_link_libraries(tests
        PRIVATE
        sfinae
        Boost::unit_test_framework
        )

target_compile_features(tests PRIVATE cxx_std_20)

if(MSVC)
    target_compile_options(tests PRIVATE /W4)
else()
    target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)
endif()

enable_testing()
add_test(NAME tests COMMAND tests)
