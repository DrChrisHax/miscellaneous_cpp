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

using namespace core;



int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    Timer t;
    {
        // Start testing code

        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

        heap.push(5);
        heap.push(3);
        heap.push(8);
        heap.push(1);


        while (!heap.empty()) {
            std::cout << heap.top() << " ";
            heap.pop();
        }

        // End testing code
    }
    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << " seconds.\n";
	return 0;
}

