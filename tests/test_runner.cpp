#include "tests.h"

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

    std::cout << "========================================" << std::endl;
    std::cout << "Running Test Suite" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    // =============================================================================
    // Fraction<int> Tests
    // =============================================================================

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

    std::cout << std::endl;
      
    // =============================================================================
    // Test Summary
    // =============================================================================
    std::cout << "========================================" << std::endl;
    std::cout << "Test Summary" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Total: " << total_tests << std::endl;
    std::cout << "Passed: " << passed_tests << std::endl;
    std::cout << "Failed: " << failed_tests << std::endl;
    std::cout << std::endl;
}

// =============================================================================
// Helper Functions
// =============================================================================
bool test_helper(std::string_view expected, std::string_view result) {
    if (result == expected) {
        std::cout << "[PASS]" << std::endl;
        return true;
    } else {
        std::cout << "[FAIL] Expected: " << expected << std::endl;
        std::cout << "[FAIL] Got:      " << result << std::endl;
        return false;
    }
}