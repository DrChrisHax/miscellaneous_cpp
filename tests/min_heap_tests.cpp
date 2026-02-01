// =============================================================================
// MinHeap Tests Implementation
// Add this to your test implementation file (e.g., tests.cpp)
// =============================================================================

#include "tests.h"
#include "MinHeap.hpp"

#include <sstream>
#include <vector>
#include <algorithm>

// =============================================================================
// Constructor Tests
// =============================================================================

bool min_heap_constructor_default() {
    std::cout << "[TEST] Min Heap Constructor - Default\n";
    core::MinHeap<int> heap;
    std::string result = (heap.empty() && heap.size() == 0) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_explicit_capacity() {
    std::cout << "[TEST] Min Heap Constructor - Explicit Capacity\n";
    core::MinHeap<int> heap(10);
    std::string result = (heap.empty() && heap.size() == 0 && heap.capacity() == 10) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_copy() {
    std::cout << "[TEST] Min Heap Copy Constructor - Normal\n";
    core::MinHeap<int> original(10);
    original.push(5);
    original.push(3);
    original.push(8);
    
    core::MinHeap<int> copy(original);
    
    // Verify copy has same values
    bool same_size = copy.size() == original.size();
    bool same_min = copy.top() == original.top();
    
    // Verify independence - modify original
    original.pop();
    bool independent = copy.size() == 3 && original.size() == 2;
    
    std::string result = (same_size && same_min && independent) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_copy_empty() {
    std::cout << "[TEST] Min Heap Copy Constructor - empty\n";
    core::MinHeap<int> original(5);
    core::MinHeap<int> copy(original);
    
    std::string result = (copy.empty() && copy.capacity() == original.capacity()) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_move() {
    std::cout << "[TEST] Min Heap Move Constructor - Normal\n";
    core::MinHeap<int> original(10);
    original.push(5);
    original.push(3);
    original.push(8);
    
    std::size_t orig_size = original.size();
    int orig_min = original.top();
    
    core::MinHeap<int> moved(std::move(original));
    
    bool correct_size = moved.size() == orig_size;
    bool correct_min = moved.top() == orig_min;
    bool original_empty = original.size() == 0;
    
    std::string result = (correct_size && correct_min && original_empty) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_move_empty() {
    std::cout << "[TEST] Min Heap Move Constructor - empty\n";
    core::MinHeap<int> original(5);
    core::MinHeap<int> moved(std::move(original));
    
    std::string result = (moved.empty()) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_initializer_list() {
    std::cout << "[TEST] Min Heap Initializer List Constructor - Normal\n";
    core::MinHeap<int> heap{5, 3, 8, 1, 9};
    
    bool correct_size = heap.size() == 5;
    bool correct_min = heap.top() == 1;
    
    std::string result = (correct_size && correct_min) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_initializer_list_empty() {
    std::cout << "[TEST] Min Heap Initializer List Constructor - empty\n";
    core::MinHeap<int> heap{};
    
    std::string result = heap.empty() ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// Assignment Operator Tests
// =============================================================================

bool min_heap_assignment_copy() {
    std::cout << "[TEST] Min Heap Copy Assignment Operator - Normal\n";
    core::MinHeap<int> original{5, 3, 8, 1};
    core::MinHeap<int> copy(2);
    copy.push(100);
    
    copy = original;
    
    bool same_size = copy.size() == original.size();
    bool same_min = copy.top() == original.top();
    
    // Verify independence
    original.pop();
    bool independent = copy.size() == 4 && original.size() == 3;
    
    std::string result = (same_size && same_min && independent) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_assignment_copy_empty() {
    std::cout << "[TEST] Min Heap Copy Assignment OPerator - empty\n";
    core::MinHeap<int> original(5);
    core::MinHeap<int> copy{1, 2, 3};
    
    copy = original;
    
    std::string result = copy.empty() ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_assignment_copy_self() {
    std::cout << "[TEST] Min Heap Copy Assignment Operator - Self\n";
    core::MinHeap<int> heap{5, 3, 8, 1};
    
    heap = heap;  // Self-assignment
    
    bool correct_size = heap.size() == 4;
    bool correct_min = heap.top() == 1;
    
    std::string result = (correct_size && correct_min) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_assignment_move() {
    std::cout << "[TEST] Min Heap Move Assignment Operator - Normal\n";
    core::MinHeap<int> original{5, 3, 8, 1};
    core::MinHeap<int> target(2);
    target.push(100);
    
    std::size_t orig_size = original.size();
    int orig_min = original.top();
    
    target = std::move(original);
    
    bool correct_size = target.size() == orig_size;
    bool correct_min = target.top() == orig_min;
    
    std::string result = (correct_size && correct_min) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_assignment_move_empty() {
    std::cout << "[TEST] Min Heap Move Assignment Operator - empty\n";
    core::MinHeap<int> original(5);
    core::MinHeap<int> target{1, 2, 3};
    
    target = std::move(original);
    
    std::string result = target.empty() ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_assignment_move_self() {
    std::cout << "[TEST] Min Heap Move Assignment Operator - Self\n";
    core::MinHeap<int> heap{5, 3, 8, 1};
    
    auto& ref = heap;
    heap = std::move(ref);  // Self-assignment
    
    // After self-move, behavior is implementation-defined but shouldn't crash
    // Just verify it doesn't crash and has reasonable state
    std::string result = "true";  // If we get here without crash, pass
    return test_helper("true", result);
}

// =============================================================================
// Basic State Tests
// =============================================================================

bool min_heap_empty_on_new() {
    std::cout << "[TEST] Min Heap empty On New\n";
    core::MinHeap<int> heap(5);
    std::string result = heap.empty() ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_empty_after_pop_all() {
    std::cout << "[TEST] Min Heap empty After Pop All\n";
    core::MinHeap<int> heap{1, 2, 3};
    heap.pop();
    heap.pop();
    heap.pop();
    std::string result = heap.empty() ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_size_after_push() {
    std::cout << "[TEST] Min Heap Size After Push\n";
    core::MinHeap<int> heap(5);
    heap.push(1);
    heap.push(2);
    heap.push(3);
    std::string result = (heap.size() == 3) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_size_after_pop() {
    std::cout << "[TEST] Min Heap Size After Pop\n";
    core::MinHeap<int> heap{1, 2, 3, 4, 5};
    heap.pop();
    heap.pop();
    std::string result = (heap.size() == 3) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_capacity_initial() {
    std::cout << "[TEST] Min Heap Capacity Initial\n";
    core::MinHeap<int> heap(16);
    std::string result = (heap.capacity() == 16) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_capacity_after_resize() {
    std::cout << "[TEST] Min Heap Capacity After Resize\n";
    core::MinHeap<int> heap(2);
    heap.push(1);
    heap.push(2);
    heap.push(3);  // Should trigger resize
    
    bool size_correct = heap.size() == 3;
    bool capacity_grew = heap.capacity() >= 3;
    
    std::string result = (size_correct && capacity_grew) ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// Push Tests
// =============================================================================

bool min_heap_push_single() {
    std::cout << "[TEST] Min Heap Push Single\n";
    core::MinHeap<int> heap(5);
    heap.push(42);
    
    bool size_one = heap.size() == 1;
    bool correct_value = heap.top() == 42;
    
    std::string result = (size_one && correct_value) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_push_multiple_ascending() {
    std::cout << "[TEST] Min Heap Push Multiple - Ascending\n";
    core::MinHeap<int> heap(10);
    heap.push(1);
    heap.push(2);
    heap.push(3);
    heap.push(4);
    heap.push(5);
    
    std::string result = (heap.top() == 1) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_push_multiple_descending() {
    std::cout << "[TEST] Min Heap Push Multiple - Descending\n";
    core::MinHeap<int> heap(10);
    heap.push(5);
    heap.push(4);
    heap.push(3);
    heap.push(2);
    heap.push(1);
    
    std::string result = (heap.top() == 1) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_push_multiple_random() {
    std::cout << "[TEST] Min Heap Push Multiple - Random\n";
    core::MinHeap<int> heap(10);
    heap.push(7);
    heap.push(2);
    heap.push(9);
    heap.push(1);
    heap.push(5);
    heap.push(3);
    
    std::string result = (heap.top() == 1) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_push_duplicates() {
    std::cout << "[TEST] Min Heap Push Multiple - Duplicates\n";
    core::MinHeap<int> heap(10);
    heap.push(5);
    heap.push(3);
    heap.push(3);
    heap.push(3);
    heap.push(7);
    
    bool size_correct = heap.size() == 5;
    bool min_correct = heap.top() == 3;
    
    std::string result = (size_correct && min_correct) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_push_triggers_resize() {
    std::cout << "[TEST] Min Heap Push Triggers Resize\n";
    core::MinHeap<int> heap(2);
    std::size_t initial_cap = heap.capacity();
    
    heap.push(3);
    heap.push(1);
    heap.push(2);  // Should trigger resize
    heap.push(4);
    
    bool capacity_grew = heap.capacity() > initial_cap;
    bool data_intact = heap.top() == 1 && heap.size() == 4;
    
    std::string result = (capacity_grew && data_intact) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_push_negative_values() {
    std::cout << "[TEST] Min Heap Push Multiple - Negative Values\n";
    core::MinHeap<int> heap(10);
    heap.push(5);
    heap.push(-3);
    heap.push(0);
    heap.push(-10);
    heap.push(2);
    
    std::string result = (heap.top() == -10) ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// Pop Tests
// =============================================================================

bool min_heap_pop_single() {
    std::cout << "[TEST] Min Heap Pop Single\n";
    core::MinHeap<int> heap(5);
    heap.push(42);
    int val = heap.pop();
    
    bool value_correct = val == 42;
    bool now_empty = heap.empty();
    
    std::string result = (value_correct && now_empty) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_pop_returns_minimum() {
    std::cout << "[TEST] Min Heap Pop Returns Minimum\n";
    core::MinHeap<int> heap{7, 2, 9, 1, 5, 3};
    int min_val = heap.pop();
    
    std::string result = (min_val == 1) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_pop_maintains_heap_property() {
    std::cout << "[TEST] Min Heap Pop Maintains Heap Property\n";
    core::MinHeap<int> heap{7, 2, 9, 1, 5, 3};
    
    heap.pop();  // Remove 1
    bool second_min = heap.top() == 2;
    
    heap.pop();  // Remove 2
    bool third_min = heap.top() == 3;
    
    std::string result = (second_min && third_min) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_pop_all_sorted() {
    std::cout << "[TEST] Min Heap Pop All Sorted\n";
    core::MinHeap<int> heap{7, 2, 9, 1, 5, 3, 8, 4, 6};
    
    std::vector<int> sorted;
    while (!heap.empty()) {
        sorted.push_back(heap.pop());
    }
    
    std::vector<int> expected{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::string result = (sorted == expected) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_pop_empty_throws() {
    std::cout << "[TEST] Min Heap Pop empty Throws\n";
    core::MinHeap<int> heap(5);
    
    bool threw = false;
    try {
        heap.pop();
    } catch (const std::runtime_error& e) {
        threw = true;
    }
    
    std::string result = threw ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_pop_with_duplicates() {
    std::cout << "[TEST] Min Heap Pop With Duplicates\n";
    core::MinHeap<int> heap{3, 1, 1, 1, 5};
    
    int first = heap.pop();
    int second = heap.pop();
    int third = heap.pop();
    
    bool all_ones = (first == 1 && second == 1 && third == 1);
    bool next_is_three = heap.top() == 3;
    
    std::string result = (all_ones && next_is_three) ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// Peek Tests
// =============================================================================

bool min_heap_peek_single() {
    std::cout << "[TEST] Min Heap Peek Single\n";
    core::MinHeap<int> heap(5);
    heap.push(42);
    
    std::string result = (heap.top() == 42) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_peek_does_not_remove() {
    std::cout << "[TEST] Min Heap Peek Does Not Remove\n";
    core::MinHeap<int> heap{3, 1, 4};
    
    int first_peek = heap.top();
    int second_peek = heap.top();
    std::size_t size_after = heap.size();
    
    bool same_value = first_peek == second_peek && first_peek == 1;
    bool size_unchanged = size_after == 3;
    
    std::string result = (same_value && size_unchanged) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_peek_after_push() {
    std::cout << "[TEST] Min Heap Peek After Push\n";
    core::MinHeap<int> heap{5, 3, 7};
    
    heap.push(1);  // New minimum
    bool new_min = heap.top() == 1;
    
    heap.push(10);  // Not minimum
    bool still_one = heap.top() == 1;
    
    std::string result = (new_min && still_one) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_peek_after_pop() {
    std::cout << "[TEST] Min Heap Peek After Pop\n";
    core::MinHeap<int> heap{1, 3, 5, 7};
    
    heap.pop();
    
    std::string result = (heap.top() == 3) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_peek_empty_throws() {
    std::cout << "[TEST] Min Heap Peek empty Throws\n";
    core::MinHeap<int> heap(5);
    
    bool threw = false;
    try {
        heap.top();
    } catch (const std::runtime_error& e) {
        threw = true;
    }
    
    std::string result = threw ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// DeleteNode Tests
// =============================================================================

bool min_heap_delete_root() {
    std::cout << "[TEST] Min Heap Delete Root\n";
    core::MinHeap<int> heap{1, 3, 5, 7, 9};
    
    heap.DeleteNode(1);
    
    bool size_correct = heap.size() == 4;
    bool new_min = heap.top() == 3;
    
    std::string result = (size_correct && new_min) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_delete_leaf() {
    std::cout << "[TEST] Min Heap Delete Leaf\n";
    core::MinHeap<int> heap{1, 3, 5, 7, 9};
    
    heap.DeleteNode(9);
    
    bool size_correct = heap.size() == 4;
    bool min_unchanged = heap.top() == 1;
    
    // Verify 9 is gone by extracting all
    std::vector<int> remaining;
    while (!heap.empty()) {
        remaining.push_back(heap.pop());
    }
    bool nine_gone = std::find(remaining.begin(), remaining.end(), 9) == remaining.end();
    
    std::string result = (size_correct && min_unchanged && nine_gone) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_delete_middle() {
    std::cout << "[TEST] Min Heap Delete Middle\n";
    core::MinHeap<int> heap{1, 3, 5, 7, 9};
    
    heap.DeleteNode(5);
    
    bool size_correct = heap.size() == 4;
    
    // Extract all and verify 5 is gone but others remain
    std::vector<int> remaining;
    while (!heap.empty()) {
        remaining.push_back(heap.pop());
    }
    
    std::vector<int> expected{1, 3, 7, 9};
    std::string result = (size_correct && remaining == expected) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_delete_nonexistent() {
    std::cout << "[TEST] Min Heap Delete Non-Existant\n";
    core::MinHeap<int> heap{1, 3, 5, 7, 9};
    
    heap.DeleteNode(100);  // Not in heap
    
    bool size_unchanged = heap.size() == 5;
    bool min_unchanged = heap.top() == 1;
    
    std::string result = (size_unchanged && min_unchanged) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_delete_last_element() {
    std::cout << "[TEST] Min Heap Delete Last Element\n";
    core::MinHeap<int> heap(5);
    heap.push(42);
    
    heap.DeleteNode(42);
    
    std::string result = heap.empty() ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_delete_maintains_heap_property() {
    std::cout << "[TEST] Min Heap Maintains Heap Property\n";
    core::MinHeap<int> heap{10, 20, 30, 40, 50, 25, 35, 45};
    
    heap.DeleteNode(20);
    heap.DeleteNode(40);
    
    // Verify heap property by extracting all in sorted order
    std::vector<int> extracted;
    while (!heap.empty()) {
        extracted.push_back(heap.pop());
    }
    
    std::vector<int> sorted = extracted;
    std::sort(sorted.begin(), sorted.end());
    
    std::string result = (extracted == sorted) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_delete_with_duplicates() {
    std::cout << "[TEST] Min Heap Delete With Duplicates\n";
    core::MinHeap<int> heap{3, 3, 3, 5, 7};
    
    heap.DeleteNode(3);  // Should delete one instance
    
    bool size_correct = heap.size() == 4;
    bool still_has_three = heap.top() == 3;
    
    std::string result = (size_correct && still_has_three) ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// Heap Property Tests
// =============================================================================

bool min_heap_property_after_many_pushes() {
    std::cout << "[TEST] Min Heap Multiple Pushes\n";
    core::MinHeap<int> heap(100);
    
    // Push values in pseudo-random order
    int values[] = {50, 25, 75, 12, 37, 62, 87, 6, 18, 31, 43, 56, 68, 81, 93};
    for (int v : values) {
        heap.push(v);
    }
    
    // Extract all - should come out sorted
    std::vector<int> extracted;
    while (!heap.empty()) {
        extracted.push_back(heap.pop());
    }
    
    std::vector<int> sorted = extracted;
    std::sort(sorted.begin(), sorted.end());
    
    std::string result = (extracted == sorted) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_property_after_mixed_operations() {
    std::cout << "[TEST] Min Heap Multiple Operations\n";
    core::MinHeap<int> heap(20);
    
    // Mix of pushes, pops, and deletes
    heap.push(50);
    heap.push(30);
    heap.push(70);
    heap.pop();         // Remove 30
    heap.push(20);
    heap.push(60);
    heap.DeleteNode(70);
    heap.push(40);
    heap.push(10);
    heap.pop();         // Remove 10
    heap.push(55);
    
    // Extract all - should come out sorted
    std::vector<int> extracted;
    while (!heap.empty()) {
        extracted.push_back(heap.pop());
    }
    
    std::vector<int> sorted = extracted;
    std::sort(sorted.begin(), sorted.end());
    
    std::string result = (extracted == sorted) ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// Comprehensive Tests
// =============================================================================

bool min_heap_comprehensive_stress_test() {
    std::cout << "[TEST] Min Heap Comprehensive\n";
    core::MinHeap<int> heap(10);
    
    // Insert 100 elements
    for (int i = 100; i >= 1; --i) {
        heap.push(i);
    }
    
    bool size_correct = heap.size() == 100;
    bool min_correct = heap.top() == 1;
    
    // Delete some elements
    heap.DeleteNode(50);
    heap.DeleteNode(25);
    heap.DeleteNode(75);
    
    // Pop half
    for (int i = 0; i < 48; ++i) {
        heap.pop();
    }
    
    bool size_after = heap.size() == 49;
    
    // Verify remaining elements come out sorted
    std::vector<int> remaining;
    while (!heap.empty()) {
        remaining.push_back(heap.pop());
    }
    
    std::vector<int> sorted = remaining;
    std::sort(sorted.begin(), sorted.end());
    
    bool sorted_correct = remaining == sorted;
    
    std::string result = (size_correct && min_correct && size_after && sorted_correct) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_heapsort_verification() {
    std::cout << "[TEST] Min Heap Heapsort Verficiations\n";
    
    std::vector<int> input{64, 34, 25, 12, 22, 11, 90, 1, 45, 33, 21, 88, 5, 72, 16};
    core::MinHeap<int> heap(input.size());
    
    for (int v : input) {
        heap.push(v);
    }
    
    std::vector<int> heapsorted;
    while (!heap.empty()) {
        heapsorted.push_back(heap.pop());
    }
    
    std::vector<int> stdsorted = input;
    std::sort(stdsorted.begin(), stdsorted.end());
    
    std::string result = (heapsorted == stdsorted) ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// to_string Tests
// =============================================================================


bool min_heap_to_string_empty() {
    std::cout << "[TEST] Min Heap to_string - empty\n";
    core::MinHeap<int> heap(5);
    return test_helper("", heap.to_string());
}

bool min_heap_to_string_single() {
    std::cout << "[TEST] Min Heap to_string - Single\n";
    core::MinHeap<int> heap(5);
    heap.push(42);
    return test_helper("42", heap.to_string());
}

bool min_heap_to_string_multiple() {
    std::cout << "[TEST] Min Heap to_string - Multiple\n";
    core::MinHeap<int> heap(10);
    heap.push(5);
    heap.push(3);
    heap.push(8);
    heap.push(1);
    
    return test_helper("1 3 5 8", heap.to_string());
}

bool min_heap_to_string_after_pop() {
    std::cout << "[TEST] Min Heap to_string - After Pop\n";
    core::MinHeap<int> heap{1, 2, 3};
    heap.pop();
    
    return test_helper("2 3", heap.to_string());
}

bool min_heap_to_string_negative_values() {
    std::cout << "[TEST] Min Heap to_string - Negative Values\n";
    core::MinHeap<int> heap{5, -3, 0, -10};

    return test_helper("-10 -3 0 5", heap.to_string());
}

// =============================================================================
// operator<< Tests
// =============================================================================

bool min_heap_ostream_empty() {
    std::cout << "[TEST] Min Heap ostream - empty\n";
    core::MinHeap<int> heap(5);
    std::ostringstream oss;
    oss << heap;
    return test_helper("", oss.str());
}

bool min_heap_ostream_single() {
    std::cout << "[TEST] Min Heap ostream - Single\n";
    core::MinHeap<int> heap(5);
    heap.push(42);
    std::ostringstream oss;
    oss << heap;
    return test_helper("42", oss.str());
}

bool min_heap_ostream_multiple() {
    std::cout << "[TEST] Min Heap ostream - Multiple\n";
    core::MinHeap<int> heap{1, 3, 5, 7, 9, 2, 4, 6, 8, 11, 13, 15, 12, 14, 16, -1, -2, -3, 0, 0, 0};
    std::ostringstream oss;
    oss << heap;

    return test_helper("-3 -2 -1 0 0 0 1 2 3 4 5 6 7 8 9 11 12 13 14 15 16", oss.str());
}

bool min_heap_ostream_matches_to_string() {
    std::cout << "[TEST] Min Heap ostream - Matches to_string\n";
    core::MinHeap<int> heap{1, 3, 5, 7, 9, 2, 4, 6, 8, 11, 13, 15, 12, 14, 16, -1, -2, -3, 0, 0, 0};
    
    std::ostringstream oss;
    oss << heap;
    
    std::string result = (oss.str() == heap.to_string()) ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// operator>> Tests
// =============================================================================

bool min_heap_istream_empty_brackets() {
    std::cout << "[TEST] Min Heap istream - empty Brackets\n";
    core::MinHeap<int> heap(5);
    std::istringstream iss("[]");
    iss >> heap;
    
    std::string result = heap.empty() ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_istream_single() {
    std::cout << "[TEST] Min Heap istream - Single\n";
    core::MinHeap<int> heap(5);
    std::istringstream iss("[42]");
    iss >> heap;
    
    bool size_one = heap.size() == 1;
    bool value_correct = heap.top() == 42;
    
    std::string result = (size_one && value_correct) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_istream_multiple() {
    std::cout << "[TEST] Min Heap istream - Multiple\n";
    core::MinHeap<int> heap(10);
    std::istringstream iss("[5, 3, 8, 1, 9]");
    iss >> heap;
    
    bool size_correct = heap.size() == 5;
    bool min_correct = heap.top() == 1;
    
    std::string result = (size_correct && min_correct) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_istream_maintains_heap_property() {
    std::cout << "[TEST] Min Heap istream - Maintains Heap Property\n";
    core::MinHeap<int> heap(10);
    std::istringstream iss("[9, 7, 5, 3, 1]");
    iss >> heap;
    
    std::vector<int> extracted;
    while (!heap.empty()) {
        extracted.push_back(heap.pop());
    }
    
    std::vector<int> expected{1, 3, 5, 7, 9};
    std::string result = (extracted == expected) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_istream_overwrites_existing() {
    std::cout << "[TEST] Min Heap istream - Overwrites Existing\n";
    core::MinHeap<int> heap{100, 200, 300};
    
    std::istringstream iss("[1, 2]");
    iss >> heap;
    
    bool size_correct = heap.size() == 2;
    bool old_data_gone = heap.top() == 1;
    
    std::vector<int> extracted;
    while (!heap.empty()) {
        extracted.push_back(heap.pop());
    }
    std::vector<int> expected{1, 2};
    
    std::string result = (size_correct && old_data_gone && extracted == expected) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_istream_whitespace_handling() {
    std::cout << "[TEST] Min Heap istream - Whitespace Handling\n";
    core::MinHeap<int> heap(10);
    std::istringstream iss("  [  5 ,  3  ,  8  ]  ");
    iss >> heap;
    
    bool size_correct = heap.size() == 3;
    bool min_correct = heap.top() == 3;
    
    std::string result = (size_correct && min_correct) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_istream_no_brackets() {
    std::cout << "[TEST] Min Heap istream - No Brackets\n";
    core::MinHeap<int> heap(10);
    std::istringstream iss("5 3 8 1");
    iss >> heap;
    
    bool has_elements = heap.size() == 4;
    bool min_correct = heap.top() == 1;
    
    std::string result = (has_elements && min_correct) ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// Roundtrip Test
// =============================================================================

bool min_heap_roundtrip_test() {
    std::cout << "[TEST] Min Heap Roundtrip\n";
    
    core::MinHeap<int> original{7, 2, 9, 1, 5, 3, 8};
    
    std::ostringstream oss;
    oss << original;
    
    core::MinHeap<int> restored(10);
    std::istringstream iss(oss.str());
    iss >> restored;
    
    std::vector<int> orig_sorted, rest_sorted;
    
    core::MinHeap<int> orig_copy(original);
    while (!orig_copy.empty()) {
        orig_sorted.push_back(orig_copy.pop());
    }
    
    while (!restored.empty()) {
        rest_sorted.push_back(restored.pop());
    }
    
    std::string result = (orig_sorted == rest_sorted) ? "true" : "false";
    return test_helper("true", result);
}