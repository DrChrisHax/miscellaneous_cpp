#ifndef TESTS_TEST_HELPERS_HPP_
#define TESTS_TEST_HELPERS_HPP_

#include <string_view>
#include <iostream>

static const char* GREEN = "\033[32m";
static const char* RED = "\033[31m";
static const char* CYAN = "\033[36m";
static const char* RESET = "\033[0m";

class test_result {
public:
    test_result() = delete;
    test_result(std::string expected, std::string result)
        : expected_{expected}
        , result_{result}
    {}

    test_result(const test_result& other) = delete;
    test_result& operator=(const test_result& other) = delete;
    test_result(test_result&& other) = delete;
    test_result&& operator=(const test_result&& other) = delete;

    bool passed() {
        return expected_ == result_;
    }

    std::string_view expected() const {
        return expected_;
    }

    std::string_view result() const {
        return result_;
    }

private:
    std::string expected_;
    std::string result_;
};

#endif  // TESTS_TEST_HELPERS_HPP_