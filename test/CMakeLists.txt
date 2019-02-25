add_executable(calc-test main.cpp
    addition.cpp
    division.cpp
    multiplication.cpp
    order_of_operations.cpp
    subtraction.cpp
    syntax_error.cpp
)

target_include_directories(calc-test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(calc-test PRIVATE calc)
