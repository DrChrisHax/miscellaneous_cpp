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
// Future Test Categories
// =============================================================================

// =============================================================================
// Helper Functions
// =============================================================================
bool test_helper(std::string_view expected, std::string_view result);

#endif  // CPP_TEMPLATE_TESTS_H_