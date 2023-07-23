// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Parser.h"

int main()
{
    Parser parser;

    std::cout << "2 + 3 = " << parser.eval("2 + 3") << std::endl;
    std::cout << "2 * 3 = " << parser.eval("2 * 3") << std::endl;
    std::cout << "2 - 3 = " << parser.eval("2 * 3") << std::endl;
    std::cout << "4 / 2 = " << parser.eval("2 * 3") << std::endl;

    std::cout << "2 + 3 + 1 = " << parser.eval("2 + 3 + 1") << std::endl;
    std::cout << "2 * 3 - 1 = " << parser.eval("2 * 3 - 1") << std::endl;
    std::cout << "2 - 3 * 2 = " << parser.eval("2 - 3 * 2") << std::endl;
    std::cout << "4 / 2 + 1 = " << parser.eval("4 / 2 + 1") << std::endl;
}
