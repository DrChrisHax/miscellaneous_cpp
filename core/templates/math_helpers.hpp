#ifndef TEMPLATES_MATH_HELPERS_H_
#define TEMPLATES_MATH_HELPERS_H_

#include <type_traits>
#include <limits>

template<typename T>
constexpr bool would_overflow_multiplication(T a, T b) {
    if (a == 0 || b == 0) return false;

    if constexpr (std::is_signed_v<T>) {
        // For signed types, check both positive and negative overflow
        if (a > 0 && b > 0) {
            return a > std::numeric_limits<T>::max() / b;
        } else if (a < 0 && b < 0) {
            return a < std::numeric_limits<T>::max() / b;
        } else if (a > 0 && b < 0) {
            return b < std::numeric_limits<T>::min() / a;
        } else { // a < 0 && b > 0
            return a < std::numeric_limits<T>::min() / b;
        }
    } else {
        // For unsigned types, we only need to worry about positive overflow
        return a > std::numeric_limits<T>::max() / b;
    }
}

#endif // TEMPLATES_MATH_HELPERS_H_