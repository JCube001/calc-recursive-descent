#include "Evaluator.hpp"

#include <cmath>

namespace Calc {

double Evaluator::getResult() const
{
    return stack.top();
}

void Evaluator::visit(Ast::NegationExpression& expression)
{
    expression.right->accept(*this);
    stack.top() = -stack.top();
}

void Evaluator::visit(Ast::AdditionExpression& expression)
{
    expression.left->accept(*this);
    expression.right->accept(*this);

    const auto right = stack.top();
    stack.pop();
    stack.top() += right;
}

void Evaluator::visit(Ast::SubtractionExpression& expression)
{
    expression.left->accept(*this);
    expression.right->accept(*this);

    const auto right = stack.top();
    stack.pop();
    stack.top() -= right;
}

void Evaluator::visit(Ast::MultiplicationExpression& expression)
{
    expression.left->accept(*this);
    expression.right->accept(*this);

    const auto right = stack.top();
    stack.pop();
    stack.top() *= right;
}

void Evaluator::visit(Ast::DivisionExpression& expression)
{
    expression.left->accept(*this);
    expression.right->accept(*this);

    const auto right = stack.top();
    stack.pop();
    stack.top() /= right;
}

void Evaluator::visit(Ast::ExponentExpression& expression)
{
    expression.left->accept(*this);
    expression.right->accept(*this);

    const auto exponent = stack.top();
    stack.pop();

    const auto base = stack.top();
    stack.pop();

    stack.push(std::pow(base, exponent));
}

void Evaluator::visit(Ast::Number& number)
{
    stack.push(number.value);
}

} // namespace Calc
