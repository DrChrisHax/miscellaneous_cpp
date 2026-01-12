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

#include <iostream>
#include <utility>
#include <memory>
#include <vector>
#include <unordered_map>


using namespace core;


int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    Timer t;
    {
        // Start testing code
        std::unordered_map<int, DL_KV_Node<int, int>*> keys;
        LRUCache<int, int> cache(2uz);

        std::cout << sizeof(keys) << std::endl;
        std::cout << sizeof(cache);


        // End testing code
    }
    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << std::endl;
	return 0;
}

