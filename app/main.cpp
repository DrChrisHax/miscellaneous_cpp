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
#include "SimpleLock.hpp"

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
#include <atomic>


using namespace core;

int a() { return 2; }

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    
    Timer t;

    { // Start testing code

        SimpleLock lock_;
        int counter = 0;
        constexpr int ITERS = 1'000'000;

        std::thread t1([&]{
            for (int i = 0; i < ITERS; ++i) {
                lock_.lock();
                ++counter;
                lock_.unlock();
            }
        });
        std::thread t2([&]{
            for (int i = 0; i < ITERS; ++i) {
                lock_.lock();
                ++counter;
                lock_.unlock();
            }
        });

        t1.join();
        t2.join();

        std::cout << "counter = " << counter << " (expected " << 2 * ITERS << ")\n";

    } // End testing code

    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << " seconds.\n";
	return 0;
}

