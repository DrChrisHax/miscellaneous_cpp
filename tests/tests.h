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

// multiplication tests
bool fraction_int_multiplication_no_reduction();
bool fraction_int_multiplication_recution();
bool fraction_int_multiplication_negative();
bool fraction_int_overflow_no_error();
bool fraction_int_overflow_error();

// =============================================================================
// Future Test Categories
// =============================================================================

// =============================================================================
// Helper Functions
// =============================================================================
bool test_helper(std::string_view expected, std::string_view result);

#endif  // CPP_TEMPLATE_TESTS_H_