#include "tests.h"
#include "math_helpers.hpp"

#include <cstdint>
#include <sstream>
#include <limits>

// Addition tests
// Unsigned Int 32-bit type
bool math_helpers_addition_unsigned_32_no_overflow() {
    std::cout << "[TEST] math_helper<uint32_t>: no overflow" << std::endl;

    uint32_t a = 1;
    uint32_t b = 2;

    std::string expected = "0";
    std::string result = std::to_string(would_overflow_addition(a, b));

    return test_helper(expected, result);
}

bool math_helpers_addition_unsigned_32_overflow() {
    std::cout << "[TEST] math_helper<uint32_t>: overflow" << std::endl;

    uint32_t a = 2;
    uint32_t b = std::numeric_limits<uint32_t>::max();

    std::string expected = "1";
    std::string result = std::to_string(would_overflow_addition(a, b));

    return test_helper(expected, result);
}

//Signed Int 32-bit type
bool math_helpers_addition_signed_32_no_negative_no_overflow() {
    std::cout << "[TEST] math_helper<int32_t>: addition (+,+) no overflow" << std::endl;

    int32_t a = 1;
    int32_t b = 2;

    std::string expected = "0";
    std::string result = std::to_string(would_overflow_addition(a, b));

    return test_helper(expected, result);
}

bool math_helpers_addition_signed_32_no_negative_overflow() {
    std::cout << "[TEST] math_helper<int32_t>: addition (+,+) overflow" << std::endl;

    int32_t a = std::numeric_limits<int32_t>::max();
    int32_t b = 1;

    std::string expected = "1";
    std::string result = std::to_string(would_overflow_addition(a, b));

    return test_helper(expected, result);
}

bool math_helpers_addition_signed_32_two_negatives_no_overflow() {
    std::cout << "[TEST] math_helper<int32_t>: addition (-,-) no overflow" << std::endl;

    int32_t a = -1;
    int32_t b = -2;

    std::string expected = "0";
    std::string result = std::to_string(would_overflow_addition(a, b));

    return test_helper(expected, result);
}

bool math_helpers_addition_signed_32_two_negatives_overflow() {
    std::cout << "[TEST] math_helper<int32_t>: addition (-,-) overflow" << std::endl;

    int32_t a = std::numeric_limits<int32_t>::min();
    int32_t b = -1;

    std::string expected = "1";
    std::string result = std::to_string(would_overflow_addition(a, b));

    return test_helper(expected, result);
}

// Multiplication tests
// Unsigned Int 32-bit type
bool math_helpers_multiplication_unsigned_32_no_overflow() {
    std::cout << "[TEST] math_helper<uint32_t>: multiplication no overflow" << std::endl;

    uint32_t a = 2;
    uint32_t b = 3;

    std::string expected = "0";
    std::string result = std::to_string(would_overflow_multiplication(a, b));

    return test_helper(expected, result);
}

bool math_helpers_multiplication_unsigned_32_overflow() {
    std::cout << "[TEST] math_helper<uint32_t>: multiplication overflow" << std::endl;

    uint32_t a = (std::numeric_limits<uint32_t>::max() / 2u) + 1u;
    uint32_t b = 2u;

    std::string expected = "1";
    std::string result = std::to_string(would_overflow_multiplication(a, b));

    return test_helper(expected, result);
}

//Signed Int 32-bit type
bool math_helpers_multiplication_signed_32_no_negative_no_overflow() {
    std::cout << "[TEST] math_helper<int32_t>: multiplication (+,+) no overflow" << std::endl;

    int32_t a = 2;
    int32_t b = 3;

    std::string expected = "0";
    std::string result = std::to_string(would_overflow_multiplication(a, b));

    return test_helper(expected, result);
}

bool math_helpers_multiplication_signed_32_no_negative_overflow() {
    std::cout << "[TEST] math_helper<int32_t>: multiplication (+,+) overflow" << std::endl;

    int32_t a = (std::numeric_limits<int32_t>::max() >> 1) + 1;
    int32_t b = 2;

    std::string expected = "1";
    std::string result = std::to_string(would_overflow_multiplication(a, b));

    return test_helper(expected, result);
}

bool math_helpers_multiplication_signed_32_one_negative_A_no_overflow() {
    std::cout << "[TEST] math_helper<int32_t>: multiplication (-,+) no overflow (A neg)" << std::endl;

    int32_t a = -2;
    int32_t b = 3;

    std::string expected = "0";
    std::string result = std::to_string(would_overflow_multiplication(a, b));

    return test_helper(expected, result);
}

bool math_helpers_multiplication_signed_32_one_negative_A_overflow() {
    std::cout << "[TEST] math_helper<int32_t>: multiplication (-,+) overflow (A neg)" << std::endl;

    int32_t a = std::numeric_limits<int32_t>::min();
    int32_t b = 2;

    std::string expected = "1";
    std::string result = std::to_string(would_overflow_multiplication(a, b));

    return test_helper(expected, result);
}

bool math_helpers_multiplication_signed_32_one_negative_B_no_overflow() {
    std::cout << "[TEST] math_helper<int32_t>: multiplication (+,-) no overflow (B neg)" << std::endl;

    int32_t a = 2;
    int32_t b = -3;

    std::string expected = "0";
    std::string result = std::to_string(would_overflow_multiplication(a, b));

    return test_helper(expected, result);
}

bool math_helpers_multiplication_signed_32_one_negative_B_overflow() {
    std::cout << "[TEST] math_helper<int32_t>: multiplication (+,-) overflow (B neg)" << std::endl;

    int32_t a = 2;
    int32_t b = std::numeric_limits<int32_t>::min();

    std::string expected = "1";
    std::string result = std::to_string(would_overflow_multiplication(a, b));

    return test_helper(expected, result);
}

bool math_helpers_multiplication_signed_32_two_negatives_no_overflow() {
    std::cout << "[TEST] math_helper<int32_t>: multiplication (-,-) no overflow" << std::endl;

    int32_t a = -2;
    int32_t b = -3;

    std::string expected = "0";
    std::string result = std::to_string(would_overflow_multiplication(a, b));

    return test_helper(expected, result);
}

bool math_helpers_multiplication_signed_32_two_negatives_overflow() {
    std::cout << "[TEST] math_helper<int32_t>: multiplication (-,-) overflow" << std::endl;

    // std::numeric_limits<int32_t>::min() * -1 overflows for 2's complement signed ints
    int32_t a = std::numeric_limits<int32_t>::min();
    int32_t b = -1;

    std::string expected = "1";
    std::string result = std::to_string(would_overflow_multiplication(a, b));

    return test_helper(expected, result);
}

//Long Double type
// bool math_helpers_multiplication_long_double_no_negative_no_overflow() {
//     std::cout << "[TEST] math_helper<long double>: multiplication (+,+) no overflow" << std::endl;

//     long double a = 2.0L;
//     long double b = 3.0L;

//     std::string expected = "0";
//     std::string result = std::to_string(would_overflow_multiplication(a, b));

//     return test_helper(expected, result);
// }

// bool math_helpers_multiplication_long_double_no_negative_overflow() {
//     std::cout << "[TEST] math_helper<long double>: multiplication (+,+) overflow" << std::endl;

//     long double a = std::numeric_limits<long double>::max();
//     long double b = 2.0L;

//     std::string expected = "1";
//     std::string result = std::to_string(would_overflow_multiplication(a, b));

//     return test_helper(expected, result);
// }

// bool math_helpers_multiplication_long_double_one_negative_A_no_overflow() {
//     std::cout << "[TEST] math_helper<long double>: multiplication (-,+) no overflow (A neg)" << std::endl;

//     long double a = -2.0L;
//     long double b = 3.0L;

//     std::string expected = "0";
//     std::string result = std::to_string(would_overflow_multiplication(a, b));

//     return test_helper(expected, result);
// }

// bool math_helpers_multiplication_long_double_one_negative_A_overflow() {
//     std::cout << "[TEST] math_helper<long double>: multiplication (-,+) overflow (A neg)" << std::endl;

//     long double a = -std::numeric_limits<long double>::max();
//     long double b = 2.0L;

//     std::string expected = "1";
//     std::string result = std::to_string(would_overflow_multiplication(a, b));

//     return test_helper(expected, result);
// }

// bool math_helpers_multiplication_long_double_one_negative_B_no_overflow() {
//     std::cout << "[TEST] math_helper<long double>: multiplication (+,-) no overflow (B neg)" << std::endl;

//     long double a = 2.0L;
//     long double b = -3.0L;

//     std::string expected = "0";
//     std::string result = std::to_string(would_overflow_multiplication(a, b));

//     return test_helper(expected, result);
// }

// bool math_helpers_multiplication_long_double_one_negative_B_overflow() {
//     std::cout << "[TEST] math_helper<long double>: multiplication (+,-) overflow (B neg)" << std::endl;

//     long double a = 2.0L;
//     long double b = -std::numeric_limits<long double>::max();

//     std::string expected = "1";
//     std::string result = std::to_string(would_overflow_multiplication(a, b));

//     return test_helper(expected, result);
// }

// bool math_helpers_multiplication_long_double_two_negatives_no_overflow() {
//     std::cout << "[TEST] math_helper<long double>: multiplication (-,-) no overflow" << std::endl;

//     long double a = -2.0L;
//     long double b = -3.0L;

//     std::string expected = "0";
//     std::string result = std::to_string(would_overflow_multiplication(a, b));

//     return test_helper(expected, result);
// }

// bool math_helpers_multiplication_long_double_two_negatives_overflow() {
//     std::cout << "[TEST] math_helper<long double>: multiplication (-,-) overflow" << std::endl;

//     long double a = -std::numeric_limits<long double>::max();
//     long double b = -2.0L;

//     std::string expected = "1";
//     std::string result = std::to_string(would_overflow_multiplication(a, b));

//     return test_helper(expected, result);
// }
