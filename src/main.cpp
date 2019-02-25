#include "Calc/Calc.hpp"
#include "config.hpp"
#include <exception>
#include <iostream>
#include <string>

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
        } else if (line.empty()) {
            continue;
        }

        try {
            std::cout << Calc::evaluate(line) << '\n';
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << "Bye!\n";
}
