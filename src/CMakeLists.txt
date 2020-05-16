set(CALC_KEYSEQ_QUIT "Ctrl+C" CACHE STRING "The key sequence used to quit the calc application")
if(WIN32)
    set(CALC_KEYSEQ_QUIT "Ctrl+Z")
elseif(UNIX)
    set(CALC_KEYSEQ_QUIT "Ctrl+D")
endif()

configure_file(config.hpp.in config.hpp @ONLY)

add_library(calc STATIC Calc.cpp Evaluator.cpp Lexer.cpp Parser.cpp)
target_compile_features(calc PUBLIC cxx_std_17)

target_include_directories(calc
PUBLIC
    $<BUILD_INTERFACE:${calc_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(app main.cpp)
target_link_libraries(app PRIVATE calc)
target_include_directories(app PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(app PROPERTIES OUTPUT_NAME calc)
