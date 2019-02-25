#include "Parser.hpp"

#include <stdexcept>
#include <utility>

namespace Calc {

using ID = Token::ID;

std::unique_ptr<Ast::Expression> Parser::operator()()
{
    auto tree = expression();

    if (!check(Token::ID::Eof)) {
        throw std::runtime_error("Junk at end of expression");
    }

    return tree;
}

std::unique_ptr<Ast::Expression> Parser::expression()
{
    auto tree = term();

    while (check(ID::Plus) || check(ID::Minus)) {
        auto op = binaryOperator();
        next();
        op->left = std::move(tree);
        op->right = term();
        tree = std::move(op);
    }

    return tree;
}

std::unique_ptr<Ast::Expression> Parser::term()
{
    auto tree = factor();

    while (check(ID::Times) || check(ID::Divide)) {
        auto op = binaryOperator();
        next();
        op->left = std::move(tree);
        op->right = factor();
        tree = std::move(op);
    }

    return tree;
}

std::unique_ptr<Ast::Expression> Parser::factor()
{
    std::unique_ptr<Ast::Expression> tree;

    if (check(Token::ID::Number)) {
        tree = number();
        next();
    } else if (accept(Token::ID::LParen)) {
        tree = expression();
        if (!accept(Token::ID::RParen)) {
            throw std::runtime_error("Expected closing ')'");
        }
    } else if (accept(Token::ID::Plus)) {
        tree = expression();
    } else if (accept(Token::ID::Minus)) {
        auto negation = std::make_unique<Ast::NegationOperator>();
        negation->right = factor();
        tree = std::move(negation);
    } else {
        throw std::runtime_error("Invalid expression");
    }

    return tree;
}

std::unique_ptr<Ast::Number> Parser::number()
{
    return std::make_unique<Ast::Number>(token.value);
}

std::unique_ptr<Ast::BinaryOperator> Parser::binaryOperator()
{
    switch (token.id) {
    case ID::Plus:
        return std::make_unique<Ast::AdditionOperator>();
    case ID::Minus:
        return std::make_unique<Ast::SubtractionOperator>();
    case ID::Times:
        return std::make_unique<Ast::MultiplicationOperator>();
    case ID::Divide:
        return std::make_unique<Ast::DivisionOperator>();
    default:
        throw std::logic_error("Calc::Parser expected a binary operator");
    }
}

} // namespace Calc
