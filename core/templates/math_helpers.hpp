#ifndef TEMPLATES_MATH_HELPERS_H_
#define TEMPLATES_MATH_HELPERS_H_

#include <type_traits>
#include <limits>
#include <concepts>

template<typename T>
inline constexpr bool always_false_v = false;

template<std::integral T>
constexpr bool would_overflow_addition(T a, T b) {
    if (a == 0 || b == 0) return false;

    if constexpr (std::is_signed_v<T>) {
        // For signed types, check both positive and negative overflow
        if (b > 0) {
            return a > std::numeric_limits<T>::max() - b;
        } else {
            return a < std::numeric_limits<T>::min() - b;
        }
    } else {
        // For unsigned types, we only need to worry about positive overflow
        return a > std::numeric_limits<T>::max() - b;
    }
}

template<std::floating_point T>
constexpr bool would_overflow_addition(T a, T b) {
    static_assert(always_false_v<T>, "Function not implemented yet.");
    return false; // TODO: Implement
}

template<std::integral T>
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

template<std::floating_point T>
constexpr bool would_overflow_multiplication(T a, T b) {
    static_assert(always_false_v<T>, "Function not implemented yet.");
    return false; // TODO: Implement
}

#endif // TEMPLATES_MATH_HELPERS_H_