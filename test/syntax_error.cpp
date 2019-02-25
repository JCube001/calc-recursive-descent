#include "Calc/Calc.hpp"
#include "catch.hpp"

using namespace Catch::Matchers;
using namespace Calc;

SCENARIO("The parser shall report invalid expressions", "[calc][syntax][error]") {
    CHECK_THROWS_WITH(evaluate(""), "Invalid expression");
    CHECK_THROWS_WITH(evaluate("1 // 2"), "Invalid expression");
    CHECK_THROWS_WITH(evaluate("1 + 2 3"), "Junk at end of expression");
    CHECK_THROWS_WITH(evaluate("(1 + 2"), "Expected closing ')'");
    CHECK_THROWS_WITH(evaluate("hey"), Contains("Stray") && Contains("detected"));
}
