#include "Calc/Calc.hpp"
#include "catch.hpp"

using namespace Calc;

SCENARIO("The evaluator shall produce correct power results", "[calc][op][pow]") {
    CHECK(evaluate("1 ^ 0") == Approx(1));
    CHECK(evaluate("1 ^ 1") == Approx(1));
    CHECK(evaluate("1 ^ 2") == Approx(1));
    CHECK(evaluate("2 ^ 0") == Approx(1));
    CHECK(evaluate("2 ^ 1") == Approx(2));
    CHECK(evaluate("2 ^ 2") == Approx(4));
    CHECK(evaluate("2 ^ 3") == Approx(8));
    CHECK(evaluate("3 ^ 2") == Approx(9));
    CHECK(evaluate("2 ^ 3 ^ 2") == Approx(512));
    CHECK(evaluate("(2 ^ 3) ^ 2") == Approx(64));
    CHECK(evaluate("2 ^ (3 ^ 2)") == Approx(512));
    CHECK(evaluate("2 ^ -1") == Approx(0.5));
    CHECK(evaluate("-2 ^ 1") == Approx(-2));
}
