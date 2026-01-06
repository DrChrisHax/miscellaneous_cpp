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

    // Fraction<long long> f1(99, 872'415'232); // 3*3*11 / 2^26 * 13
    // Fraction<long long> f2(51, 1'140'850'688); // 17*3 / 2^26 * 17
    // Fraction<long long> f3(69, 436'207'616); // 3*23 / 2^25 * 13

    // std::cout << std::setprecision(32);
    // std::cout << "f1:\n" << f1 << "\n" << to_long_double(f1) << "\n";
    // std::cout << "f2:\n" << f2 << "\n" << to_long_double(f2) << "\n";
    // std::cout << "f3:\n" << f3 << "\n" << to_long_double(f3) << "\n";

    // Fraction<long long> result;
    // try {
    //     result = f1 + f2;
    // } catch (const std::overflow_error& e) {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << "result:\n" << result << "\n" << to_long_double(result) << "\n";

    for (auto i{1}; i < 10000; ++i) {
        for (auto j{1}; j < 10000; ++j) {
            int res = (17*i) + (13*j);
            if ((res%13 == 0 || res%17 == 0) && ((i*17 % 13 != 0) && (j*13 % 17 != 0))) {
                std::cout << "res: " << res << " i: " << i << " j: " << j << "\n";
                std::cout << res << " % " << i << " = " << res%i << " " << res << " % " << j << " = " << res%j << "\n";
            }
            
        }
    }


    // End testing code
    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << std::endl;
	return 0;
}