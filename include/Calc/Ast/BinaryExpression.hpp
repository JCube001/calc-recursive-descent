#ifndef CALC_AST_BINARY_EXPRESSION_HPP
#define CALC_AST_BINARY_EXPRESSION_HPP

#include <Calc/Ast/Expression.hpp>
#include <memory>
#include <utility>

namespace Calc {
namespace Ast {

struct BinaryExpression : public Expression
{
    BinaryExpression(std::unique_ptr<Expression>&& left = {}, std::unique_ptr<Expression>&& right = {})
        : left{std::move(left)}
        , right{std::move(right)}
    {}

    virtual ~BinaryExpression() = default;
    virtual void accept(Visitor& visitor) override = 0;

    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
};

} // namespace Ast
} // namespace Calc

#endif // CALC_AST_BINARY_EXPRESSION_HPP
