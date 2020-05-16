#ifndef CALC_AST_UNARY_EXPRESSION_HPP
#define CALC_AST_UNARY_EXPRESSION_HPP

#include <Calc/Ast/Expression.hpp>
#include <memory>

namespace Calc {
namespace Ast {

struct UnaryExpression : public Expression
{
    UnaryExpression(std::unique_ptr<Expression>&& right = {})
        : right{std::move(right)}
    {}

    virtual ~UnaryExpression() = default;
    virtual void accept(Visitor& visitor) override = 0;

    std::unique_ptr<Expression> right;
};

} // namespace Ast
} // namespace Calc

#endif // CALC_AST_UNARY_EXPRESSION_HPP
