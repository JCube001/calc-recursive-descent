#ifndef CALC_AST_EXPRESSION_HPP
#define CALC_AST_EXPRESSION_HPP

namespace Calc {
namespace Ast {

struct Visitor;

struct Expression
{
    virtual ~Expression() = default;

    virtual void accept(Visitor& visitor) = 0;
};

} // namespace Ast
} // namespace Calc

#endif // CALC_AST_EXPRESSION_HPP
