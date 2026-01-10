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

    Fraction<int> f1{3, 4};
    Fraction<int> f2 = f1;

    Fraction<int> f3{5, 6};
    f3 = f1;

    Fraction<int> f4{7, 8};
    Fraction<int> f5 = std::move(f4);

    Fraction<int> f6 = Fraction<int>{9, 10};

    Fraction<int> f7{11, 12};
    Fraction<int> f8{13, 14};
    f8 = std::move(f7);

    Fraction<int> f9{15, 16};
    f9 = Fraction<int>{17, 18};

    // End testing code
    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << std::endl;
	return 0;
}

