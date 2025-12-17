#include "tests.h"

#include <string>

bool SampleTest1() {
    std::cout << "[TEST] Sample Test 1: 1==1" << std::endl;

    int input = 1;
    std::string expected = "1";
    std::string result = std::to_string(input);

    return test_helper(expected, result); // This test will pass
}

bool SampleTest2() {
    std::cout << "[TEST] Sample Test 1: 1==2" << std::endl;

    int input = 2;
    std::string expected = "1";
    std::string result = std::to_string(input);

    return test_helper(expected, result); // This test will fail
}