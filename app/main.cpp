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

#include <iostream>
#include <utility>
#include <memory>
#include <vector>
#include <unordered_map>
#include <future>

using namespace core;


int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    Timer t;
    {
        // Start testing code

        auto empty    = EmptyTree<BinaryTree<int>>();
        auto one      = OneElementTree<BinaryTree<int>>();
        auto balanced = BalancedTree<BinaryTree<int>>(10);
        auto worst    = WorstUnbalancedTree<BinaryTree<int>>(10);
        auto random   = RandomTree<BinaryTree<int>>(10);
        auto uniqueT  = UniqueRandomTree<BinaryTree<int>>(10);

        std::cout << empty << std::endl << std::endl;
        std::cout << one << std::endl << std::endl;
        std::cout << balanced << std::endl << std::endl;
        std::cout << worst << std::endl << std::endl;
        std::cout << random << std::endl << std::endl;
        std::cout << uniqueT << std::endl << std::endl;



        // End testing code
    }
    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << " seconds." << std::endl;
	return 0;
}

