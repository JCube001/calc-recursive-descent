#include "Parser.hpp"

#include <stdexcept>
#include <utility>

namespace Calc {

using ID = Token::ID;

std::unique_ptr<Ast::Expression> Parser::operator()()
{
    auto tree = expression();

    if (!match(ID::Eof)) {
        throw std::runtime_error("Junk at end of expression");
    }

    return tree;
}

std::unique_ptr<Ast::Expression> Parser::expression()
{
    auto tree = term();

    while (match(ID::Plus, ID::Minus)) {
        auto subtree = binaryOperator();
        subtree->left = std::move(tree);
        subtree->right = term();
        tree = std::move(subtree);
    }

    return tree;
}

std::unique_ptr<Ast::Expression> Parser::term()
{
    auto tree = factor();

    while (match(ID::Times, ID::Divide)) {
        auto subtree = binaryOperator();
        subtree->left = std::move(tree);
        subtree->right = factor();
        tree = std::move(subtree);
    }

    return tree;
}

std::unique_ptr<Ast::Expression> Parser::factor()
{
    std::unique_ptr<Ast::Expression> tree;

    if (match(ID::Number)) {
        tree = number();
    } else if (accept(ID::LParen)) {
        tree = expression();
        if (!accept(ID::RParen)) {
            throw std::runtime_error("Expected closing ')'");
        }
    } else if (accept(ID::Plus)) {
        tree = expression();
    } else if (accept(ID::Minus)) {
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
    auto tree = std::make_unique<Ast::Number>(token.value);
    next();
    return tree;
}

std::unique_ptr<Ast::BinaryOperator> Parser::binaryOperator()
{
    const auto id = token.id;

    next();

    switch (id) {
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
