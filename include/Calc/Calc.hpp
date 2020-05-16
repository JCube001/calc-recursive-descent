#ifndef CALC_HPP
#define CALC_HPP

#include <Calc/Ast/Ast.hpp>
#include <Calc/SyntaxError.hpp>
#include <istream>
#include <memory>
#include <string>

namespace Calc {

std::unique_ptr<Ast::Expression> parse(std::istream& stream);

double evaluate(std::istream& stream);
double evaluate(const std::string& code);

} // namespace Calc

#endif // CALC_HPP
