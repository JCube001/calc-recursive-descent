#include "Calc/Calc.hpp"
#include "catch.hpp"

using namespace Calc;

SCENARIO("The parser shall produce correct subtraction results", "[calc][operator][sub]") {
    CHECK(evaluate("0 - 0") == Approx(0));
    CHECK(evaluate("0 - 1") == Approx(-1));
    CHECK(evaluate("1 - 0") == Approx(1));
    CHECK(evaluate("1 - 1") == Approx(0));
    CHECK(evaluate("1 - 2") == Approx(-1));
    CHECK(evaluate("2 - 1") == Approx(1));
    CHECK(evaluate("4 - 2 - 1") == Approx(1));
    CHECK(evaluate("(4 - 2) - 1") == Approx(1));
    CHECK(evaluate("4 - (2 - 1)") == Approx(3));
    CHECK(evaluate("-1 - 1") == Approx(-2));
    CHECK(evaluate("1 - -1") == Approx(2));
    CHECK(evaluate("-1 - -1") == Approx(0));
}
