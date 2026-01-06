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

    Fraction<int> f1{};

    f1 = {0, 2};

    std::cout << +f1 << "\n";
    std::cout << -f1 << "\n";
    std::cout << static_cast<bool>(f1) << "\n";
    std::cout << !f1 << "\n";
    



    // End testing code
    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << std::endl;
	return 0;
}