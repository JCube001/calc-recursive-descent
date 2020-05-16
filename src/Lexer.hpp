#ifndef CALC_LEXER_HPP
#define CALC_LEXER_HPP

#include "Token.hpp"
#include <istream>

namespace Calc {

class Lexer
{
public:
    Lexer(std::istream& stream)
        : stream{stream}
    {}

    Token operator()();

private:
    std::istream& stream;
};

} // namespace Calc

#endif // CALC_LEXER_HPP
