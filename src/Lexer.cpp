#include "Lexer.hpp"

namespace Calc {

Token Lexer::operator()()
{
    double value;

    for (;;) {
        switch (stream.peek()) {
        case ' ':
        case '\f':
        case '\t':
        case '\v':
        case '\r':
        case '\n':
            stream.ignore();
            continue;
        case std::istream::traits_type::eof():
            return {Token::ID::Eof};
        case '+':
            stream.ignore();
            return {Token::ID::Plus};
        case '-':
            stream.ignore();
            return {Token::ID::Minus};
        case '*':
            stream.ignore();
            return {Token::ID::Times};
        case '/':
            stream.ignore();
            return {Token::ID::Divide};
        case '^':
            stream.ignore();
            return {Token::ID::Exponent};
        case '(':
            stream.ignore();
            return {Token::ID::LParen};
        case ')':
            stream.ignore();
            return {Token::ID::RParen};
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            stream >> value;
            return {Token::ID::Number, value};
        default:
            stream.ignore();
            return {Token::ID::Unknown};
        }
    }
}

} // namespace Calc
