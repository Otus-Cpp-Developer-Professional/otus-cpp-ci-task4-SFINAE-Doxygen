find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(tests_sfinae sfinae_test.cpp)

target_link_libraries(tests_sfinae
        PRIVATE
        sfinae
        Boost::unit_test_framework
        )

target_compile_features(tests_sfinae PRIVATE cxx_std_20)

if(MSVC)
    target_compile_options(tests_sfinae PRIVATE /W4)
else()
    target_compile_options(tests_sfinae PRIVATE -Wall -Wextra -Wpedantic)
endif()
