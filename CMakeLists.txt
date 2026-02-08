cmake_minimum_required(VERSION 3.14)

set(CPACK_PACKAGE_NAME "sfinae")
set(CPACK_PACKAGE_VENDOR "OTUS")
set(CPACK_PACKAGE_CONTACT "sagge14@yandex.ru")

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "OTUS")

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")

project(sfinae VERSION 0.0.${PATCH_VERSION} LANGUAGES CXX)

configure_file(version.h.in version.h)

option(WITH_BOOST_TEST "Build tests" ON)

add_library(sfinae INTERFACE)

target_include_directories(sfinae INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

target_compile_features(sfinae INTERFACE cxx_std_20)

add_subdirectory(src)

if(WITH_BOOST_TEST)
    add_subdirectory(test)
endif()

include(CPack)
