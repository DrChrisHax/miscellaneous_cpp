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
// Future Test Categories
// =============================================================================

// =============================================================================
// Helper Functions
// =============================================================================
bool test_helper(std::string_view expected, std::string_view result);

#endif  // CPP_TEMPLATE_TESTS_H_