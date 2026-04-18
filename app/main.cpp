#include "Fraction.hpp"
#include "MultiDimensionArray.hpp"
#include "math_helpers.hpp"
#include "string_helpers.hpp"
#include "sorts.hpp"
#include "Timer.h"
#include "concepts.hpp"
#include "random.hpp"
#include "Nodes.hpp"
#include "LRUCache.hpp"
#include "Tree.hpp"
#include "BinaryTree.hpp"
#include "TreeGenerator.hpp"
#include "MinHeap.hpp"
#include "IPv4.h"
#include "HierarchicalMutex.h"
#include "AverageCalculator.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <utility>
#include <memory>
#include <vector>
#include <unordered_map>
#include <future>
#include <thread>
#include <string>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <list>
#include <mutex>
#include <numbers>
#include <cmath>


using namespace core;

int a() { return 2; }

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    
    Timer t;
    {
        // Start testing code

        // pi ~ 4 x average (heads / total flips)  stop when heads > tails
        AverageCalculator calc;
        double estimate_pi{0.0l};
        int iteration_count{0};
        constexpr double err = 0.00001;

        std::cout << std::setprecision(std::numeric_limits<double>::max_digits10);

        while(std::abs(std::numbers::pi - estimate_pi) > err) {
            double heads{0.0l};
            double tails{0.0l};

            while (tails >= heads) {
                bool coinFlip = Random::get<uint8_t>(0, 1);

                if (coinFlip == 0) {
                    ++heads;
                } else {
                    ++tails;
                }
            }

            calc += (heads / (heads + tails));
            estimate_pi = (calc() * 4);
            ++iteration_count;

            if (iteration_count % 1000 == 0) {
                std::cout << "Number of iterations: "
                          << iteration_count
                          << "\nEstimate: "
                          << estimate_pi
                          << "\n";
            }
        }

        std::cout << "Number of iterations: "
                  << iteration_count
                  << "\nEstimate: "
                  << estimate_pi
                  << "\nActual: "
                  << std::numbers::pi;

        // End testing code
    }
    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << " seconds.\n";
	return 0;
}

