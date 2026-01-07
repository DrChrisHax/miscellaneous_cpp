#ifndef TEMPLATES_CONCEPTS_H_
#define TEMPLATES_CONCEPTS_H_

#include <concepts>

template<typename T>
concept Numeric = (std::integral<T> || std::floating_point<T>) && !std::same_as<T, bool>;

#endif // TEMPLATES_CONCEPTS_H_