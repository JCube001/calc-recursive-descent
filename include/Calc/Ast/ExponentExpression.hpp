#ifndef CALC_AST_EXPONENT_EXPRESSION_HPP
#define CALC_AST_EXPONENT_EXPRESSION_HPP

#include <Calc/Ast/BinaryExpression.hpp>

namespace Calc {
namespace Ast {

struct ExponentExpression final : public BinaryExpression
{
    ExponentExpression(std::unique_ptr<Expression>&& left = {}, std::unique_ptr<Expression>&& right = {})
        : BinaryExpression{std::move(left), std::move(right)}
    {}

    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }
};

} // namespace Ast
} // namespace Calc

#endif // CALC_AST_EXPONENT_EXPRESSION_HPP
