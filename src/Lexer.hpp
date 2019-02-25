#ifndef CALC_LEXER_HPP
#define CALC_LEXER_HPP

#include "Token.hpp"
#include <string_view>

namespace Calc {

class Lexer
{
public:
    Lexer(std::string_view text)
        : buffer(text)
        , cursor(buffer.data())
        , marker(cursor)
        , lexeme(cursor)
    {}

    Token operator()();

private:
    std::string_view buffer;
    std::string_view::const_pointer cursor;
    std::string_view::const_pointer marker;
    std::string_view::const_pointer lexeme;
};

} // namespace Calc

#endif // CALC_LEXER_HPP
