#include "Calc/Calc.hpp"
#include "catch.hpp"

using namespace Calc;

SCENARIO("The parser shall adhere to the order of operations for arithmetic", "[calc][operator]") {
    CHECK(evaluate("1 + 2 * 3") == Approx(7));
    CHECK(evaluate("(1 + 2) * 3") == Approx(9));
    CHECK(evaluate("(1 + 3 * 5) / 2 - 1") == Approx(7));
    CHECK(evaluate("20 - 4 - 6") == Approx(10));
    CHECK(evaluate("-(4 + 2 ^ 3 ^ 0 * 5 ^ 2) + 7") == Approx(-47));
}
