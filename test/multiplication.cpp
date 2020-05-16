#include "Calc/Calc.hpp"
#include "catch.hpp"

using namespace Calc;

SCENARIO("The evaluator shall produce correct multiplication results", "[calc][op][mul]") {
    CHECK(evaluate("0 * 0") == Approx(0));
    CHECK(evaluate("0 * 1") == Approx(0));
    CHECK(evaluate("1 * 0") == Approx(0));
    CHECK(evaluate("1 * 1") == Approx(1));
    CHECK(evaluate("1 * 2") == Approx(2));
    CHECK(evaluate("2 * 1") == Approx(2));
    CHECK(evaluate("2 * 3 * 4") == Approx(24));
    CHECK(evaluate("(2 * 3) * 4") == Approx(24));
    CHECK(evaluate("2 * (3 * 4)") == Approx(24));
    CHECK(evaluate("-1 * 1") == Approx(-1));
    CHECK(evaluate("1 * -1") == Approx(-1));
    CHECK(evaluate("-1 * -1") == Approx(1));
}
