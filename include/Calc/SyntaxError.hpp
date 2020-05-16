#ifndef CALC_SYNTAX_ERROR_HPP
#define CALC_SYNTAX_ERROR_HPP

#include <stdexcept>

namespace Calc {

class SyntaxError final : public std::runtime_error
{
public:
    SyntaxError(const std::string& message)
        : std::runtime_error{message}
    {}

    SyntaxError(const char* message)
        : std::runtime_error{message}
    {}
};

} // namespace Calc

#endif // CALC_SYNTAX_ERROR_HPP
