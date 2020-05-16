#ifndef CALC_AST_EXPRESSION_HPP
#define CALC_AST_EXPRESSION_HPP

#include <Calc/Ast/Visitor.hpp>

namespace Calc {
namespace Ast {

struct Expression
{
    virtual ~Expression() = default;
    virtual void accept(Visitor& visitor) = 0;
};

} // namespace Ast
} // namespace Calc

#endif // CALC_AST_EXPRESSION_HPP
