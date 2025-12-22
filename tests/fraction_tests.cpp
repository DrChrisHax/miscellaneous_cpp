#include "tests.h"
#include "Fraction.hpp"

// Constructor tests
bool fraction_int_constructor_default() {
    std::cout << "[TEST] Fraction<int>: Default constructor (0/1)" << std::endl;

    Fraction<int> f;
    std::string expected = "0";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_constructor_single_param() {
    std::cout << "[TEST] Fraction<int>: Single parameter constructor (5)" << std::endl;
    
    Fraction<int> f{5};
    std::string expected = "5";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_constructor_both_params() {
    std::cout << "[TEST] Fraction<int>: Both parameters constructor (3/4)" << std::endl;
    
    Fraction<int> f(3, 4);
    std::string expected = "3/4";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_constructor_zero_denominator() {
    std::cout << "[TEST] Fraction<int>: Zero denominator throws exception" << std::endl;
    
    bool exception_thrown = false;
    try {
        Fraction<int> f(1, 0);
    } catch (const std::invalid_argument&) {
        exception_thrown = true;
    }
    
    std::string expected = "true";
    std::string result = exception_thrown ? "true" : "false";
    
    return test_helper(expected, result);
}

// Normalization tests
bool fraction_int_normalization_gcd_reduction() {
    std::cout << "[TEST] Fraction<int>: GCD reduction (12/15 -> 4/5)" << std::endl;
    
    Fraction<int> f(12, 15);
    std::string expected = "4/5";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_normalization_already_reduced() {
    std::cout << "[TEST] Fraction<int>: Already in lowest terms (7/11)" << std::endl;
    
    Fraction<int> f(7, 11);
    std::string expected = "7/11";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_normalization_to_whole_number() {
    std::cout << "[TEST] Fraction<int>: Reduces to whole number (100/25 -> 4)" << std::endl;
    
    Fraction<int> f(100, 25);
    std::string expected = "4";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_normalization_zero_numerator() {
    std::cout << "[TEST] Fraction<int>: Zero numerator (0/5 -> 0)" << std::endl;
    
    Fraction<int> f(0, 5);
    std::string expected = "0";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

// Negative tests
bool fraction_int_negative_numerator() {
    std::cout << "[TEST] Fraction<int>: Negative numerator (-3/4)" << std::endl;
    
    Fraction<int> f(-3, 4);
    std::string expected = "-3/4";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_negative_denominator() {
    std::cout << "[TEST] Fraction<int>: Negative denominator (3/-4 -> -3/4)" << std::endl;
    
    Fraction<int> f(3, -4);
    std::string expected = "-3/4";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_both_negative() {
    std::cout << "[TEST] Fraction<int>: Both negative (-3/-4 -> 3/4)" << std::endl;
    
    Fraction<int> f(-3, -4);
    std::string expected = "3/4";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_negative_with_reduction() {
    std::cout << "[TEST] Fraction<int>: Negative with GCD reduction (-12/15 -> -4/5)" << std::endl;
    
    Fraction<int> f(-12, 15);
    std::string expected = "-4/5";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_negative_whole_number() {
    std::cout << "[TEST] Fraction<int>: Negative reduces to whole number (-8/4 -> -2)" << std::endl;
    
    Fraction<int> f(-8, 4);
    std::string expected = "-2";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

// to_string tests
bool fraction_int_to_string_whole_number() {
    std::cout << "[TEST] Fraction<int>: to_string whole number (5/1 -> \"5\")" << std::endl;
    
    Fraction<int> f(5, 1);
    std::string expected = "5";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_to_string_regular_fraction() {
    std::cout << "[TEST] Fraction<int>: to_string regular fraction (3/4 -> \"3/4\")" << std::endl;
    
    Fraction<int> f(3, 4);
    std::string expected = "3/4";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_to_string_negative_fraction() {
    std::cout << "[TEST] Fraction<int>: to_string negative fraction (-2/3 -> \"-2/3\")" << std::endl;
    
    Fraction<int> f(-2, 3);
    std::string expected = "-2/3";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_to_string_zero() {
    std::cout << "[TEST] Fraction<int>: to_string zero (0/1 -> \"0\")" << std::endl;
    
    Fraction<int> f(0, 1);
    std::string expected = "0";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

// multiplication tests
bool fraction_int_multiplication_no_reduction() {
    std::cout << "[TEST] Fraction<int>: Multiplication with no reduction (3/5 * 8/13 -> 24/65)" << std::endl;
    
    Fraction<int> f1(3, 5);
    Fraction<int> f2(8, 13);
    Fraction<int> result = f1 * f2;
    
    std::string expected = "24/65";
    std::string result_str = to_string(result);
    
    return test_helper(expected, result_str);
}

bool fraction_int_multiplication_recution() {
    std::cout << "[TEST] Fraction<int>: Multiplication with reduction (12/17 * 51/96 -> 3/8)" << std::endl;
    
    Fraction<int> f1(12, 17);
    Fraction<int> f2(51, 96);
    Fraction<int> result = f1 * f2;
    
    std::string expected = "3/8";
    std::string result_str = to_string(result);
    
    return test_helper(expected, result_str);
}

bool fraction_int_multiplication_negative() {
    std::cout << "[TEST] Fraction<int>: Multiplication with negative (-1/2 * 3/4 -> -3/8)" << std::endl;
    
    Fraction<int> f1(-1, 2);
    Fraction<int> f2(3, 4);
    Fraction<int> result = f1 * f2;
    
    std::string expected = "-3/8";
    std::string result_str = to_string(result);
    
    return test_helper(expected, result_str);
}

bool fraction_int_overflow_no_error() {
    std::cout << "[TEST] Fraction<int>: Large multiplication with cross-cancellation (1B/7 * 21/1B -> 3)" << std::endl;
    
    Fraction<int> f1(1'000'000'000, 7);
    Fraction<int> f2(21, 1'000'000'000);
    Fraction<int> result = f1 * f2;
    
    std::string expected = "3";
    std::string result_str = to_string(result);
    
    return test_helper(expected, result_str);
}

bool fraction_int_overflow_error() {
    std::cout << "[TEST] Fraction<int>: Multiplication overflow detection (1B/3 * 1B/5 -> overflow)" << std::endl;
    
    try {
        Fraction<int> f1(1'000'000'000, 3);
        Fraction<int> f2(1'000'000'000, 5);
        Fraction<int> result = f1 * f2;
        
        // Should not reach here
        std::cout << "  Expected: overflow_error exception" << std::endl;
        std::cout << "  Got:      " << to_string(result) << " (no exception)" << std::endl;
        std::cout << "  Result:   FAIL" << std::endl;
        std::cout << std::endl;
        return false;
    } catch (const std::overflow_error& e) {
        std::cout << "  Expected: overflow_error exception" << std::endl;
        std::cout << "  Got:      overflow_error: " << e.what() << std::endl;
        std::cout << "  Result:   PASS" << std::endl;
        std::cout << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cout << "  Expected: overflow_error exception" << std::endl;
        std::cout << "  Got:      " << e.what() << " (wrong exception type)" << std::endl;
        std::cout << "  Result:   FAIL" << std::endl;
        std::cout << std::endl;
        return false;
    }
}