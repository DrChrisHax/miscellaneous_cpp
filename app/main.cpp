#include "Fraction.hpp"

#include <iostream>
#include <numeric>

int main(int argc, char* argv[]) {

    (void)argc;
    (void)argv;

    //INT_MAX = 2,147,483,647

    Fraction<int> f1(1'000'000'000, 7);         // 1 billion / 7
    Fraction<int> f2(21, 1'000'000'000);        // 21 / 1 billion

    std::cout << to_string(f1) << std::endl;
    std::cout << to_string(f2) << std::endl;
    std::cout << to_string(f1 * f2) << std::endl;

    return 0;
}