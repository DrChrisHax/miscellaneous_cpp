#ifndef CORE_TEMPLATES_NODES_H_
#define CORE_TEMPLATES_NODES_H_

#include <iostream>

namespace core {

    // Singly Linked Node
    template <typename V>
    struct SL_Node {
        V value{};
        SL_Node* next{nullptr};  
    };

    // Doubly Linked Node
    template <typename V>
    struct DL_Node {
        V value{};
        DL_Node* next{nullptr};
        DL_Node* prev{nullptr};
    };

    // Singly Linked Key Value Node
    template <typename K, typename V>
    struct SL_KV_Node {
        K key{};
        V value{};
        SL_KV_Node* next{nullptr};
    };

    // Doubly Linked Key Value Node
    template <typename K, typename V>
    struct DL_KV_Node {
        K key{};
        V value{};
        DL_KV_Node* next{nullptr};
        DL_KV_Node* prev{nullptr};
    };

    // Tree Node
    template <typename V>
    struct TreeNode {
        V value{};
        TreeNode* left{nullptr};
        TreeNode* right{nullptr};
    };

    // Red-Black Tree Node
    template <typename V>
    struct RB_TreeNode {
        V value{};
        RB_TreeNode* left{nullptr};
        RB_TreeNode* right{nullptr};
        bool color{}; // Red is true, black is false

        bool IsRed() const { return color; }
        bool IsBlack() const { return !color; }

        const char* Color() const { return color ? "R" : "B"; }
    };

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const SL_Node<V>& node) {
        os << "(" << node.value << ")";
        return os;
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const SL_Node<V>* node) {
        os << "(" << node->value << ")";
        return os;
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const DL_Node<V>& node) {
        os << "(" << node.value << ")";
        return os;
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const DL_Node<V>* node) {
        os << "(" << node->value << ")";
        return os;
    }

    template <typename K, typename V>
    std::ostream& operator<<(std::ostream& os, const SL_KV_Node<K, V>& node) {
        os << "(" << node.key << ", " << node.value << ")";
        return os;
    }

    template <typename K, typename V>
    std::ostream& operator<<(std::ostream& os, const SL_KV_Node<K, V>* node) {
        os << "(" << node->key << ", " << node->value << ")";
        return os;
    }

    template <typename K, typename V>
    std::ostream& operator<<(std::ostream& os, const DL_KV_Node<K, V>& node) {
        os << "(" << node.key << ", " << node.value << ")";
        return os;
    }

    template <typename K, typename V>
    std::ostream& operator<<(std::ostream& os, const DL_KV_Node<K, V>* node) {
        os << "(" << node->key << ", " << node->value << ")";
        return os;
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const TreeNode<V>& node) {
        os << "(" << node.value << ")";
        return os;
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const TreeNode<V>* node) {
        os << "(" << node->value << ")";
        return os;
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const RB_TreeNode<V>& node) {
        os << "(" << node.Color() << " " << node.value << ")";
        return os;
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const RB_TreeNode<V>* node) {
        os << "(" << node->Color() << " " << node->value << ")";
        return os;
    }


}

#endif // CORE_TEMPLATES_NODES_H_
