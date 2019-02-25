# Calc

A recursive descent parser implementation of a simple arithmetic expression language. Includes a library and interpreter components. I made this simply to practice writing a lexer and parser. An EBNF definition of the grammar used is available in the `doc` directory.

## Build

To build this project you'll need CMake, a C++17 or later compiler, and [re2c](http://re2c.org/). The CMake scripts will take care of the entire build. To get started, run commands similar to those below, replacing variables with your own choices.

```sh
cd $CALC_PROJECT_ROOT
mkdir build && cd build
cmake -G "$GENERATOR" ..
cmake --build .
```
