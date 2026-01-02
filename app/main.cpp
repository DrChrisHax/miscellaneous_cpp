#include "Fraction.hpp"
#include "MultiDimensionArray.hpp"
#include "math_helpers.hpp"
#include "string_helpers.hpp"
#include "sorts.hpp"
#include "Timer.h"

#include <array>
#include <vector>
#include <numeric>

void print(auto start, auto end) {
    while (start != end) {
        std::cout << *start << " ";
        ++start;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {

    (void)argc;
    (void)argv;

    core::Timer timer;

    std::cout << "Creating 3 vectors with 100,000 elements" << std::endl;

    timer.reset();
    std::vector<int> v1(100000);
    std::iota(v1.rbegin(), v1.rend(), 1);
    std::vector<int> v2 = v1;
    std::vector<int> v3 = v1;
    const double ts0 = timer.elapsed();
    std::cout << "Vector creation time: " << std::to_string(ts0) << std::endl;


    BubbleSort(v1.begin(), v1.end());
    const double ts1 = timer.elapsed();
    std::cout << "Bubble sort time: " << std::to_string(ts1) << std::endl;

    timer.reset();
    SelectionSort(v1.begin(), v1.end());
    const double ts2 = timer.elapsed();
    std::cout << "Selection sort time: " << std::to_string(ts2) << std::endl;

    timer.reset();
    std::sort(v2.begin(), v2.end());
    const double ts3 = timer.elapsed();
    std::cout << "std::sort time: " << std::to_string(ts3) << std::endl;

	return 0;
}