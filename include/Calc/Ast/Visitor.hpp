#ifndef CALC_AST_VISITOR_HPP
#define CALC_AST_VISITOR_HPP

namespace Calc {
namespace Ast {

struct Number;
struct NegationOperator;
struct AdditionOperator;
struct SubtractionOperator;
struct MultiplicationOperator;
struct DivisionOperator;

struct Visitor
{
    virtual ~Visitor() = default;

    virtual void visit(Number& number) = 0;

    virtual void visit(NegationOperator& negation) = 0;

    virtual void visit(AdditionOperator& addition) = 0;

    virtual void visit(SubtractionOperator& subtraction) = 0;

    virtual void visit(MultiplicationOperator& multiplication) = 0;

    virtual void visit(DivisionOperator& division) = 0;
};

} // namespace Ast
} // namespace Calc

#endif // CALC_AST_VISITOR_HPP
