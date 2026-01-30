#include "tests.h"
#include "Timer.h"

#include <iostream>

static int total_tests = 0;
static int passed_tests = 0;
static int failed_tests = 0;

void Run(bool (*test)()) {
    total_tests++;
    if (test()) {
        passed_tests++;
    } else {
        failed_tests++;
    }
}

int main(int argc, char* argv[]) {

    (void)argc;
    (void)argv;

    std::cout << "========================================\n";
    std::cout << "Running Test Suite\n";
    std::cout << "========================================\n";
    std::cout << std::endl;
    core::Timer t{};

    // =============================================================================
    // math_helper Tests
    // =============================================================================

    std::cout << "========================================\n";
    std::cout << "Running Math Helper Tests\n";
    std::cout << "========================================\n";
    std::cout << std::endl;

    Run(math_helpers_addition_unsigned_32_no_overflow);
    Run(math_helpers_addition_unsigned_32_overflow);

    Run(math_helpers_addition_signed_32_no_negative_no_overflow);
    Run(math_helpers_addition_signed_32_no_negative_overflow);
    Run(math_helpers_addition_signed_32_two_negatives_no_overflow);
    Run(math_helpers_addition_signed_32_two_negatives_overflow);

    Run(math_helpers_multiplication_unsigned_32_no_overflow);
    Run(math_helpers_multiplication_unsigned_32_overflow);

    Run(math_helpers_multiplication_signed_32_no_negative_no_overflow);
    Run(math_helpers_multiplication_signed_32_no_negative_overflow);
    Run(math_helpers_multiplication_signed_32_one_negative_A_no_overflow);
    Run(math_helpers_multiplication_signed_32_one_negative_A_overflow);
    Run(math_helpers_multiplication_signed_32_one_negative_B_no_overflow);
    Run(math_helpers_multiplication_signed_32_one_negative_B_overflow);
    Run(math_helpers_multiplication_signed_32_two_negatives_no_overflow);
    Run(math_helpers_multiplication_signed_32_two_negatives_overflow);

    // Run(math_helpers_multiplication_long_double_no_negative_no_overflow);
    // Run(math_helpers_multiplication_long_double_no_negative_overflow);
    // Run(math_helpers_multiplication_long_double_one_negative_A_no_overflow);
    // Run(math_helpers_multiplication_long_double_one_negative_A_overflow);
    // Run(math_helpers_multiplication_long_double_one_negative_B_no_overflow);
    // Run(math_helpers_multiplication_long_double_one_negative_B_overflow);
    // Run(math_helpers_multiplication_long_double_two_negatives_no_overflow);
    // Run(math_helpers_multiplication_long_double_two_negatives_overflow);


    // =============================================================================
    // Fraction<int> Tests
    // =============================================================================

    std::cout << "========================================\n";
    std::cout << "Running Fraction<int> Tests\n";
    std::cout << "========================================\n";
    std::cout << std::endl;

    Run(fraction_int_constructor_default);
    Run(fraction_int_constructor_single_param);
    Run(fraction_int_constructor_both_params);
    Run(fraction_int_constructor_zero_denominator);

    // Normalization tests
    Run(fraction_int_normalization_gcd_reduction);
    Run(fraction_int_normalization_already_reduced);
    Run(fraction_int_normalization_to_whole_number);
    Run(fraction_int_normalization_zero_numerator);

    // Negative tests
    Run(fraction_int_negative_numerator);
    Run(fraction_int_negative_denominator);
    Run(fraction_int_both_negative);
    Run(fraction_int_negative_with_reduction);
    Run(fraction_int_negative_whole_number);

    // to_string tests
    Run(fraction_int_to_string_whole_number);
    Run(fraction_int_to_string_regular_fraction);
    Run(fraction_int_to_string_negative_fraction);
    Run(fraction_int_to_string_zero);

    // Addition tests
    Run(fraction_int_addition_simple);
    Run(fraction_int_addition_with_reduction);
    Run(fraction_int_addition_negative);
    Run(fraction_int_addition_to_whole_number);
    Run(fraction_int_addition_smart_overflow_avoidance);

    // Multiplication tests
    Run(fraction_int_multiplication_no_reduction);
    Run(fraction_int_multiplication_recution);
    Run(fraction_int_multiplication_negative);
    Run(fraction_int_overflow_no_error);
    Run(fraction_int_overflow_error);

    // operator<< tests
    Run(fraction_int_ostream_whole_number);
    Run(fraction_int_ostream_regular_fraction);
    Run(fraction_int_ostream_negative_fraction);
    Run(fraction_int_ostream_zero);
    Run(fraction_int_ostream_multiple_fractions);

    // operator>> tests
    Run(fraction_int_istream_whole_number);
    Run(fraction_int_istream_regular_fraction);
    Run(fraction_int_istream_negative_numerator);
    Run(fraction_int_istream_with_reduction);
    Run(fraction_int_istream_zero_denominator);
    Run(fraction_int_istream_multiple_fractions);
    Run(fraction_int_istream_whitespace_handling);
    Run(fraction_int_istream_negative_denominator);
    Run(fraction_int_istream_both_negative);

    // << & >> operator test
    Run(fraction_int_roundtrip_test);

    std::cout << std::endl;

    // =============================================================================
    // Node Tests
    // =============================================================================

    std::cout << "========================================\n";
    std::cout << "Running Node Tests\n";
    std::cout << "========================================\n";
    std::cout << std::endl;

    // SL_Node tests
    Run(node_sl_node_to_string_ref);
    Run(node_sl_node_to_string_ptr);
    Run(node_sl_node_ostream_ref);
    Run(node_sl_node_ostream_ptr);

    // DL_Node tests
    Run(node_dl_node_to_string_ref);
    Run(node_dl_node_to_string_ptr);
    Run(node_dl_node_ostream_ref);
    Run(node_dl_node_ostream_ptr);

    // SL_KV_Node tests
    Run(node_sl_kv_node_to_string_ref);
    Run(node_sl_kv_node_to_string_ptr);
    Run(node_sl_kv_node_ostream_ref);
    Run(node_sl_kv_node_ostream_ptr);

    // DL_KV_Node tests
    Run(node_dl_kv_node_to_string_ref);
    Run(node_dl_kv_node_to_string_ptr);
    Run(node_dl_kv_node_ostream_ref);
    Run(node_dl_kv_node_ostream_ptr);

    // TreeNode tests
    Run(node_tree_node_to_string_ref);
    Run(node_tree_node_to_string_ptr);
    Run(node_tree_node_ostream_ref);
    Run(node_tree_node_ostream_ptr);

    // RB_TreeNode tests
    Run(node_rb_tree_node_to_string_ref);
    Run(node_rb_tree_node_to_string_ptr);
    Run(node_rb_tree_node_ostream_ref);
    Run(node_rb_tree_node_ostream_ptr);

    std::cout << std::endl;

    // =============================================================================
    // LRU Cache Tests
    // =============================================================================

    std::cout << "========================================\n";
    std::cout << "Running LRU Cache Tests\n";
    std::cout << "========================================\n";
    std::cout << std::endl;

    // Constructor tests
    Run(lru_cache_constructor_explicit_capacity);
    Run(lru_cache_constructor_copy);
    Run(lru_cache_constructor_move);

    // Assignment operator tests
    Run(lru_cache_assignment_copy);
    Run(lru_cache_assignment_move);
    Run(lru_cache_assignment_self);

    // Basic functionality tests
    Run(lru_cache_empty_cache);
    Run(lru_cache_single_item);
    Run(lru_cache_multiple_items);

    // Put and Get tests
    Run(lru_cache_put_and_get_basic);
    Run(lru_cache_get_moves_to_front);
    Run(lru_cache_put_existing_key);
    Run(lru_cache_get_nonexistent_returns_nullptr);

    // Capacity and eviction tests
    Run(lru_cache_capacity_hit_multiple_times);
    Run(lru_cache_capacity_with_updates);
    Run(lru_cache_comprehensive);

    // Operator tests
    Run(lru_cache_ostream_single_item);
    Run(lru_cache_ostream_multiple_items);

    std::cout << std::endl;

    // =============================================================================
    // Binary Tree Tests
    // =============================================================================

    std::cout << "========================================\n";
    std::cout << "Running Binary Tree Tests\n";
    std::cout << "========================================\n";
    std::cout << std::endl;

    Run(binary_tree_constructor_default);
    Run(binary_tree_destructor);
    Run(binary_tree_move_constructor);
    Run(binary_tree_move_assignment);
    Run(binary_tree_move_assignment_self);
        
    // =============================================================================
    // MinHeap Tests
    // =============================================================================

    std::cout << "========================================\n";
    std::cout << "Running MinHeap Tests\n";
    std::cout << "========================================\n";
    std::cout << std::endl;

    // Constructor tests
    Run(min_heap_constructor_default);
    Run(min_heap_constructor_explicit_capacity);
    Run(min_heap_constructor_copy);
    Run(min_heap_constructor_copy_empty);
    Run(min_heap_constructor_move);
    Run(min_heap_constructor_move_empty);
    Run(min_heap_constructor_initializer_list);
    Run(min_heap_constructor_initializer_list_empty);

    // Assignment operator tests
    Run(min_heap_assignment_copy);
    Run(min_heap_assignment_copy_empty);
    Run(min_heap_assignment_copy_self);
    Run(min_heap_assignment_move);
    Run(min_heap_assignment_move_empty);
    Run(min_heap_assignment_move_self);

    // Basic state tests
    Run(min_heap_empty_on_new);
    Run(min_heap_empty_after_pop_all);
    Run(min_heap_size_after_push);
    Run(min_heap_size_after_pop);
    Run(min_heap_capacity_initial);
    Run(min_heap_capacity_after_resize);

    // Push tests
    Run(min_heap_push_single);
    Run(min_heap_push_multiple_ascending);
    Run(min_heap_push_multiple_descending);
    Run(min_heap_push_multiple_random);
    Run(min_heap_push_duplicates);
    Run(min_heap_push_triggers_resize);
    Run(min_heap_push_negative_values);

    // Pop tests
    Run(min_heap_pop_single);
    Run(min_heap_pop_returns_minimum);
    Run(min_heap_pop_maintains_heap_property);
    Run(min_heap_pop_all_sorted);
    Run(min_heap_pop_empty_throws);
    Run(min_heap_pop_with_duplicates);

    // Peek tests
    Run(min_heap_peek_single);
    Run(min_heap_peek_does_not_remove);
    Run(min_heap_peek_after_push);
    Run(min_heap_peek_after_pop);
    Run(min_heap_peek_empty_throws);

    // DeleteNode tests
    Run(min_heap_delete_root);
    Run(min_heap_delete_leaf);
    Run(min_heap_delete_middle);
    Run(min_heap_delete_nonexistent);
    Run(min_heap_delete_last_element);
    Run(min_heap_delete_maintains_heap_property);
    Run(min_heap_delete_with_duplicates);

    // Heap property tests
    Run(min_heap_property_after_many_pushes);
    Run(min_heap_property_after_mixed_operations);

    // Comprehensive tests
    Run(min_heap_comprehensive_stress_test);
    Run(min_heap_heapsort_verification);

    // to_string tests
    Run(min_heap_to_string_empty);
    Run(min_heap_to_string_single);
    Run(min_heap_to_string_multiple);
    Run(min_heap_to_string_after_pop);
    Run(min_heap_to_string_negative_values);

    // operator<< tests
    Run(min_heap_ostream_empty);
    Run(min_heap_ostream_single);
    Run(min_heap_ostream_multiple);
    Run(min_heap_ostream_matches_to_string);

    // operator>> tests
    Run(min_heap_istream_empty_brackets);
    Run(min_heap_istream_single);
    Run(min_heap_istream_multiple);
    Run(min_heap_istream_maintains_heap_property);
    Run(min_heap_istream_overwrites_existing);
    Run(min_heap_istream_whitespace_handling);
    Run(min_heap_istream_no_brackets);

    // roundtrip test
    Run(min_heap_roundtrip_test);

    std::cout << std::endl;

    // =============================================================================
    // IPv4 Tests
    // =============================================================================

    std::cout << "========================================\n";
    std::cout << "Running IPv4 Tests\n";
    std::cout << "========================================\n";
    std::cout << std::endl;

    // Constructor tests
    Run(ipv4_constructor_default);
    Run(ipv4_constructor_uint32);
    Run(ipv4_constructor_four_octets);
    Run(ipv4_constructor_four_octets_max);
    Run(ipv4_constructor_string_valid);
    Run(ipv4_constructor_string_loopback);
    Run(ipv4_constructor_string_invalid_throws);
    Run(ipv4_constructor_string_out_of_range_throws);

    // Static factory tests
    Run(ipv4_from_network_order_little_endian);
    Run(ipv4_from_host_order);
    Run(ipv4_static_any);
    Run(ipv4_static_loopback);
    Run(ipv4_static_broadcast);
    Run(ipv4_static_localhost);

    std::cout << std::endl;


    // =============================================================================
    // Test Summary
    // =============================================================================
    const double ts = t.elapsed();
    std::cout << "========================================\n";
    std::cout << "Test Summary\n";
    std::cout << "========================================\n";
    std::cout << "Total: " << total_tests << "\n";
    std::cout << "Passed: " << passed_tests << "\n";
    std::cout << "Failed: " << failed_tests << "\n";
    std::cout << "Total time elapsed: " << ts << "\n";
    std::cout << std::endl;
}

// =============================================================================
// Helper Functions
// =============================================================================
bool test_helper(std::string_view expected, std::string_view result) {
    // ANSI color codes
    const char* GREEN = "\033[32m";
    const char* RED = "\033[31m";
    const char* RESET = "\033[0m";


    if (result == expected) {
        std::cout << GREEN << "[PASS]" << RESET << "\n";
        return true;
    } else {
        std::cout << RED << "[FAIL]" << RESET << "Expected: " << expected << "\n";
        std::cout << RED << "[FAIL]" << RESET << "Got:      " << result << "\n";
        return false;
    }
}