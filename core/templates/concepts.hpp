#ifndef TEMPLATES_CONCEPTS_H_
#define TEMPLATES_CONCEPTS_H_

#include "Tree.hpp"
#include <concepts>

namespace core {

    template <typename T>
    concept Numeric = (std::integral<T> || std::floating_point<T>) && !std::same_as<T, bool>;

    template <typename T>
    concept TreeType = std::derived_from<T, Tree<typename T::value_type>>;

}



#endif // TEMPLATES_CONCEPTS_H_