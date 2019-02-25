#ifndef CALC_TOKEN_HPP
#define CALC_TOKEN_HPP

namespace Calc {

struct Token
{
    enum class ID
    {
        Eof = 0,
        Plus,
        Minus,
        Times,
        Divide,
        LParen,
        RParen,
        Number
    };

    ID id;
    double value;
};

} // namespace Calc

#endif // CALC_TOKEN_HPP