#ifndef CALC_AST_NEGATION_EXPRESSION_HPP
#define CALC_AST_NEGATION_EXPRESSION_HPP

#include <Calc/Ast/UnaryExpression.hpp>

namespace Calc {
namespace Ast {

struct NegationExpression final : public UnaryExpression
{
    NegationExpression(std::unique_ptr<Expression>&& right = {})
        : UnaryExpression{std::move(right)}
    {}

    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }
};

} // namespace Ast
} // namespace Calc

#endif // CALC_AST_NEGATION_EXPRESSION_HPP
