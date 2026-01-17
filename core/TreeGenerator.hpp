#ifndef CORE_TREE_GENERATOR_H_
#define CORE_TREE_GENERATOR_H_

#include "Tree.hpp"
#include "concepts.hpp"
#include "random.hpp"

#include <vector>

namespace core {

    template <TreeType  T>
    T EmptyTree() {
        return T{};
    }

    template <TreeType  T>
    T OneElementTree() {
        T tree;
        tree.insert(1);
        return tree;
    }

    // Inserts in an order that produces a balanced BST
    template <TreeType  T>
    T BalancedTree(std::size_t n) {
        T tree;
        std::vector<std::pair<int, int>> ranges{{0, static_cast<int>(n) - 1}};
        while (!ranges.empty()) {
            std::vector<std::pair<int, int>> next;
            for (auto [low, high] : ranges) {
                if (low > high) continue;
                int middle = low + (high - low) / 2;
                tree.Insert(static_cast<typename T::value_type>(mid + 1));
                next.push_back({low, mid - 1});
                next.push_back({mid + 1, high});
            }
            ranges = std::move(next);
        }
        return tree;
    }

    // Inserts in an order that produces the most unbalanced BST
    template <TreeType  T>
    T WorstUnbalancedTree(std::size_t n) {
        T tree;
        for (auto i{0uz}; i < n; ++i) {
            tree.Insert(static_cast<typename T::value_type>(i));
        }
        return tree;
    }

    // Inserts n random positive values
    template <TreeType  T>
    T RandomTree(std::size_t n){
        T tree;
        for (auto i{0uz}; i < n; ++i) {
            tree.Insert(Random::get<typename T::value_type>(1, n * 10));
        }
        return tree;
    }

    // Inserts n random unique positive values
    template <TreeType  T>
    T UniqueRandomTree(unsigned int n) {
        T tree;
        std::unordered_set<typename T::value_type> seen;
        while (seen.size() < n) {
            auto val = Random::get<typename T::value_type>(1, n * 10);
            if (seen.insert(val).second) {
                tree.Insert(val);
            }
        }
        return tree;
    }

}

#endif // CORE_TREE_GENERATOR_H_