#include "Calc/Calc.hpp"
#include "config.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cctype>

namespace {

// https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
void trimRight(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

} // namespace

int main()
{
    std::cout << "Calc interpreter version " CALC_VERSION "\n"
                 "Enter " CALC_KEYSEQ_QUIT " to quit\n";

    for (;;) {
        std::string line;

        std::cout << "> ";
        std::getline(std::cin, line);
        if (!std::cin) {
            break;
        }

        trimRight(line);
        if (line.empty()) {
            continue;
        }

        try {
            std::cout << Calc::evaluate(line) << '\n';
        } catch (const Calc::SyntaxError& e) {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }

    std::cout << "\nBye!\n";
}
