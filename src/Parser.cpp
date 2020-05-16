#include "Parser.hpp"

#include <utility>

namespace Calc {

std::unique_ptr<Ast::Expression> Parser::operator()()
{
    auto expression = parseExpression();

    if (!match(Token::ID::Eof)) {
        throw SyntaxError{"extra input at end of expression"};
    }

    return expression;
}

std::unique_ptr<Ast::Expression> Parser::parseExpression()
{
    auto expression = parseTerm();

    for (;;) {
        std::unique_ptr<Ast::BinaryExpression> term;

        if (accept(Token::ID::Plus)) {
            term = std::make_unique<Ast::AdditionExpression>();
        } else if (accept(Token::ID::Minus)) {
            term = std::make_unique<Ast::SubtractionExpression>();
        } else {
            break;
        }

        term->left = std::move(expression);
        term->right = parseTerm();
        expression = std::move(term);
    }

    return expression;
}

std::unique_ptr<Ast::Expression> Parser::parseTerm()
{
    auto term = parseFactor();

    for (;;) {
        std::unique_ptr<Ast::BinaryExpression> factor;

        if (accept(Token::ID::Times)) {
            factor = std::make_unique<Ast::MultiplicationExpression>();
        } else if (accept(Token::ID::Divide)) {
            factor = std::make_unique<Ast::DivisionExpression>();
        } else {
            break;
        }

        factor->left = std::move(term);
        factor->right = parseFactor();
        term = std::move(factor);
    }

    return term;
}

std::unique_ptr<Ast::Expression> Parser::parseFactor()
{
    auto factor = parseExponent();

    if (accept(Token::ID::Exponent)) {
        auto exponent = std::make_unique<Ast::ExponentExpression>();
        exponent->left = std::move(factor);
        exponent->right = parseFactor();
        factor = std::move(exponent);
    }

    return factor;
}

std::unique_ptr<Ast::Expression> Parser::parseExponent()
{
    std::unique_ptr<Ast::Expression> exponent;

    if (accept(Token::ID::LParen)) {
        exponent = parseExpression();
        if (!accept(Token::ID::RParen)) {
            throw SyntaxError{"expected ')'"};
        }
    } else if (accept(Token::ID::Plus)) {
        exponent = parseExponent();
    } else if (accept(Token::ID::Minus)) {
        exponent = std::make_unique<Ast::NegationExpression>(parseExponent());
    } else if (match(Token::ID::Number)) {
        exponent = parseNumber();
    } else {
        throw SyntaxError{"invalid expression"};
    }

    return exponent;
}

std::unique_ptr<Ast::Number> Parser::parseNumber()
{
    auto number = std::make_unique<Ast::Number>(token.value);
    next();
    return number;
}

bool Parser::match(const Token::ID id) const
{
    return token.id == id;
}

bool Parser::accept(const Token::ID id)
{
    if (match(id)) {
        next();
        return true;
    }

    return false;
}

void Parser::next()
{
    token = lex();
}

} // namespace Calc
