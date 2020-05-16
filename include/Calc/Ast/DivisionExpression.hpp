#ifndef CALC_AST_DIVISION_EXPRESSION_HPP
#define CALC_AST_DIVISION_EXPRESSION_HPP

#include <Calc/Ast/BinaryExpression.hpp>

namespace Calc {
namespace Ast {

struct DivisionExpression final : public BinaryExpression
{
    DivisionExpression(std::unique_ptr<Expression>&& left = {}, std::unique_ptr<Expression>&& right = {})
        : BinaryExpression{std::move(left), std::move(right)}
    {}

    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }
};

} // namespace Ast
} // namespace Calc

#endif // CALC_AST_DIVISION_EXPRESSION_HPP
