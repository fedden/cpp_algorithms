cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)
project(cpp_algorithms)
include(gtest.cmake)

SET(COVERAGE OFF CACHE BOOL "Coverage")

add_executable(tests test/test_breadth_first_search.cpp)

find_package (Threads)
target_link_libraries(tests gtest ${CMAKE_THREAD_LIBS_INIT})

target_compile_options(tests PRIVATE -std=c++14 -g -Wall -Werror -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)

# If COVERAGE env var set, enable the gcda files generation, needed by lcov in our toolchain.
if (COVERAGE)
  target_compile_options(tests PRIVATE --coverage)
  target_link_libraries(tests PRIVATE --coverage)
endif()
