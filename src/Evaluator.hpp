#ifndef CALC_EVALUATOR_HPP
#define CALC_EVALUATOR_HPP

#include "Calc/Ast/Ast.hpp"
#include <stack>

namespace Calc {

class Evaluator final : public Ast::Visitor
{
public:
    double getResult() const;
    void visit(Ast::NegationExpression& expression) override;
    void visit(Ast::AdditionExpression& expression) override;
    void visit(Ast::SubtractionExpression& expression) override;
    void visit(Ast::MultiplicationExpression& expression) override;
    void visit(Ast::DivisionExpression& expression) override;
    void visit(Ast::ExponentExpression& expression) override;
    void visit(Ast::Number& number) override;

private:
    std::stack<double> stack;
};

} // namespace Calc

#endif // CALC_EVALUATOR_HPP
