#ifndef CALC_PARSER_HPP
#define CALC_PARSER_HPP

#include "Calc/Calc.hpp"
#include "Lexer.hpp"

namespace Calc {

class Parser
{
public:
    Parser(std::string_view text)
        : lex(text)
        , token(lex())
    {}

    std::unique_ptr<Ast::Expression> operator()();

private:
    std::unique_ptr<Ast::Expression> expression();

    std::unique_ptr<Ast::Expression> term();

    std::unique_ptr<Ast::Expression> factor();

    std::unique_ptr<Ast::Number> number();

    std::unique_ptr<Ast::BinaryOperator> binaryOperator();

    bool check(const Token::ID id)
    {
        return id == token.id;
    }

    bool accept(const Token::ID id)
    {
        if (check(id)) {
            next();
            return true;
        }

        return false;
    }

    void next()
    {
        token = lex();
    }

    Lexer lex;
    Token token;
};

} // namespace Calc

#endif // CALC_PARSER_HPP
