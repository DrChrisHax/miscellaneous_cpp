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

    // std::cout << "========================================\n";
    // std::cout << "Running Math Helper Tests\n";
    // std::cout << "========================================\n";
    // std::cout << std::endl;

    // Run(math_helpers_addition_unsigned_32_no_overflow);
    // Run(math_helpers_addition_unsigned_32_overflow);

    // Run(math_helpers_addition_signed_32_no_negative_no_overflow);
    // Run(math_helpers_addition_signed_32_no_negative_overflow);
    // Run(math_helpers_addition_signed_32_two_negatives_no_overflow);
    // Run(math_helpers_addition_signed_32_two_negatives_overflow);

    // Run(math_helpers_multiplication_unsigned_32_no_overflow);
    // Run(math_helpers_multiplication_unsigned_32_overflow);

    // Run(math_helpers_multiplication_signed_32_no_negative_no_overflow);
    // Run(math_helpers_multiplication_signed_32_no_negative_overflow);
    // Run(math_helpers_multiplication_signed_32_one_negative_A_no_overflow);
    // Run(math_helpers_multiplication_signed_32_one_negative_A_overflow);
    // Run(math_helpers_multiplication_signed_32_one_negative_B_no_overflow);
    // Run(math_helpers_multiplication_signed_32_one_negative_B_overflow);
    // Run(math_helpers_multiplication_signed_32_two_negatives_no_overflow);
    // Run(math_helpers_multiplication_signed_32_two_negatives_overflow);

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

    // std::cout << "========================================\n";
    // std::cout << "Running Fraction<int> Tests\n";
    // std::cout << "========================================\n";
    // std::cout << std::endl;

    // Run(fraction_int_constructor_default);
    // Run(fraction_int_constructor_single_param);
    // Run(fraction_int_constructor_both_params);
    // Run(fraction_int_constructor_zero_denominator);

    // // Normalization tests
    // Run(fraction_int_normalization_gcd_reduction);
    // Run(fraction_int_normalization_already_reduced);
    // Run(fraction_int_normalization_to_whole_number);
    // Run(fraction_int_normalization_zero_numerator);

    // // Negative tests
    // Run(fraction_int_negative_numerator);
    // Run(fraction_int_negative_denominator);
    // Run(fraction_int_both_negative);
    // Run(fraction_int_negative_with_reduction);
    // Run(fraction_int_negative_whole_number);

    // // to_string tests
    // Run(fraction_int_to_string_whole_number);
    // Run(fraction_int_to_string_regular_fraction);
    // Run(fraction_int_to_string_negative_fraction);
    // Run(fraction_int_to_string_zero);

    // // Addition tests
    // Run(fraction_int_addition_simple);
    // Run(fraction_int_addition_with_reduction);
    // Run(fraction_int_addition_negative);
    // Run(fraction_int_addition_to_whole_number);
    // Run(fraction_int_addition_smart_overflow_avoidance);

    // // Multiplication tests
    // Run(fraction_int_multiplication_no_reduction);
    // Run(fraction_int_multiplication_recution);
    // Run(fraction_int_multiplication_negative);
    // Run(fraction_int_overflow_no_error);
    // Run(fraction_int_overflow_error);

    // // operator<< tests
    // Run(fraction_int_ostream_whole_number);
    // Run(fraction_int_ostream_regular_fraction);
    // Run(fraction_int_ostream_negative_fraction);
    // Run(fraction_int_ostream_zero);
    // Run(fraction_int_ostream_multiple_fractions);

    // // operator>> tests
    // Run(fraction_int_istream_whole_number);
    // Run(fraction_int_istream_regular_fraction);
    // Run(fraction_int_istream_negative_numerator);
    // Run(fraction_int_istream_with_reduction);
    // Run(fraction_int_istream_zero_denominator);
    // Run(fraction_int_istream_multiple_fractions);
    // Run(fraction_int_istream_whitespace_handling);
    // Run(fraction_int_istream_negative_denominator);
    // Run(fraction_int_istream_both_negative);

    // // << & >> operator test
    // Run(fraction_int_roundtrip_test);

    // std::cout << std::endl;

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

    // Operator tests
    Run(lru_cache_ostream_single_item);
    Run(lru_cache_ostream_multiple_items);

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