#ifndef CALC_TOKEN_HPP
#define CALC_TOKEN_HPP

namespace Calc {

struct Token
{
    enum class ID
    {
        Unknown,
        Eof,
        Plus,
        Minus,
        Times,
        Divide,
        Exponent,
        LParen,
        RParen,
        Number
    };

    ID id;
    double value;
};

} // namespace Calc

#endif // CALC_TOKEN_HPP
