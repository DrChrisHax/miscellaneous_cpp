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

#include <iostream>
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


using namespace core;

int a() { return 2; }

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    
    Timer t;
    {
        // Start testing code

        std::mutex m;

        std::cout << sizeof(m) << "\n";

        HierarchicalMutext h{1000};

        std::cout << sizeof(h);


        // End testing code
    }
    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << " seconds.\n";
	return 0;
}

