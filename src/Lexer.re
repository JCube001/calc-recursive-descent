#include "Lexer.hpp"

#include <sstream>
#include <cstdlib>

namespace Calc {

using ID = Token::ID;

Token Lexer::operator()()
{
    for (;;) {
        lexeme = cursor;
        /*!re2c
            re2c:define:YYCTYPE = std::string_view::value_type;
            re2c:define:YYCURSOR = cursor;
            re2c:define:YYMARKER = marker;
            re2c:yyfill:enable = 0;

            * {
                std::ostringstream stream;
                stream << "Stray '" << yych << "' detected";
                throw std::runtime_error(stream.str());
            }

            end = "\x00";
            end { return {ID::Eof}; }

            ws = [ \t\v\f\r\n];
            ws { continue; }

            "+" { return {ID::Plus}; }
            "-" { return {ID::Minus}; }
            "*" { return {ID::Times}; }
            "/" { return {ID::Divide}; }
            "(" { return {ID::LParen}; }
            ")" { return {ID::RParen}; }

            number = ("0" | [1-9][0-9]*) ("." [0-9]+)?;
            number { return {ID::Number, std::strtod(lexeme, nullptr)}; }
        */
    }
}

} // namespace Calc
