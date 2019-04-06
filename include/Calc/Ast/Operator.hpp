#ifndef CALC_AST_OPERATOR_HPP
#define CALC_AST_OPERATOR_HPP

#include <Calc/Ast/Expression.hpp>
#include <Calc/Ast/Visitor.hpp>
#include <memory>

namespace Calc {
namespace Ast {

struct Operator : public Expression
{
    virtual ~Operator() = default;

    virtual void accept(Visitor& visitor) override = 0;
};

struct UnaryOperator : public Operator
{
    virtual ~UnaryOperator() = default;

    virtual void accept(Visitor& visitor) override = 0;

    std::unique_ptr<Expression> right;
};

struct NegationOperator final : public UnaryOperator
{
    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }
};

struct BinaryOperator : public Operator
{
    virtual ~BinaryOperator() = default;

    virtual void accept(Visitor& visitor) override = 0;

    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
};

struct AdditionOperator final : public BinaryOperator
{
    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }
};

struct SubtractionOperator final : public BinaryOperator
{
    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }
};

struct MultiplicationOperator final : public BinaryOperator
{
    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }
};

struct DivisionOperator final : public BinaryOperator
{
    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }
};

struct PowerOperator final : public BinaryOperator
{
    void accept(Visitor& visitor) override
    {
        visitor.visit(*this);
    }
};

} // namespace Ast
} // namespace Calc

#endif // CALC_AST_OPERATOR_HPP
