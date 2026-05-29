#pragma once

#include "test_helpers.hpp"
#include "Fraction.hpp"

// Constructor tests
test_result fraction_int_constructor_default() {
    Fraction<int> f;
    std::string expected = "0";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_constructor_single_param() {  
    Fraction<int> f{5};
    std::string expected = "5";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_constructor_both_params() {
    Fraction<int> f(3, 4);
    std::string expected = "3/4";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_constructor_zero_denominator() {
    bool exception_thrown = false;
    try {
        Fraction<int> f(1, 0);
    } catch (const std::invalid_argument&) {
        exception_thrown = true;
    }
    
    std::string expected = "true";
    std::string result = exception_thrown ? "true" : "false";
    
    return test_result(expected, result);
}

// Normalization tests
test_result fraction_int_normalization_gcd_reduction() {
    Fraction<int> f(12, 15);
    std::string expected = "4/5";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_normalization_already_reduced() {
    Fraction<int> f(7, 11);
    std::string expected = "7/11";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_normalization_to_whole_number() {
    Fraction<int> f(100, 25);
    std::string expected = "4";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_normalization_zero_numerator() {
    Fraction<int> f(0, 5);
    std::string expected = "0";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

// Negative tests
test_result fraction_int_negative_numerator() {
    Fraction<int> f(-3, 4);
    std::string expected = "-3/4";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_negative_denominator() {
    Fraction<int> f(3, -4);
    std::string expected = "-3/4";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_both_negative() {
    Fraction<int> f(-3, -4);
    std::string expected = "3/4";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_negative_with_reduction() {
    Fraction<int> f(-12, 15);
    std::string expected = "-4/5";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_negative_whole_number() {
    Fraction<int> f(-8, 4);
    std::string expected = "-2";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

// to_string tests
test_result fraction_int_to_string_whole_number() {
    Fraction<int> f(5, 1);
    std::string expected = "5";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_to_string_regular_fraction() {
    Fraction<int> f(3, 4);
    std::string expected = "3/4";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_to_string_negative_fraction() {
    Fraction<int> f(-2, 3);
    std::string expected = "-2/3";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_to_string_zero() {
    Fraction<int> f(0, 1);
    std::string expected = "0";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

// addition tests
test_result fraction_int_addition_simple() {
    Fraction<int> f1(1, 2);
    Fraction<int> f2(1, 3);
    Fraction<int> result = f1 + f2;
    
    std::string expected = "5/6";
    std::string result_str = to_string(result);
    
    return test_result(expected, result_str);
}

test_result fraction_int_addition_with_reduction() {
    Fraction<int> f1(1, 6);
    Fraction<int> f2(1, 4);
    Fraction<int> result = f1 + f2;
    
    std::string expected = "5/12";
    std::string result_str = to_string(result);
    
    return test_result(expected, result_str);
}

test_result fraction_int_addition_negative() {
    Fraction<int> f1(3, 4);
    Fraction<int> f2(-1, 2);
    Fraction<int> result = f1 + f2;
    
    std::string expected = "1/4";
    std::string result_str = to_string(result);
    
    return test_result(expected, result_str);
}

test_result fraction_int_addition_to_whole_number() {
    Fraction<int> f1(1, 4);
    Fraction<int> f2(3, 4);
    Fraction<int> result = f1 + f2;
    
    std::string expected = "1";
    std::string result_str = to_string(result);
    
    return test_result(expected, result_str);
}

test_result fraction_int_addition_smart_overflow_avoidance() {
    Fraction<int> f1(99, 872'415'232);
    Fraction<int> f2(51, 1'140'850'688);
    Fraction<int> result = f1 + f2;
    
    Fraction<int> f3(69, 436'207'616);
    std::string expected = to_string(f3);
    std::string result_str = to_string(result);
    
    return test_result(expected, result_str);
}

// multiplication tests
test_result fraction_int_multiplication_no_reduction() {
    Fraction<int> f1(3, 5);
    Fraction<int> f2(8, 13);
    Fraction<int> result = f1 * f2;
    
    std::string expected = "24/65";
    std::string result_str = to_string(result);
    
    return test_result(expected, result_str);
}

test_result fraction_int_multiplication_recution() {   
    Fraction<int> f1(12, 17);
    Fraction<int> f2(51, 96);
    Fraction<int> result = f1 * f2;
    
    std::string expected = "3/8";
    std::string result_str = to_string(result);
    
    return test_result(expected, result_str);
}

test_result fraction_int_multiplication_negative() {
    Fraction<int> f1(-1, 2);
    Fraction<int> f2(3, 4);
    Fraction<int> result = f1 * f2;
    
    std::string expected = "-3/8";
    std::string result_str = to_string(result);
    
    return test_result(expected, result_str);
}

test_result fraction_int_overflow_no_error() {
    Fraction<int> f1(1'000'000'000, 7);
    Fraction<int> f2(21, 1'000'000'000);
    Fraction<int> result = f1 * f2;
    
    std::string expected = "3";
    std::string result_str = to_string(result);
    
    return test_result(expected, result_str);
}

test_result fraction_int_overflow_error() {
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
    
    return test_result(expected, result);
}

// operator<< tests
test_result fraction_int_ostream_whole_number() {
    Fraction<int> f(5, 1);
    std::ostringstream oss;
    oss << f;
    
    std::string expected = "5";
    std::string result = oss.str();
    
    return test_result(expected, result);
}

test_result fraction_int_ostream_regular_fraction() {
    Fraction<int> f(3, 4);
    std::ostringstream oss;
    oss << f;
    
    std::string expected = "3/4";
    std::string result = oss.str();
    
    return test_result(expected, result);
}

test_result fraction_int_ostream_negative_fraction() {
    Fraction<int> f(-7, 8);
    std::ostringstream oss;
    oss << f;
    
    std::string expected = "-7/8";
    std::string result = oss.str();
    
    return test_result(expected, result);
}

test_result fraction_int_ostream_zero() {
    Fraction<int> f(0, 1);
    std::ostringstream oss;
    oss << f;
    
    std::string expected = "0";
    std::string result = oss.str();
    
    return test_result(expected, result);
}

test_result fraction_int_ostream_multiple_fractions() {
    Fraction<int> f1(1, 2);
    Fraction<int> f2(3, 4);
    std::ostringstream oss;
    oss << f1 << " + " << f2;
    
    std::string expected = "1/2 + 3/4";
    std::string result = oss.str();
    
    return test_result(expected, result);
}

// operator>> tests
test_result fraction_int_istream_whole_number() {
    std::istringstream iss("7");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "7";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_istream_regular_fraction() {
    std::istringstream iss("3/4");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "3/4";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_istream_negative_numerator() {
    std::istringstream iss("-5/8");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "-5/8";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_istream_with_reduction() {
    std::istringstream iss("12/16");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "3/4";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_istream_zero_denominator() {
    std::istringstream iss("5/0");
    Fraction<int> f(99, 99);
    iss >> f;
    
    bool stream_failed = iss.fail();
    std::string expected = "true";
    std::string result = stream_failed ? "true" : "false";
    
    return test_result(expected, result);
}

test_result fraction_int_istream_multiple_fractions() {
    std::istringstream iss("1/2 3/4");
    Fraction<int> f1, f2;
    iss >> f1 >> f2;
    
    std::string expected = "1/2 3/4";
    std::ostringstream oss;
    oss << f1 << " " << f2;
    std::string result = oss.str();
    
    return test_result(expected, result);
}

test_result fraction_int_istream_whitespace_handling() {
    std::istringstream iss("  5/6");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "5/6";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_istream_negative_denominator() {
    std::istringstream iss("3/-4");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "-3/4";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

test_result fraction_int_istream_both_negative() { 
    std::istringstream iss("-6/-8");
    Fraction<int> f;
    iss >> f;
    
    std::string expected = "3/4";
    std::string result = to_string(f);
    
    return test_result(expected, result);
}

// << & >> operator test
test_result fraction_int_roundtrip_test() {
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
    
    return test_result(expected, result);
}