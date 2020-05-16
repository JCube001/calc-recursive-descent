#include "Calc/Calc.hpp"

#include "Evaluator.hpp"
#include "Parser.hpp"
#include <sstream>

namespace Calc {

std::unique_ptr<Ast::Expression> parse(std::istream& stream)
{
    return Parser{stream}();
}

double evaluate(std::istream& stream)
{
    auto expression = parse(stream);

    Evaluator eval;
    expression->accept(eval);

    return eval.getResult();
}

double evaluate(const std::string& code)
{
    std::istringstream stream{code};
    return evaluate(stream);
}

} // namespace Calc
