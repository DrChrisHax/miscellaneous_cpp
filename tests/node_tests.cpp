#include "tests.h"
#include "Nodes.hpp"

#include <sstream>

using namespace core;

// =============================================================================
// SL_Node Tests
// =============================================================================

bool node_sl_node_to_string_ref() {
    std::cout << "[TEST] SL_Node - to_string (reference)" << std::endl;
    SL_Node<int> node{42, nullptr};
    
    std::string expected = "(42)";
    std::string result = to_string(node);
    return test_helper(expected, result);
}

bool node_sl_node_to_string_ptr() {
    std::cout << "[TEST] SL_Node - to_string (pointer)" << std::endl;
    SL_Node<int>* node = new SL_Node<int>{42, nullptr};
    
    std::string expected = "(42)";
    std::string result = to_string(node);
    
    delete node;
    return test_helper(expected, result);
}

bool node_sl_node_ostream_ref() {
    std::cout << "[TEST] SL_Node - operator<< (reference)" << std::endl;
    SL_Node<std::string> node{"hello", nullptr};
    
    std::ostringstream oss;
    oss << node;
    
    std::string expected = "(hello)";
    std::string result = oss.str();
    return test_helper(expected, result);
}

bool node_sl_node_ostream_ptr() {
    std::cout << "[TEST] SL_Node - operator<< (pointer)" << std::endl;
    SL_Node<std::string>* node = new SL_Node<std::string>{"hello", nullptr};
    
    std::ostringstream oss;
    oss << node;
    
    std::string expected = "(hello)";
    std::string result = oss.str();
    
    delete node;
    return test_helper(expected, result);
}

// =============================================================================
// DL_Node Tests
// =============================================================================

bool node_dl_node_to_string_ref() {
    std::cout << "[TEST] DL_Node - to_string (reference)" << std::endl;
    DL_Node<int> node{99, nullptr, nullptr};
    
    std::string expected = "(99)";
    std::string result = to_string(node);
    return test_helper(expected, result);
}

bool node_dl_node_to_string_ptr() {
    std::cout << "[TEST] DL_Node - to_string (pointer)" << std::endl;
    DL_Node<int>* node = new DL_Node<int>{99, nullptr, nullptr};
    
    std::string expected = "(99)";
    std::string result = to_string(node);
    
    delete node;
    return test_helper(expected, result);
}

bool node_dl_node_ostream_ref() {
    std::cout << "[TEST] DL_Node - operator<< (reference)" << std::endl;
    DL_Node<double> node{3.14, nullptr, nullptr};
    
    std::ostringstream oss;
    oss << node;
    
    std::string expected = "(3.14)";
    std::string result = oss.str();
    return test_helper(expected, result);
}

bool node_dl_node_ostream_ptr() {
    std::cout << "[TEST] DL_Node - operator<< (pointer)" << std::endl;
    DL_Node<double>* node = new DL_Node<double>{3.14, nullptr, nullptr};
    
    std::ostringstream oss;
    oss << node;
    
    std::string expected = "(3.14)";
    std::string result = oss.str();
    
    delete node;
    return test_helper(expected, result);
}

// =============================================================================
// SL_KV_Node Tests
// =============================================================================

bool node_sl_kv_node_to_string_ref() {
    std::cout << "[TEST] SL_KV_Node - to_string (reference)" << std::endl;
    SL_KV_Node<int, std::string> node{1, "one", nullptr};
    
    std::string expected = "(1, one)";
    std::string result = to_string(node);
    return test_helper(expected, result);
}

bool node_sl_kv_node_to_string_ptr() {
    std::cout << "[TEST] SL_KV_Node - to_string (pointer)" << std::endl;
    SL_KV_Node<int, std::string>* node = new SL_KV_Node<int, std::string>{1, "one", nullptr};
    
    std::string expected = "(1, one)";
    std::string result = to_string(node);
    
    delete node;
    return test_helper(expected, result);
}

bool node_sl_kv_node_ostream_ref() {
    std::cout << "[TEST] SL_KV_Node - operator<< (reference)" << std::endl;
    SL_KV_Node<std::string, int> node{"key", 42, nullptr};
    
    std::ostringstream oss;
    oss << node;
    
    std::string expected = "(key, 42)";
    std::string result = oss.str();
    return test_helper(expected, result);
}

bool node_sl_kv_node_ostream_ptr() {
    std::cout << "[TEST] SL_KV_Node - operator<< (pointer)" << std::endl;
    SL_KV_Node<std::string, int>* node = new SL_KV_Node<std::string, int>{"key", 42, nullptr};
    
    std::ostringstream oss;
    oss << node;
    
    std::string expected = "(key, 42)";
    std::string result = oss.str();
    
    delete node;
    return test_helper(expected, result);
}

// =============================================================================
// DL_KV_Node Tests
// =============================================================================

bool node_dl_kv_node_to_string_ref() {
    std::cout << "[TEST] DL_KV_Node - to_string (reference)" << std::endl;
    DL_KV_Node<int, std::string> node{100, "hundred", nullptr, nullptr};
    
    std::string expected = "(100, hundred)";
    std::string result = to_string(node);
    return test_helper(expected, result);
}

bool node_dl_kv_node_to_string_ptr() {
    std::cout << "[TEST] DL_KV_Node - to_string (pointer)" << std::endl;
    DL_KV_Node<int, std::string>* node = new DL_KV_Node<int, std::string>{100, "hundred", nullptr, nullptr};
    
    std::string expected = "(100, hundred)";
    std::string result = to_string(node);
    
    delete node;
    return test_helper(expected, result);
}

bool node_dl_kv_node_ostream_ref() {
    std::cout << "[TEST] DL_KV_Node - operator<< (reference)" << std::endl;
    DL_KV_Node<char, int> node{'A', 65, nullptr, nullptr};
    
    std::ostringstream oss;
    oss << node;
    
    std::string expected = "(A, 65)";
    std::string result = oss.str();
    return test_helper(expected, result);
}

bool node_dl_kv_node_ostream_ptr() {
    std::cout << "[TEST] DL_KV_Node - operator<< (pointer)" << std::endl;
    DL_KV_Node<char, int>* node = new DL_KV_Node<char, int>{'A', 65, nullptr, nullptr};
    
    std::ostringstream oss;
    oss << node;
    
    std::string expected = "(A, 65)";
    std::string result = oss.str();
    
    delete node;
    return test_helper(expected, result);
}

// =============================================================================
// TreeNode Tests
// =============================================================================

bool node_tree_node_to_string_ref() {
    std::cout << "[TEST] TreeNode - to_string (reference)" << std::endl;
    TreeNode<int> node{50, nullptr, nullptr};
    
    std::string expected = "(50)";
    std::string result = to_string(node);
    return test_helper(expected, result);
}

bool node_tree_node_to_string_ptr() {
    std::cout << "[TEST] TreeNode - to_string (pointer)" << std::endl;
    TreeNode<int>* node = new TreeNode<int>{50, nullptr, nullptr};
    
    std::string expected = "(50)";
    std::string result = to_string(node);
    
    delete node;
    return test_helper(expected, result);
}

bool node_tree_node_ostream_ref() {
    std::cout << "[TEST] TreeNode - operator<< (reference)" << std::endl;
    TreeNode<std::string> node{"root", nullptr, nullptr};
    
    std::ostringstream oss;
    oss << node;
    
    std::string expected = "(root)";
    std::string result = oss.str();
    return test_helper(expected, result);
}

bool node_tree_node_ostream_ptr() {
    std::cout << "[TEST] TreeNode - operator<< (pointer)" << std::endl;
    TreeNode<std::string>* node = new TreeNode<std::string>{"root", nullptr, nullptr};
    
    std::ostringstream oss;
    oss << node;
    
    std::string expected = "(root)";
    std::string result = oss.str();
    
    delete node;
    return test_helper(expected, result);
}

// =============================================================================
// RB_TreeNode Tests
// =============================================================================

bool node_rb_tree_node_to_string_ref() {
    std::cout << "[TEST] RB_TreeNode - to_string (reference)" << std::endl;
    RB_TreeNode<int> red_node{25, nullptr, nullptr, true};
    RB_TreeNode<int> black_node{75, nullptr, nullptr, false};
    
    std::string expected = "(R 25) (B 75)";
    std::string result = to_string(red_node) + " " + to_string(black_node);
    return test_helper(expected, result);
}

bool node_rb_tree_node_to_string_ptr() {
    std::cout << "[TEST] RB_TreeNode - to_string (pointer)" << std::endl;
    RB_TreeNode<int>* red_node = new RB_TreeNode<int>{25, nullptr, nullptr, true};
    RB_TreeNode<int>* black_node = new RB_TreeNode<int>{75, nullptr, nullptr, false};
    
    std::string expected = "(R 25) (B 75)";
    std::string result = to_string(red_node) + " " + to_string(black_node);
    
    delete red_node;
    delete black_node;
    return test_helper(expected, result);
}

bool node_rb_tree_node_ostream_ref() {
    std::cout << "[TEST] RB_TreeNode - operator<< (reference)" << std::endl;
    RB_TreeNode<int> red_node{10, nullptr, nullptr, true};
    RB_TreeNode<int> black_node{20, nullptr, nullptr, false};
    
    std::ostringstream oss;
    oss << red_node << " " << black_node;
    
    std::string expected = "(R 10) (B 20)";
    std::string result = oss.str();
    return test_helper(expected, result);
}

bool node_rb_tree_node_ostream_ptr() {
    std::cout << "[TEST] RB_TreeNode - operator<< (pointer)" << std::endl;
    RB_TreeNode<int>* red_node = new RB_TreeNode<int>{10, nullptr, nullptr, true};
    RB_TreeNode<int>* black_node = new RB_TreeNode<int>{20, nullptr, nullptr, false};
    
    std::ostringstream oss;
    oss << red_node << " " << black_node;
    
    std::string expected = "(R 10) (B 20)";
    std::string result = oss.str();
    
    delete red_node;
    delete black_node;
    return test_helper(expected, result);
}