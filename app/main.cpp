#include "Fraction.hpp"
#include "MultiDimensionArray.hpp"
#include "math_helpers.hpp"
#include "string_helpers.hpp"
#include "sorts.hpp"
#include "Timer.h"


int main(int argc, char* argv[]) {

    (void)argc;
    (void)argv;

    core::Timer t;

    const double ts = t.elapsed();

    Fraction f1(1, 4);
    Fraction f2(3, 4);

    std::cout << f1 - f2 << "\n";

    std::cout << "Time taken: " << std::to_string(ts);

    std::cout << std::endl;

	return 0;
}