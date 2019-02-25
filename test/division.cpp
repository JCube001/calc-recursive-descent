#include "Calc/Calc.hpp"
#include "catch.hpp"

using namespace Calc;

SCENARIO("The parser shall produce correct division results", "[calc][operator][div]") {
    CHECK(evaluate("0 / 1") == Approx(0));
    CHECK(evaluate("1 / 1") == Approx(1));
    CHECK(evaluate("1 / 2") == Approx(0.5));
    CHECK(evaluate("2 / 1") == Approx(2));
    CHECK(evaluate("2 / 3 / 4") == Approx(0.16666666666666666));
    CHECK(evaluate("(2 / 3) / 4") == Approx(0.16666666666666666));
    CHECK(evaluate("2 / (3 / 4)") == Approx(2.6666666666666665));
    CHECK(evaluate("-1 / 1") == Approx(-1));
    CHECK(evaluate("1 / -1") == Approx(-1));
    CHECK(evaluate("-1 / -1") == Approx(1));
}
