#include "Fraction.hpp"
#include "MultiDimensionArray.hpp"
#include "math_helpers.hpp"
#include "string_helpers.hpp"
#include "sorts.hpp"

#include <array>
#include <vector>

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

    std::array a {2, 12, 15, 9, 8, 5, 14, 32, 1};

    std::vector<int> v {2, 12, 15, 9, 8, 5, 14, 32, 1};

    std::cout << "Array:\n";

    print(a.begin(), a.end());
    BubbleSort(a.begin(), a.end());
    print(a.begin(), a.end());

    std::cout << "Vector:\n";
    print(v.begin(), v.end());
    BubbleSort(v.begin(), v.end());
    print(v.begin(), v.end());

	return 0;
}