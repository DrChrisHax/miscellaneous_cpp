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
    // Sample Tests
    // =============================================================================
    
    Run(SampleTest1); // This test will pass
    Run(SampleTest2); // This test will fail

    std::cout << std::endl;

    // =============================================================================
    // Future Tests
    // =============================================================================

    //std::cout << std::endl;
      
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