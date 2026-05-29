#pragma once

#include "test_helpers.hpp"

#include "BinaryTree.hpp"
#include "TreeGenerator.hpp"

using namespace core;

// =============================================================================
// Constructor and Destructor Tests
// =============================================================================

test_result binary_tree_constructor_default() {
    BinaryTree<int> tree;
    std::string expected = "Empty: true\nSize: 0\nRoot: nullptr";
    std::string result = "Empty: " + std::string(tree.Empty() ? "true" : "false") +
                         "\nSize: " + std::to_string(tree.Size()) +
                         "\nRoot: " + std::string(tree.Root() == nullptr ? "nullptr" : "exists");
    return test_result(expected, result);
}

test_result binary_tree_destructor() {
    // Test that destructor runs without crashing on various tree sizes
    {
        auto empty = EmptyTree<BinaryTree<int>>();
    }
    {
        auto one = OneElementTree<BinaryTree<int>>();
    }
    {
        auto balanced = BalancedTree<BinaryTree<int>>(15);
    }
    {
        auto worst = WorstUnbalancedTree<BinaryTree<int>>(10);
    }
    std::string expected = "All destructors ran";
    std::string result = "All destructors ran";
    return test_result(expected, result);
}

// =============================================================================
// Move Constructor and Assignment Tests
// =============================================================================

test_result binary_tree_move_constructor() {
    auto original = BalancedTree<BinaryTree<int>>(7);
    
    BinaryTree<int> moved(std::move(original));
    
    std::string expected = "Moved Size: 7\nMoved Empty: false\nOriginal Size: 0\nOriginal Empty: true";
    std::string result = "Moved Size: " + std::to_string(moved.Size()) +
                         "\nMoved Empty: " + std::string(moved.Empty() ? "true" : "false") +
                         "\nOriginal Size: " + std::to_string(original.Size()) +
                         "\nOriginal Empty: " + std::string(original.Empty() ? "true" : "false");
    return test_result(expected, result);
}

test_result binary_tree_move_assignment() {
    auto original = BalancedTree<BinaryTree<int>>(7);
    BinaryTree<int> assigned;
    assigned.Insert(100);
    
    assigned = std::move(original);
    
    std::string expected = "Assigned Size: 7\nAssigned Contains 4: true\nOriginal Size: 0";
    std::string result = "Assigned Size: " + std::to_string(assigned.Size()) +
                         "\nAssigned Contains 4: " + std::string(assigned.Contains(4) ? "true" : "false") +
                         "\nOriginal Size: " + std::to_string(original.Size());
    return test_result(expected, result);
}

test_result binary_tree_move_assignment_self() {
    auto tree = BalancedTree<BinaryTree<int>>(7);

    auto& ref = tree;
    tree = std::move(ref); // Self assignment
    
    std::string expected = "Size: 7\nContains 4: true";
    std::string result = "Size: " + std::to_string(tree.Size()) +
                         "\nContains 4: " + std::string(tree.Contains(4) ? "true" : "false");
    return test_result(expected, result);
}