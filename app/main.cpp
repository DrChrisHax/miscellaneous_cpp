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


using namespace core;



int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    
    Timer t;
    {
        // Start testing code

        IPv4 ip{192, 168, 254, 1};

        ip++;
        ++ip;
        std::cout << ip << "\nIs Public: " << ip.is_public() << "\nIs Private: " << ip.is_private();
        
        std::unordered_set<IPv4> test;
        test.insert(ip);

        // End testing code
    }
    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << " seconds.\n";
	return 0;
}

