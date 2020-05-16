#ifndef CALC_PARSER_HPP
#define CALC_PARSER_HPP

#include "Calc/Calc.hpp"
#include "Lexer.hpp"

namespace Calc {

class Parser
{
public:
    Parser(std::istream& stream)
        : lex{stream}
        , token{lex()}
    {}

    std::unique_ptr<Ast::Expression> operator()();

private:
    std::unique_ptr<Ast::Expression> parseExpression();
    std::unique_ptr<Ast::Expression> parseTerm();
    std::unique_ptr<Ast::Expression> parseFactor();
    std::unique_ptr<Ast::Expression> parseExponent();
    std::unique_ptr<Ast::Number> parseNumber();

    bool match(const Token::ID id) const;
    bool accept(const Token::ID id);
    void next();

    Lexer lex;
    Token token;
};

} // namespace Calc

#endif // CALC_PARSER_HPP
