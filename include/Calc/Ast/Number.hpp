#ifndef CALC_AST_NUMBER_HPP
#define CALC_AST_NUMBER_HPP

#include <Calc/Ast/Expression.hpp>
#include <Calc/Ast/Visitor.hpp>

namespace Calc {
namespace Ast {

struct Number final : public Expression
{
    Number(const double value)
        : value(value)
    {}

    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }

    double value;
};

} // namespace Ast
} // namespace Calc

#endif // CALC_AST_NUMBER_HPP
