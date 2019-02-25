#include "Calc/Calc.hpp"
#include "catch.hpp"

using namespace Calc;

SCENARIO("The parser shall produce correct addition results", "[calc][operator][add]") {
    CHECK(evaluate("0 + 0") == Approx(0));
    CHECK(evaluate("0 + 1") == Approx(1));
    CHECK(evaluate("1 + 0") == Approx(1));
    CHECK(evaluate("1 + 1") == Approx(2));
    CHECK(evaluate("1 + 2") == Approx(3));
    CHECK(evaluate("2 + 1") == Approx(3));
    CHECK(evaluate("1 + 2 + 3") == Approx(6));
    CHECK(evaluate("(1 + 2) + 3") == Approx(6));
    CHECK(evaluate("1 + (2 + 3)") == Approx(6));
    CHECK(evaluate("-1 + 1") == Approx(0));
    CHECK(evaluate("1 + -1") == Approx(0));
    CHECK(evaluate("-1 + -1") == Approx(-2));
}
