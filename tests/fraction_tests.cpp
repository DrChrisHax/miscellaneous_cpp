#include "tests.h"
#include "Fraction.hpp"

#include <sstream>

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

// addition tests
bool fraction_int_addition_simple() {
    std::cout << "[TEST] Fraction<int>: Simple addition (1/2 + 1/3 -> 5/6)" << std::endl;
    
    Fraction<int> f1(1, 2);
    Fraction<int> f2(1, 3);
    Fraction<int> result = f1 + f2;
    
    std::string expected = "5/6";
    std::string result_str = to_string(result);
    
    return test_helper(expected, result_str);
}

bool fraction_int_addition_with_reduction() {
    std::cout << "[TEST] Fraction<int>: Addition with reduction (1/6 + 1/4 -> 5/12)" << std::endl;
    
    Fraction<int> f1(1, 6);
    Fraction<int> f2(1, 4);
    Fraction<int> result = f1 + f2;
    
    std::string expected = "5/12";
    std::string result_str = to_string(result);
    
    return test_helper(expected, result_str);
}

bool fraction_int_addition_negative() {
    std::cout << "[TEST] Fraction<int>: Addition with negative (3/4 + (-1/2) -> 1/4)" << std::endl;
    
    Fraction<int> f1(3, 4);
    Fraction<int> f2(-1, 2);
    Fraction<int> result = f1 + f2;
    
    std::string expected = "1/4";
    std::string result_str = to_string(result);
    
    return test_helper(expected, result_str);
}

bool fraction_int_addition_to_whole_number() {
    std::cout << "[TEST] Fraction<int>: Addition to whole number (1/4 + 3/4 -> 1)" << std::endl;
    
    Fraction<int> f1(1, 4);
    Fraction<int> f2(3, 4);
    Fraction<int> result = f1 + f2;
    
    std::string expected = "1";
    std::string result_str = to_string(result);
    
    return test_helper(expected, result_str);
}

bool fraction_int_addition_smart_overflow_avoidance() {
    std::cout << "[TEST] Fraction<int>: Smart cross-cancellation prevents overflow ((3*3*11 / 2^26 * 13) + (17*3 / 2^26 * 17) -> (3*23 / 2^25 * 13))" << std::endl;
    
    Fraction<int> f1(99, 872'415'232);
    Fraction<int> f2(51, 1'140'850'688);
    Fraction<int> result = f1 + f2;
    
    Fraction<int> f3(69, 436'207'616);
    std::string expected = to_string(f3);
    std::string result_str = to_string(result);
    
    return test_helper(expected, result_str);
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
    
    std::string expected = "overflow_error";
    std::string result;
    
    try {
        Fraction<int> f1(1'000'000'000, 3);
        Fraction<int> f2(1'000'000'000, 5);
        Fraction<int> frac_result = f1 * f2;
        
        // Should not reach here
        result = "no exception thrown (got: " + to_string(frac_result) + ")";
    } catch (const std::overflow_error& e) {
        result = "overflow_error";
    } catch (const std::exception& e) {
        result = std::string("wrong exception type: ") + e.what();
    }
    
    return test_helper(expected, result);
}

// operator<< tests
bool fraction_int_ostream_whole_number() {
    std::cout << "[TEST] Fraction<int>: operator<< whole number (5)" << std::endl;
    
    Fraction<int> f(5, 1);
    std::ostringstream oss;
    oss << f;
    
    std::string expected = "5";
    std::string result = oss.str();
    
    return test_helper(expected, result);
}

bool fraction_int_ostream_regular_fraction() {
    std::cout << "[TEST] Fraction<int>: operator<< regular fraction (3/4)" << std::endl;
    
    Fraction<int> f(3, 4);
    std::ostringstream oss;
    oss << f;
    
    std::string expected = "3/4";
    std::string result = oss.str();
    
    return test_helper(expected, result);
}

bool fraction_int_ostream_negative_fraction() {
    std::cout << "[TEST] Fraction<int>: operator<< negative fraction (-7/8)" << std::endl;
    
    Fraction<int> f(-7, 8);
    std::ostringstream oss;
    oss << f;
    
    std::string expected = "-7/8";
    std::string result = oss.str();
    
    return test_helper(expected, result);
}

bool fraction_int_ostream_zero() {
    std::cout << "[TEST] Fraction<int>: operator<< zero (0/1)" << std::endl;
    
    Fraction<int> f(0, 1);
    std::ostringstream oss;
    oss << f;
    
    std::string expected = "0";
    std::string result = oss.str();
    
    return test_helper(expected, result);
}

bool fraction_int_ostream_multiple_fractions() {
    std::cout << "[TEST] Fraction<int>: operator<< multiple fractions in sequence" << std::endl;
    
    Fraction<int> f1(1, 2);
    Fraction<int> f2(3, 4);
    std::ostringstream oss;
    oss << f1 << " + " << f2;
    
    std::string expected = "1/2 + 3/4";
    std::string result = oss.str();
    
    return test_helper(expected, result);
}

// operator>> tests
bool fraction_int_istream_whole_number() {
    std::cout << "[TEST] Fraction<int>: operator>> whole number (\"7\")" << std::endl;
    
    std::istringstream iss("7");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "7";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_istream_regular_fraction() {
    std::cout << "[TEST] Fraction<int>: operator>> regular fraction (\"3/4\")" << std::endl;
    
    std::istringstream iss("3/4");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "3/4";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_istream_negative_numerator() {
    std::cout << "[TEST] Fraction<int>: operator>> negative numerator (\"-5/8\")" << std::endl;
    
    std::istringstream iss("-5/8");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "-5/8";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_istream_with_reduction() {
    std::cout << "[TEST] Fraction<int>: operator>> with GCD reduction (\"12/16\" -> \"3/4\")" << std::endl;
    
    std::istringstream iss("12/16");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "3/4";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_istream_zero_denominator() {
    std::cout << "[TEST] Fraction<int>: operator>> zero denominator sets failbit (\"5/0\")" << std::endl;
    
    std::istringstream iss("5/0");
    Fraction<int> f(99, 99);
    iss >> f;
    
    bool stream_failed = iss.fail();
    std::string expected = "true";
    std::string result = stream_failed ? "true" : "false";
    
    return test_helper(expected, result);
}

bool fraction_int_istream_multiple_fractions() {
    std::cout << "[TEST] Fraction<int>: operator>> multiple fractions (\"1/2 3/4\")" << std::endl;
    
    std::istringstream iss("1/2 3/4");
    Fraction<int> f1, f2;
    iss >> f1 >> f2;
    
    std::string expected = "1/2 3/4";
    std::ostringstream oss;
    oss << f1 << " " << f2;
    std::string result = oss.str();
    
    return test_helper(expected, result);
}

bool fraction_int_istream_whitespace_handling() {
    std::cout << "[TEST] Fraction<int>: operator>> handles leading whitespace (\"  5/6\")" << std::endl;
    
    std::istringstream iss("  5/6");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "5/6";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_istream_negative_denominator() {
    std::cout << "[TEST] Fraction<int>: operator>> negative denominator (\"3/-4\" -> \"-3/4\")" << std::endl;
    
    std::istringstream iss("3/-4");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "-3/4";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

bool fraction_int_istream_both_negative() {
    std::cout << "[TEST] Fraction<int>: operator>> both negative (\"-6/-8\" -> \"3/4\")" << std::endl;
    
    std::istringstream iss("-6/-8");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "3/4";
    std::string result = to_string(f);
    
    return test_helper(expected, result);
}

// << & >> operator test
bool fraction_int_roundtrip_test() {
    std::cout << "[TEST] Fraction<int>: roundtrip test (output->input->output)" << std::endl;
    
    Fraction<int> original(7, 11);
    
    std::ostringstream oss;
    oss << original;
    
    std::istringstream iss(oss.str());
    Fraction<int> copy;
    iss >> copy;
    
    std::ostringstream oss2;
    oss2 << copy;
    
    std::string expected = "7/11";
    std::string result = oss2.str();
    
    return test_helper(expected, result);
}