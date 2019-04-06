#include "Calc/Calc.hpp"
#include "Parser.hpp"
#include "Solver.hpp"
#include <stdexcept>

namespace Calc {

std::unique_ptr<Ast::Expression> parse(std::string_view text)
{
    return Parser(text)();
}

double evaluate(std::string_view text)
{
    Solver solver;

    auto ast = parse(text);
    if (!ast) {
        throw std::runtime_error("Missing expression");
    }

    ast->accept(solver);
    return solver.getResult();
}

} // namespace Calc
