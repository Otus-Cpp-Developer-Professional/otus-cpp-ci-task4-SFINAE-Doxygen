add_executable(sfinae_cli main.cpp)

target_link_libraries(sfinae_cli PRIVATE sfinae)

target_compile_features(sfinae_cli PRIVATE cxx_std_20)

if(MSVC)
    target_compile_options(sfinae_cli PRIVATE /W4)
else()
    target_compile_options(sfinae_cli PRIVATE -Wall -Wextra -Wpedantic)
endif()
