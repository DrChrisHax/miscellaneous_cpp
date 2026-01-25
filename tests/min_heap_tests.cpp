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
    std::string result = (heap.Empty() && heap.Size() == 0) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_explicit_capacity() {
    std::cout << "[TEST] Min Heap Constructor - Explicit Capacity";
    core::MinHeap<int> heap(10);
    std::string result = (heap.Empty() && heap.Size() == 0 && heap.Capacity() == 10) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_copy() {
    std::cout << "[TEST] Min Heap Copy Constructor - Normal\n";
    core::MinHeap<int> original(10);
    original.Push(5);
    original.Push(3);
    original.Push(8);
    
    core::MinHeap<int> copy(original);
    
    // Verify copy has same values
    bool same_size = copy.Size() == original.Size();
    bool same_min = copy.Peek() == original.Peek();
    
    // Verify independence - modify original
    original.Pop();
    bool independent = copy.Size() == 3 && original.Size() == 2;
    
    std::string result = (same_size && same_min && independent) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_copy_empty() {
    std::cout << "[TEST] Min Heap Copy Constructor - Empty\n";
    core::MinHeap<int> original(5);
    core::MinHeap<int> copy(original);
    
    std::string result = (copy.Empty() && copy.Capacity() == original.Capacity()) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_move() {
    std::cout << "[TEST] Min Heap Move Constructor - Normal\n";
    core::MinHeap<int> original(10);
    original.Push(5);
    original.Push(3);
    original.Push(8);
    
    std::size_t orig_size = original.Size();
    int orig_min = original.Peek();
    
    core::MinHeap<int> moved(std::move(original));
    
    bool correct_size = moved.Size() == orig_size;
    bool correct_min = moved.Peek() == orig_min;
    bool original_empty = original.Size() == 0;
    
    std::string result = (correct_size && correct_min && original_empty) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_move_empty() {
    std::cout << "[TEST] Min Heap Move Constructor - Empty\n";
    core::MinHeap<int> original(5);
    core::MinHeap<int> moved(std::move(original));
    
    std::string result = (moved.Empty()) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_initializer_list() {
    std::cout << "[TEST] Min Heap Initializer List Constructor - Normal\n";
    core::MinHeap<int> heap{5, 3, 8, 1, 9};
    
    bool correct_size = heap.Size() == 5;
    bool correct_min = heap.Peek() == 1;
    
    std::string result = (correct_size && correct_min) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_constructor_initializer_list_empty() {
    std::cout << "[TEST] Min Heap Initializer List Constructor - Empty\n";
    core::MinHeap<int> heap{};
    
    std::string result = heap.Empty() ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// Assignment Operator Tests
// =============================================================================

bool min_heap_assignment_copy() {
    std::cout << "[TEST] Min Heap Copy Assignment Operator - Normal\n";
    core::MinHeap<int> original{5, 3, 8, 1};
    core::MinHeap<int> copy(2);
    copy.Push(100);
    
    copy = original;
    
    bool same_size = copy.Size() == original.Size();
    bool same_min = copy.Peek() == original.Peek();
    
    // Verify independence
    original.Pop();
    bool independent = copy.Size() == 4 && original.Size() == 3;
    
    std::string result = (same_size && same_min && independent) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_assignment_copy_empty() {
    std::cout << "[TEST] Min Heap Copy Assignment OPerator - Empty\n";
    core::MinHeap<int> original(5);
    core::MinHeap<int> copy{1, 2, 3};
    
    copy = original;
    
    std::string result = copy.Empty() ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_assignment_copy_self() {
    std::cout << "[TEST] Min Heap Copy Assignment Operator - Self\n";
    core::MinHeap<int> heap{5, 3, 8, 1};
    
    heap = heap;  // Self-assignment
    
    bool correct_size = heap.Size() == 4;
    bool correct_min = heap.Peek() == 1;
    
    std::string result = (correct_size && correct_min) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_assignment_move() {
    std::cout << "[TEST] Min Heap Move Assignment Operator - Normal\n";
    core::MinHeap<int> original{5, 3, 8, 1};
    core::MinHeap<int> target(2);
    target.Push(100);
    
    std::size_t orig_size = original.Size();
    int orig_min = original.Peek();
    
    target = std::move(original);
    
    bool correct_size = target.Size() == orig_size;
    bool correct_min = target.Peek() == orig_min;
    
    std::string result = (correct_size && correct_min) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_assignment_move_empty() {
    std::cout << "[TEST] Min Heap Move Assignment Operator - Empty\n";
    core::MinHeap<int> original(5);
    core::MinHeap<int> target{1, 2, 3};
    
    target = std::move(original);
    
    std::string result = target.Empty() ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_assignment_move_self() {
    std::cout << "[TEST] Min Heap Move Assignment Operator - Self\n";
    core::MinHeap<int> heap{5, 3, 8, 1};
    
    heap = std::move(heap);  // Self-assignment
    
    // After self-move, behavior is implementation-defined but shouldn't crash
    // Just verify it doesn't crash and has reasonable state
    std::string result = "true";  // If we get here without crash, pass
    return test_helper("true", result);
}

// =============================================================================
// Basic State Tests
// =============================================================================

bool min_heap_empty_on_new() {
    std::cout << "[TEST] Min Heap Empty On New\n";
    core::MinHeap<int> heap(5);
    std::string result = heap.Empty() ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_empty_after_pop_all() {
    std::cout << "[TEST] Min Heap Empty After Pop All\n";
    core::MinHeap<int> heap{1, 2, 3};
    heap.Pop();
    heap.Pop();
    heap.Pop();
    std::string result = heap.Empty() ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_size_after_push() {
    std::cout << "[TEST] Min Heap Size After Push\n";
    core::MinHeap<int> heap(5);
    heap.Push(1);
    heap.Push(2);
    heap.Push(3);
    std::string result = (heap.Size() == 3) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_size_after_pop() {
    std::cout << "[TEST] Min Heap Size After Pop\n";
    core::MinHeap<int> heap{1, 2, 3, 4, 5};
    heap.Pop();
    heap.Pop();
    std::string result = (heap.Size() == 3) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_capacity_initial() {
    std::cout << "[TEST] Min Heap Capacity Initial\n";
    core::MinHeap<int> heap(16);
    std::string result = (heap.Capacity() == 16) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_capacity_after_resize() {
    std::cout << "[TEST] Min Heap Capacity After Resize\n";
    core::MinHeap<int> heap(2);
    heap.Push(1);
    heap.Push(2);
    heap.Push(3);  // Should trigger resize
    
    bool size_correct = heap.Size() == 3;
    bool capacity_grew = heap.Capacity() >= 3;
    
    std::string result = (size_correct && capacity_grew) ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// Push Tests
// =============================================================================

bool min_heap_push_single() {
    std::cout << "[TEST] Min Heap Push Single\n";
    core::MinHeap<int> heap(5);
    heap.Push(42);
    
    bool size_one = heap.Size() == 1;
    bool correct_value = heap.Peek() == 42;
    
    std::string result = (size_one && correct_value) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_push_multiple_ascending() {
    std::cout << "[TEST] Min Heap Push Multiple - Ascending\n";
    core::MinHeap<int> heap(10);
    heap.Push(1);
    heap.Push(2);
    heap.Push(3);
    heap.Push(4);
    heap.Push(5);
    
    std::string result = (heap.Peek() == 1) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_push_multiple_descending() {
    std::cout << "[TEST] Min Heap Push Multiple - Descending\n";
    core::MinHeap<int> heap(10);
    heap.Push(5);
    heap.Push(4);
    heap.Push(3);
    heap.Push(2);
    heap.Push(1);
    
    std::string result = (heap.Peek() == 1) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_push_multiple_random() {
    std::cout << "[TEST] Min Heap Push Multiple - Random\n";
    core::MinHeap<int> heap(10);
    heap.Push(7);
    heap.Push(2);
    heap.Push(9);
    heap.Push(1);
    heap.Push(5);
    heap.Push(3);
    
    std::string result = (heap.Peek() == 1) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_push_duplicates() {
    std::cout << "[TEST] Min Heap Push Multiple - Duplicates\n";
    core::MinHeap<int> heap(10);
    heap.Push(5);
    heap.Push(3);
    heap.Push(3);
    heap.Push(3);
    heap.Push(7);
    
    bool size_correct = heap.Size() == 5;
    bool min_correct = heap.Peek() == 3;
    
    std::string result = (size_correct && min_correct) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_push_triggers_resize() {
    std::cout << "[TEST] Min Heap Push Triggers Resize\n";
    core::MinHeap<int> heap(2);
    std::size_t initial_cap = heap.Capacity();
    
    heap.Push(3);
    heap.Push(1);
    heap.Push(2);  // Should trigger resize
    heap.Push(4);
    
    bool capacity_grew = heap.Capacity() > initial_cap;
    bool data_intact = heap.Peek() == 1 && heap.Size() == 4;
    
    std::string result = (capacity_grew && data_intact) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_push_negative_values() {
    std::cout << "[TEST] Min Heap Push Multiple - Negative Values\n";
    core::MinHeap<int> heap(10);
    heap.Push(5);
    heap.Push(-3);
    heap.Push(0);
    heap.Push(-10);
    heap.Push(2);
    
    std::string result = (heap.Peek() == -10) ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// Pop Tests
// =============================================================================

bool min_heap_pop_single() {
    std::cout << "[TEST] Min Heap Pop Single\n";
    core::MinHeap<int> heap(5);
    heap.Push(42);
    int val = heap.Pop();
    
    bool value_correct = val == 42;
    bool now_empty = heap.Empty();
    
    std::string result = (value_correct && now_empty) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_pop_returns_minimum() {
    std::cout << "[TEST] Min Heap Pop Returns Minimum\n";
    core::MinHeap<int> heap{7, 2, 9, 1, 5, 3};
    int min_val = heap.Pop();
    
    std::string result = (min_val == 1) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_pop_maintains_heap_property() {
    std::cout << "[TEST] Min Heap Pop Maintains Heap Property\n";
    core::MinHeap<int> heap{7, 2, 9, 1, 5, 3};
    
    heap.Pop();  // Remove 1
    bool second_min = heap.Peek() == 2;
    
    heap.Pop();  // Remove 2
    bool third_min = heap.Peek() == 3;
    
    std::string result = (second_min && third_min) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_pop_all_sorted() {
    std::cout << "[TEST] Min Heap Pop All Sorted\n";
    core::MinHeap<int> heap{7, 2, 9, 1, 5, 3, 8, 4, 6};
    
    std::vector<int> sorted;
    while (!heap.Empty()) {
        sorted.push_back(heap.Pop());
    }
    
    std::vector<int> expected{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::string result = (sorted == expected) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_pop_empty_throws() {
    std::cout << "[TEST] Min Heap Pop Empty Throws\n";
    core::MinHeap<int> heap(5);
    
    bool threw = false;
    try {
        heap.Pop();
    } catch (const std::runtime_error& e) {
        threw = true;
    }
    
    std::string result = threw ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_pop_with_duplicates() {
    std::cout << "[TEST] Min Heap Pop With Duplicates\n";
    core::MinHeap<int> heap{3, 1, 1, 1, 5};
    
    int first = heap.Pop();
    int second = heap.Pop();
    int third = heap.Pop();
    
    bool all_ones = (first == 1 && second == 1 && third == 1);
    bool next_is_three = heap.Peek() == 3;
    
    std::string result = (all_ones && next_is_three) ? "true" : "false";
    return test_helper("true", result);
}

// =============================================================================
// Peek Tests
// =============================================================================

bool min_heap_peek_single() {
    std::cout << "[TEST] Min Heap Peek Single\n";
    core::MinHeap<int> heap(5);
    heap.Push(42);
    
    std::string result = (heap.Peek() == 42) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_peek_does_not_remove() {
    std::cout << "[TEST] Min Heap Peek Does Not Remove\n";
    core::MinHeap<int> heap{3, 1, 4};
    
    int first_peek = heap.Peek();
    int second_peek = heap.Peek();
    std::size_t size_after = heap.Size();
    
    bool same_value = first_peek == second_peek && first_peek == 1;
    bool size_unchanged = size_after == 3;
    
    std::string result = (same_value && size_unchanged) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_peek_after_push() {
    std::cout << "[TEST] Min Heap Peek After Push\n";
    core::MinHeap<int> heap{5, 3, 7};
    
    heap.Push(1);  // New minimum
    bool new_min = heap.Peek() == 1;
    
    heap.Push(10);  // Not minimum
    bool still_one = heap.Peek() == 1;
    
    std::string result = (new_min && still_one) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_peek_after_pop() {
    std::cout << "[TEST] Min Heap Peek After Pop\n";
    core::MinHeap<int> heap{1, 3, 5, 7};
    
    heap.Pop();
    
    std::string result = (heap.Peek() == 3) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_peek_empty_throws() {
    std::cout << "[TEST] Min Heap Peek Empty Throws\n";
    core::MinHeap<int> heap(5);
    
    bool threw = false;
    try {
        heap.Peek();
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
    
    bool size_correct = heap.Size() == 4;
    bool new_min = heap.Peek() == 3;
    
    std::string result = (size_correct && new_min) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_delete_leaf() {
    std::cout << "[TEST] Min Heap Delete Leaf\n";
    core::MinHeap<int> heap{1, 3, 5, 7, 9};
    
    heap.DeleteNode(9);
    
    bool size_correct = heap.Size() == 4;
    bool min_unchanged = heap.Peek() == 1;
    
    // Verify 9 is gone by extracting all
    std::vector<int> remaining;
    while (!heap.Empty()) {
        remaining.push_back(heap.Pop());
    }
    bool nine_gone = std::find(remaining.begin(), remaining.end(), 9) == remaining.end();
    
    std::string result = (size_correct && min_unchanged && nine_gone) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_delete_middle() {
    std::cout << "[TEST] Min Heap Delete Middle\n";
    core::MinHeap<int> heap{1, 3, 5, 7, 9};
    
    heap.DeleteNode(5);
    
    bool size_correct = heap.Size() == 4;
    
    // Extract all and verify 5 is gone but others remain
    std::vector<int> remaining;
    while (!heap.Empty()) {
        remaining.push_back(heap.Pop());
    }
    
    std::vector<int> expected{1, 3, 7, 9};
    std::string result = (size_correct && remaining == expected) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_delete_nonexistent() {
    std::cout << "[TEST] Min Heap Delete Non-Existant\n";
    core::MinHeap<int> heap{1, 3, 5, 7, 9};
    
    heap.DeleteNode(100);  // Not in heap
    
    bool size_unchanged = heap.Size() == 5;
    bool min_unchanged = heap.Peek() == 1;
    
    std::string result = (size_unchanged && min_unchanged) ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_delete_last_element() {
    std::cout << "[TEST] Min Heap Delete Last Element\n";
    core::MinHeap<int> heap(5);
    heap.Push(42);
    
    heap.DeleteNode(42);
    
    std::string result = heap.Empty() ? "true" : "false";
    return test_helper("true", result);
}

bool min_heap_delete_maintains_heap_property() {
    std::cout << "[TEST] Min Heap Maintains Heap Property\n";
    core::MinHeap<int> heap{10, 20, 30, 40, 50, 25, 35, 45};
    
    heap.DeleteNode(20);
    heap.DeleteNode(40);
    
    // Verify heap property by extracting all in sorted order
    std::vector<int> extracted;
    while (!heap.Empty()) {
        extracted.push_back(heap.Pop());
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
    
    bool size_correct = heap.Size() == 4;
    bool still_has_three = heap.Peek() == 3;
    
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
        heap.Push(v);
    }
    
    // Extract all - should come out sorted
    std::vector<int> extracted;
    while (!heap.Empty()) {
        extracted.push_back(heap.Pop());
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
    heap.Push(50);
    heap.Push(30);
    heap.Push(70);
    heap.Pop();         // Remove 30
    heap.Push(20);
    heap.Push(60);
    heap.DeleteNode(70);
    heap.Push(40);
    heap.Push(10);
    heap.Pop();         // Remove 10
    heap.Push(55);
    
    // Extract all - should come out sorted
    std::vector<int> extracted;
    while (!heap.Empty()) {
        extracted.push_back(heap.Pop());
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
        heap.Push(i);
    }
    
    bool size_correct = heap.Size() == 100;
    bool min_correct = heap.Peek() == 1;
    
    // Delete some elements
    heap.DeleteNode(50);
    heap.DeleteNode(25);
    heap.DeleteNode(75);
    
    // Pop half
    for (int i = 0; i < 48; ++i) {
        heap.Pop();
    }
    
    bool size_after = heap.Size() == 49;
    
    // Verify remaining elements come out sorted
    std::vector<int> remaining;
    while (!heap.Empty()) {
        remaining.push_back(heap.Pop());
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
        heap.Push(v);
    }
    
    std::vector<int> heapsorted;
    while (!heap.Empty()) {
        heapsorted.push_back(heap.Pop());
    }
    
    std::vector<int> stdsorted = input;
    std::sort(stdsorted.begin(), stdsorted.end());
    
    std::string result = (heapsorted == stdsorted) ? "true" : "false";
    return test_helper("true", result);
}