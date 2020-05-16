#include "Calc/Calc.hpp"
#include "catch.hpp"

using namespace Calc;

SCENARIO("The parser shall report invalid expressions", "[calc][syntax][error]") {
    CHECK_THROWS_WITH(evaluate(""), "invalid expression");
    CHECK_THROWS_WITH(evaluate("1 // 2"), "invalid expression");
    CHECK_THROWS_WITH(evaluate("1 + 2 3"), "extra input at end of expression");
    CHECK_THROWS_WITH(evaluate("(1 + 2"), "expected ')'");
    CHECK_THROWS_WITH(evaluate("hey"), "invalid expression");
}
