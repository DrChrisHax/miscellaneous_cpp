#include "Fraction.hpp"
#include "MultiDimensionArray.hpp"
#include "math_helpers.hpp"
#include "string_helpers.hpp"
#include "sorts.hpp"
#include "Timer.h"

#include <iostream>
#include <iomanip>

#include <array>
#include <algorithm>
#include <string>
#include <string_view>
#include <functional>
#include <map>

#include <iterator>




int main(int argc, char* argv[]) {

    (void)argc;
    (void)argv;
    core::Timer t;
    // Start testing code

    Fraction<int> f1(99, 872'415'232); // 3*3*11 / 2^26 * 13
    Fraction<int> f2(51, 1'140'850'688); // 17*3 / 2^26 * 17
    Fraction<int> expected(69, 436'207'616); // 3*23 / 2^25 * 13
    
    std::cout << std::setprecision(32);
    std::cout << "f1: " << f1 << "\n";
    std::cout << "f2: " << f2 << "\n";
    std::cout << "expected: " << expected << "\n";

    Fraction<int> result;
    try {
        result = f1 + f2;
    } catch (const std::overflow_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "result: " << result << "\n";

    // End testing code
    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << std::endl;
	return 0;
}