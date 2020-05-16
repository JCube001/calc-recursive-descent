#ifndef CALC_AST_VISITOR_HPP
#define CALC_AST_VISITOR_HPP

namespace Calc {
namespace Ast {

struct NegationExpression;
struct AdditionExpression;
struct SubtractionExpression;
struct MultiplicationExpression;
struct DivisionExpression;
struct ExponentExpression;
struct Number;

struct Visitor
{
    virtual ~Visitor() = default;
    virtual void visit(NegationExpression& expression) = 0;
    virtual void visit(AdditionExpression& expression) = 0;
    virtual void visit(SubtractionExpression& expression) = 0;
    virtual void visit(MultiplicationExpression& expression) = 0;
    virtual void visit(DivisionExpression& expression) = 0;
    virtual void visit(ExponentExpression& expression) = 0;
    virtual void visit(Number& number) = 0;
};

} // namespace Ast
} // namespace Calc

#endif // CALC_AST_VISITOR_HPP
