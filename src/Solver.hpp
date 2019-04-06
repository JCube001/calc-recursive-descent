#ifndef CALC_SOLVER_HPP
#define CALC_SOLVER_HPP

#include <Calc/Ast/Ast.hpp>
#include <functional>
#include <stack>
#include <vector>
#include <cmath>

namespace Calc {

class Solver final : public Ast::Visitor
{
public:
    double getResult()
    {
        return values.top();
    }

    void visit(Ast::Number& number) override
    {
        values.push(number.value);
    }

    void visit(Ast::NegationOperator& negation) override
    {
        negation.right->accept(*this);
        values.top() = -values.top();
    }

    void visit(Ast::AdditionOperator& addition) override
    {
        solve(addition, std::plus<double>());
    }

    void visit(Ast::SubtractionOperator& subtraction) override
    {
        solve(subtraction, std::minus<double>());
    }

    void visit(Ast::MultiplicationOperator& multiplication) override
    {
        solve(multiplication, std::multiplies<double>());
    }

    void visit(Ast::DivisionOperator& division) override
    {
        solve(division, std::divides<double>());
    }

    void visit(Ast::PowerOperator& power) override
    {
        solve(power, [](const double base, const double exponent) {
            return std::pow(base, exponent);
        });
    }

private:
    template<class T>
    using Stack = std::stack<T, std::vector<T>>;

    template<class Functor>
    void solve(Ast::BinaryOperator& op, Functor f)
    {
        op.left->accept(*this);
        op.right->accept(*this);
        const auto operand = values.top();
        values.pop();
        values.top() = f(values.top(), operand);
    }

    Stack<double> values;
};

} // namespace Calc

#endif // CALC_SOLVER_HPP
