#ifndef CPP_TEMPLATE_TESTS_H_
#define CPP_TEMPLATE_TESTS_H_

#include <string_view>
#include <iostream>

// =============================================================================
// Sample Test
// =============================================================================

bool SampleTest1(); // This test will pass
bool SampleTest2(); // This test will fail

// =============================================================================
// math_helpers Tests
// =============================================================================

// Addition tests
// Unsigned Int 32-bit type
bool math_helpers_addition_unsigned_32_no_overflow();
bool math_helpers_addition_unsigned_32_overflow();

//Signed Int 32-bit type
bool math_helpers_addition_signed_32_no_negative_no_overflow();
bool math_helpers_addition_signed_32_no_negative_overflow();
bool math_helpers_addition_signed_32_two_negatives_no_overflow();
bool math_helpers_addition_signed_32_two_negatives_overflow();

// Multiplication tests
// Unsigned Int 32-bit type
bool math_helpers_multiplication_unsigned_32_no_overflow();
bool math_helpers_multiplication_unsigned_32_overflow();

//Signed Int 32-bit type
bool math_helpers_multiplication_signed_32_no_negative_no_overflow();
bool math_helpers_multiplication_signed_32_no_negative_overflow();
bool math_helpers_multiplication_signed_32_one_negative_A_no_overflow();
bool math_helpers_multiplication_signed_32_one_negative_A_overflow();
bool math_helpers_multiplication_signed_32_one_negative_B_no_overflow();
bool math_helpers_multiplication_signed_32_one_negative_B_overflow();
bool math_helpers_multiplication_signed_32_two_negatives_no_overflow();
bool math_helpers_multiplication_signed_32_two_negatives_overflow();

//Long Double type
// bool math_helpers_multiplication_long_double_no_negative_no_overflow();
// bool math_helpers_multiplication_long_double_no_negative_overflow();
// bool math_helpers_multiplication_long_double_one_negative_A_no_overflow();
// bool math_helpers_multiplication_long_double_one_negative_A_overflow();
// bool math_helpers_multiplication_long_double_one_negative_B_no_overflow();
// bool math_helpers_multiplication_long_double_one_negative_B_overflow();
// bool math_helpers_multiplication_long_double_two_negatives_no_overflow();
// bool math_helpers_multiplication_long_double_two_negatives_overflow();

// =============================================================================
// Fraction<int> Tests
// =============================================================================

// Constructor tests
bool fraction_int_constructor_default();
bool fraction_int_constructor_single_param();
bool fraction_int_constructor_both_params();
bool fraction_int_constructor_zero_denominator();

// Normalization tests
bool fraction_int_normalization_gcd_reduction();
bool fraction_int_normalization_already_reduced();
bool fraction_int_normalization_to_whole_number();
bool fraction_int_normalization_zero_numerator();

// Negative tests
bool fraction_int_negative_numerator();
bool fraction_int_negative_denominator();
bool fraction_int_both_negative();
bool fraction_int_negative_with_reduction();
bool fraction_int_negative_whole_number();

// to_string tests
bool fraction_int_to_string_whole_number();
bool fraction_int_to_string_regular_fraction();
bool fraction_int_to_string_negative_fraction();
bool fraction_int_to_string_zero();

// addition tests
bool fraction_int_addition_simple();
bool fraction_int_addition_with_reduction();
bool fraction_int_addition_negative();
bool fraction_int_addition_to_whole_number();
bool fraction_int_addition_smart_overflow_avoidance();

// multiplication tests
bool fraction_int_multiplication_no_reduction();
bool fraction_int_multiplication_recution();
bool fraction_int_multiplication_negative();
bool fraction_int_overflow_no_error();
bool fraction_int_overflow_error();

// operator<< tests
bool fraction_int_ostream_whole_number();
bool fraction_int_ostream_regular_fraction();
bool fraction_int_ostream_negative_fraction();
bool fraction_int_ostream_zero();
bool fraction_int_ostream_multiple_fractions();

// operator>> tests
bool fraction_int_istream_whole_number();
bool fraction_int_istream_regular_fraction();
bool fraction_int_istream_negative_numerator();
bool fraction_int_istream_with_reduction();
bool fraction_int_istream_zero_denominator();
bool fraction_int_istream_multiple_fractions();
bool fraction_int_istream_whitespace_handling();
bool fraction_int_istream_negative_denominator();
bool fraction_int_istream_both_negative();

// << & >> operator test
bool fraction_int_roundtrip_test();

// =============================================================================
// Node Tests 
// =============================================================================

// SL_Node tests
bool node_sl_node_to_string_ref();
bool node_sl_node_to_string_ptr();
bool node_sl_node_ostream_ref();
bool node_sl_node_ostream_ptr();

// DL_Node tests
bool node_dl_node_to_string_ref();
bool node_dl_node_to_string_ptr();
bool node_dl_node_ostream_ref();
bool node_dl_node_ostream_ptr();

// SL_KV_Node tests
bool node_sl_kv_node_to_string_ref();
bool node_sl_kv_node_to_string_ptr();
bool node_sl_kv_node_ostream_ref();
bool node_sl_kv_node_ostream_ptr();

// DL_KV_Node tests
bool node_dl_kv_node_to_string_ref();
bool node_dl_kv_node_to_string_ptr();
bool node_dl_kv_node_ostream_ref();
bool node_dl_kv_node_ostream_ptr();

// TreeNode tests
bool node_tree_node_to_string_ref();
bool node_tree_node_to_string_ptr();
bool node_tree_node_ostream_ref();
bool node_tree_node_ostream_ptr();

// RB_TreeNode tests
bool node_rb_tree_node_to_string_ref();
bool node_rb_tree_node_to_string_ptr();
bool node_rb_tree_node_ostream_ref();
bool node_rb_tree_node_ostream_ptr();

// =============================================================================
// LRU Cache Tests
// =============================================================================

// Constructor tests
bool lru_cache_constructor_explicit_capacity();
bool lru_cache_constructor_copy();
bool lru_cache_constructor_move();

// Assignment operator tests
bool lru_cache_assignment_copy();
bool lru_cache_assignment_move();
bool lru_cache_assignment_self();

// Basic functionality tests
bool lru_cache_empty_cache();
bool lru_cache_single_item();
bool lru_cache_multiple_items();

// Put and Get tests
bool lru_cache_put_and_get_basic();
bool lru_cache_get_moves_to_front();
bool lru_cache_put_existing_key();
bool lru_cache_get_nonexistent_returns_nullptr();

// Capacity and eviction tests
bool lru_cache_capacity_hit_multiple_times();
bool lru_cache_capacity_with_updates();

// Operator tests
bool lru_cache_ostream_single_item();
bool lru_cache_ostream_multiple_items();
bool lru_cache_comprehensive();

// =============================================================================
// Binary Tree Tests
// =============================================================================

// Constructor and destructor tests
bool binary_tree_constructor_default();
bool binary_tree_destructor();

// Move tests
bool binary_tree_move_constructor();
bool binary_tree_move_assignment();
bool binary_tree_move_assignment_self();

// PreOrder 

// =============================================================================
// MinHeap Tests
// =============================================================================

// Constructor tests
bool min_heap_constructor_default();
bool min_heap_constructor_explicit_capacity();
bool min_heap_constructor_copy();
bool min_heap_constructor_copy_empty();
bool min_heap_constructor_move();
bool min_heap_constructor_move_empty();
bool min_heap_constructor_initializer_list();
bool min_heap_constructor_initializer_list_empty();

// Assignment operator tests
bool min_heap_assignment_copy();
bool min_heap_assignment_copy_empty();
bool min_heap_assignment_copy_self();
bool min_heap_assignment_move();
bool min_heap_assignment_move_empty();
bool min_heap_assignment_move_self();

// Basic state tests
bool min_heap_empty_on_new();
bool min_heap_empty_after_pop_all();
bool min_heap_size_after_push();
bool min_heap_size_after_pop();
bool min_heap_capacity_initial();
bool min_heap_capacity_after_resize();

// Push tests
bool min_heap_push_single();
bool min_heap_push_multiple_ascending();
bool min_heap_push_multiple_descending();
bool min_heap_push_multiple_random();
bool min_heap_push_duplicates();
bool min_heap_push_triggers_resize();
bool min_heap_push_negative_values();

// Pop tests
bool min_heap_pop_single();
bool min_heap_pop_returns_minimum();
bool min_heap_pop_maintains_heap_property();
bool min_heap_pop_all_sorted();
bool min_heap_pop_empty_throws();
bool min_heap_pop_with_duplicates();

// Peek tests
bool min_heap_peek_single();
bool min_heap_peek_does_not_remove();
bool min_heap_peek_after_push();
bool min_heap_peek_after_pop();
bool min_heap_peek_empty_throws();

// DeleteNode tests
bool min_heap_delete_root();
bool min_heap_delete_leaf();
bool min_heap_delete_middle();
bool min_heap_delete_nonexistent();
bool min_heap_delete_last_element();
bool min_heap_delete_maintains_heap_property();
bool min_heap_delete_with_duplicates();

// Heap property tests
bool min_heap_property_after_many_pushes();
bool min_heap_property_after_mixed_operations();

// Comprehensive tests
bool min_heap_comprehensive_stress_test();
bool min_heap_heapsort_verification();

// to_string tests
bool min_heap_to_string_empty();
bool min_heap_to_string_single();
bool min_heap_to_string_multiple();
bool min_heap_to_string_after_pop();
bool min_heap_to_string_negative_values();

// operator<< tests
bool min_heap_ostream_empty();
bool min_heap_ostream_single();
bool min_heap_ostream_multiple();
bool min_heap_ostream_matches_to_string();

// operator>> tests
bool min_heap_istream_empty_brackets();
bool min_heap_istream_single();
bool min_heap_istream_multiple();
bool min_heap_istream_maintains_heap_property();
bool min_heap_istream_overwrites_existing();
bool min_heap_istream_whitespace_handling();
bool min_heap_istream_no_brackets();

// roundtrip test
bool min_heap_roundtrip_test();

// =============================================================================
// IPv4 Tests
// =============================================================================

// Constructor Tests
bool ipv4_constructor_default();
bool ipv4_constructor_uint32();
bool ipv4_constructor_four_octets();
bool ipv4_constructor_four_octets_max();
bool ipv4_constructor_string_valid();
bool ipv4_constructor_string_loopback();
bool ipv4_constructor_string_invalid_throws();
bool ipv4_constructor_string_out_of_range_throws();

// Static Factory Tests
bool ipv4_from_network_order_little_endian();
bool ipv4_from_host_order();
bool ipv4_static_any();
bool ipv4_static_loopback();
bool ipv4_static_broadcast();
bool ipv4_static_localhost();

// Accessor Tests
bool ipv4_octect();
bool ipv4_cotect_out_of_range();
bool ipv4_a_b_c_d();
bool ipv4_octects_array();
bool ipv4_value();


// =============================================================================
// Future Test Categories
// =============================================================================

// =============================================================================
// Helper Functions
// =============================================================================
bool test_helper(std::string_view expected, std::string_view result);

#endif  // CPP_TEMPLATE_TESTS_H_