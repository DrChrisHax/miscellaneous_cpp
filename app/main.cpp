#include "Fraction.hpp"
#include "MultiDimensionArray.hpp"
#include "math_helpers.hpp"
#include "string_helpers.hpp"
#include "sorts.hpp"
#include "Timer.h"
#include "concepts.hpp"
#include "random.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;
    core::Timer t;
    // Start testing code

    std::cout << Random::get<std::size_t>(1, 6) << "\n"; // returns std::size_t
	std::cout << Random::get<std::size_t>(1, 6u) << "\n"; // returns std::size_t
    std::cout << Random::get<int>(1, 6u) << "\n"; // returns int

    // End testing code
    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << std::endl;
	return 0;
}

