#ifndef CALC_HPP
#define CALC_HPP

#include <Calc/Ast/Ast.hpp>
#include <memory>
#include <string_view>

namespace Calc {

std::unique_ptr<Ast::Expression> parse(std::string_view text);

double evaluate(std::string_view text);

} // namespace Calc

#endif // CALC_HPP
