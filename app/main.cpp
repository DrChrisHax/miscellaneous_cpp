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


        LRUCache<int, std::string> cache{5uz};
        LRUCache<int, std::string> c0{cache};
        LRUCache<int, std::string> c1{5uz};
        LRUCache<int, std::string> c2{5uz};
        LRUCache<int, std::string> c3{5uz};


        cache.put(1, "S1");
        c1 = cache;
        cache.put(2, "S2");
        c2 = cache;
        cache.put(3, "S3");
        cache.get(1);
        cache.put(4, "S4");
        c3 = cache;
        cache.put(5, "S5");
        cache.put(6, "S6");


        std::cout << "Cache:\nSize: " << cache.size() << "\nCapacity: " << cache.capacity() << "\nList: " << cache << "\n";
        std::cout << "C0:\nSize: " << c0.size() << "\nCapacity: " << c0.capacity() << "\nList: " << c0 << "\n";
        std::cout << "C1:\nSize: " << c1.size() << "\nCapacity: " << c1.capacity() << "\nList: " << c1 << "\n";
        std::cout << "C2:\nSize: " << c2.size() << "\nCapacity: " << c2.capacity() << "\nList: " << c2 << "\n";
        std::cout << "C3:\nSize: " << c3.size() << "\nCapacity: " << c3.capacity() << "\nList: " << c3 << "\n";

        LRUCache<int, std::string> moved{std::move(cache)};

        std::cout << "Moved cache to moved\n";
        std::cout << "Cache:\nSize: " << cache.size() << "\nCapacity: " << cache.capacity() << "\nList: " << cache << "\n";
        std::cout << "Moved:\nSize: " << moved.size() << "\nCapacity: " << moved.capacity() << "\nList: " << moved << "\n";

        moved = std::move(c1);

        std::cout << "Moved c1 to moved\n";
        std::cout << "Moved:\nSize: " << moved.size() << "\nCapacity: " << moved.capacity() << "\nList: " << moved << "\n";
        std::cout << "C1:\nSize: " << c1.size() << "\nCapacity: " << c1.capacity() << "\nList: " << c1 << "\n";

        // End testing code
    }
    const double ts = t.elapsed();
    std::cout << "\nTime taken: " << std::to_string(ts) << " seconds." << std::endl;
	return 0;
}

