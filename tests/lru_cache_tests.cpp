#include "tests.h"
#include "LRUCache.hpp"

#include <sstream>

using namespace core;

// Constructor tests
bool lru_cache_constructor_explicit_capacity() {
    std::cout << "[TEST] LRU Cache Constructor - Explicit Capacity" << std::endl;
    LRUCache<int, std::string> cache{5uz};
    std::string expected = "Capacity: 5\nSize: 0";
    std::string result = "Capacity: " + std::to_string(cache.capacity()) + "\nSize: " + std::to_string(cache.size());
    return test_helper(expected, result);
}

bool lru_cache_constructor_copy() {
    std::cout << "[TEST] LRU Cache Constructor - Copy" << std::endl;

    std::string expected = "";
    std::string result = "";

    // The enclosed block is to test the destructor as well
    {
        LRUCache<int, std::string> original{3uz};
        original.put(1, "one");
        original.put(2, "two");
        
        LRUCache<int, std::string> copy(original);
        expected = "Capacity: 3\nSize: 2\nContains 1: true\nContains 2: true";
        result = "Capacity: " + std::to_string(copy.capacity()) + "\nSize: " + std::to_string(copy.size()) +
                            "\nContains 1: " + (copy.contains(1) ? "true" : "false") +
                            "\nContains 2: " + (copy.contains(2) ? "true" : "false");
    }
    
    return test_helper(expected, result);
}

bool lru_cache_constructor_move() {
    std::cout << "[TEST] LRU Cache Constructor - Move" << std::endl;

    std::string expected = "";
    std::string result = "";

    // The enclosed block is to test the destructor as well
    {
        LRUCache<int, std::string> original{3uz};
        original.put(1, "one");
        original.put(2, "two");
        
        LRUCache<int, std::string> moved(std::move(original));
        expected = "Capacity: 3\nSize: 2\nContains 1: true\nContains 2: true";
        result = "Capacity: " + std::to_string(moved.capacity()) + "\nSize: " + std::to_string(moved.size()) +
                            "\nContains 1: " + (moved.contains(1) ? "true" : "false") +
                            "\nContains 2: " + (moved.contains(2) ? "true" : "false");
    }
    return test_helper(expected, result);
}

// Assignment operator tests
bool lru_cache_assignment_copy() {
    std::cout << "[TEST] LRU Cache Assignment - Copy" << std::endl;
    LRUCache<int, std::string> original{3uz};
    original.put(1, "one");
    original.put(2, "two");
    
    LRUCache<int, std::string> assigned{2uz};
    assigned = original;
    
    std::string expected = "Capacity: 3\nSize: 2\nContains 1: true\nContains 2: true";
    std::string result = "Capacity: " + std::to_string(assigned.capacity()) + "\nSize: " + std::to_string(assigned.size()) +
                         "\nContains 1: " + (assigned.contains(1) ? "true" : "false") +
                         "\nContains 2: " + (assigned.contains(2) ? "true" : "false");
    return test_helper(expected, result);
}

bool lru_cache_assignment_move() {
    std::cout << "[TEST] LRU Cache Assignment - Move" << std::endl;
    LRUCache<int, std::string> original{3uz};
    original.put(1, "one");
    original.put(2, "two");
    
    LRUCache<int, std::string> assigned{2uz};
    assigned = std::move(original);
    
    std::string expected = "Capacity: 3\nSize: 2\nContains 1: true\nContains 2: true";
    std::string result = "Capacity: " + std::to_string(assigned.capacity()) + "\nSize: " + std::to_string(assigned.size()) +
                         "\nContains 1: " + (assigned.contains(1) ? "true" : "false") +
                         "\nContains 2: " + (assigned.contains(2) ? "true" : "false");
    return test_helper(expected, result);
}

bool lru_cache_assignment_self() {
    std::cout << "[TEST] LRU Cache Assignment - Self Assignment" << std::endl;
    LRUCache<int, std::string> cache{3uz};
    cache.put(1, "one");
    cache.put(2, "two");
    
    cache = cache;
    
    std::string expected = "Capacity: 3\nSize: 2\nContains 1: true\nContains 2: true";
    std::string result = "Capacity: " + std::to_string(cache.capacity()) + "\nSize: " + std::to_string(cache.size()) +
                         "\nContains 1: " + (cache.contains(1) ? "true" : "false") +
                         "\nContains 2: " + (cache.contains(2) ? "true" : "false");
    return test_helper(expected, result);
}

// Basic functionality tests
bool lru_cache_empty_cache() {
    std::cout << "[TEST] LRU Cache - Empty Cache" << std::endl;
    LRUCache<int, std::string> cache{5uz};
    
    std::string expected = "Capacity: 5\nSize: 0";
    std::string result = "Capacity: " + std::to_string(cache.capacity()) + "\nSize: " + std::to_string(cache.size());
    return test_helper(expected, result);
}

bool lru_cache_single_item() {
    std::cout << "[TEST] LRU Cache - Single Item" << std::endl;
    LRUCache<int, std::string> cache{5uz};
    cache.put(1, "one");
    
    std::string* val = cache.get(1);
    std::string expected = "Size: 1\nContains 1: true\nValue of 1: one";
    std::string result = "Size: " + std::to_string(cache.size()) +
                         "\nContains 1: " + (cache.contains(1) ? "true" : "false") +
                         "\nValue of 1: " + (val != nullptr ? *val : "nullptr");
    return test_helper(expected, result);
}

bool lru_cache_multiple_items() {
    std::cout << "[TEST] LRU Cache - Multiple Items" << std::endl;
    LRUCache<int, std::string> cache{5uz};
    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(3, "three");
    
    std::string expected = "Size: 3\nContains 1: true\nContains 2: true\nContains 3: true";
    std::string result = "Size: " + std::to_string(cache.size()) +
                         "\nContains 1: " + (cache.contains(1) ? "true" : "false") +
                         "\nContains 2: " + (cache.contains(2) ? "true" : "false") +
                         "\nContains 3: " + (cache.contains(3) ? "true" : "false");
    return test_helper(expected, result);
}

// Put and Get tests
bool lru_cache_put_and_get_basic() {
    std::cout << "[TEST] LRU Cache - Put and Get Basic" << std::endl;
    LRUCache<std::string, int> cache{3uz};
    cache.put("first", 100);
    cache.put("second", 200);
    
    int* val1 = cache.get("first");
    int* val2 = cache.get("second");
    
    std::string expected = "Size: 2\nValue of first: 100\nValue of second: 200";
    std::string result = "Size: " + std::to_string(cache.size()) +
                         "\nValue of first: " + (val1 != nullptr ? std::to_string(*val1) : "nullptr") +
                         "\nValue of second: " + (val2 != nullptr ? std::to_string(*val2) : "nullptr");
    return test_helper(expected, result);
}

bool lru_cache_get_moves_to_front() {
    std::cout << "[TEST] LRU Cache - Get Moves Item to Front" << std::endl;
    LRUCache<int, std::string> cache{3uz};
    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(3, "three");
    
    cache.get(1);
    cache.put(4, "four");
    
    std::string expected = "Size: 3\nContains 1: true\nContains 2: false\nContains 3: true\nContains 4: true";
    std::string result = "Size: " + std::to_string(cache.size()) +
                         "\nContains 1: " + (cache.contains(1) ? "true" : "false") +
                         "\nContains 2: " + (cache.contains(2) ? "true" : "false") +
                         "\nContains 3: " + (cache.contains(3) ? "true" : "false") +
                         "\nContains 4: " + (cache.contains(4) ? "true" : "false");
    return test_helper(expected, result);
}

bool lru_cache_put_existing_key() {
    std::cout << "[TEST] LRU Cache - Put with Existing Key" << std::endl;
    LRUCache<int, std::string> cache{3uz};
    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(1, "ONE_UPDATED");
    
    std::string* val = cache.get(1);
    std::string expected = "Size: 2\nValue of 1: ONE_UPDATED";
    std::string result = "Size: " + std::to_string(cache.size()) +
                         "\nValue of 1: " + (val != nullptr ? *val : "nullptr");
    return test_helper(expected, result);
}

bool lru_cache_get_nonexistent_returns_nullptr() {
    std::cout << "[TEST] LRU Cache - Get Non-existent Returns nullptr" << std::endl;
    LRUCache<int, std::string> cache{3uz};
    cache.put(1, "one");
    
    auto val = cache.get(999);
    std::string expected = "Size: 1\nGet 999: nullptr";
    std::string result = "Size: " + std::to_string(cache.size()) +
                         "\nGet 999: " + (val == nullptr ? "nullptr" : "found");
    return test_helper(expected, result);
}

// Capacity and eviction tests
bool lru_cache_capacity_hit_multiple_times() {
    std::cout << "[TEST] LRU Cache - Capacity Hit Multiple Times" << std::endl;
    LRUCache<int, int> cache{3uz};
    
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);
    cache.put(4, 40);
    cache.put(5, 50);
    cache.put(6, 60);
    
    cache.get(4);
    cache.put(7, 70);
    
    std::string expected = "Size: 3\nContains 1: false\nContains 2: false\nContains 3: false\nContains 4: true\nContains 5: false\nContains 6: true\nContains 7: true";
    std::string result = "Size: " + std::to_string(cache.size()) +
                         "\nContains 1: " + (cache.contains(1) ? "true" : "false") +
                         "\nContains 2: " + (cache.contains(2) ? "true" : "false") +
                         "\nContains 3: " + (cache.contains(3) ? "true" : "false") +
                         "\nContains 4: " + (cache.contains(4) ? "true" : "false") +
                         "\nContains 5: " + (cache.contains(5) ? "true" : "false") +
                         "\nContains 6: " + (cache.contains(6) ? "true" : "false") +
                         "\nContains 7: " + (cache.contains(7) ? "true" : "false");
    return test_helper(expected, result);
}

bool lru_cache_capacity_with_updates() {
    std::cout << "[TEST] LRU Cache - Capacity with Updates" << std::endl;
    LRUCache<std::string, int> cache{2uz};
    
    cache.put("a", 1);
    cache.put("b", 2);
    cache.put("a", 10);
    cache.put("c", 3);
    
    int* val_a = cache.get("a");
    std::string expected = "Size: 2\nContains a: true\nContains b: false\nContains c: true\nValue of a: 10";
    std::string result = "Size: " + std::to_string(cache.size()) +
                         "\nContains a: " + (cache.contains("a") ? "true" : "false") +
                         "\nContains b: " + (cache.contains("b") ? "true" : "false") +
                         "\nContains c: " + (cache.contains("c") ? "true" : "false") +
                         "\nValue of a: " + (val_a != nullptr ? std::to_string(*val_a) : "nullptr");
    return test_helper(expected, result);
}

// Operator tests
bool lru_cache_ostream_single_item() {
    std::cout << "[TEST] LRU Cache - Output Stream Single Item" << std::endl;
    LRUCache<int, std::string> cache{3uz};
    cache.put(1, "one");
    
    std::stringstream ss;
    ss << cache;

    std::string expected = "(1, one)";
    std::string result = ss.str();
    return test_helper(expected, result);
}

bool lru_cache_ostream_multiple_items() {
    std::cout << "[TEST] LRU Cache - Output Stream Multiple Items" << std::endl;
    LRUCache<int, std::string> cache{3uz};
    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(3, "three");
    
    std::stringstream ss;
    ss << cache;
    
    std::string expected = "(3, three)-->(2, two)-->(1, one)";
    std::string result = ss.str();
    return test_helper(expected, result);
}
