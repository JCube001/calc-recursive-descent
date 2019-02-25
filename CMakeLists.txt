cmake_minimum_required(VERSION 3.10)
project(calc VERSION 1.0.0 LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(NAME calc-test COMMAND calc-test)
