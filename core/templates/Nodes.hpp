#ifndef CORE_TEMPLATES_NODES_H_
#define CORE_TEMPLATES_NODES_H_

#include <iostream>
#include <string>

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

    /*** SL_Node ***/

    template <typename V>
    std::string to_string(const SL_Node<V>& node) {
        std::ostringstream oss;
        oss << "(" << node.value << ")";
        return oss.str();
    }

    template <typename V>
    std::string to_string(const SL_Node<V>* node) {
        std::ostringstream oss;
        oss << "(" << node->value << ")";
        return oss.str();
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const SL_Node<V>& node) {
        os << to_string(node);
        return os;
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const SL_Node<V>* node) {
        os << to_string(node);
        return os;
    }

    /*** DL_Node ***/

    template <typename V>
    std::string to_string(const DL_Node<V>& node) {
        std::ostringstream oss;
        oss << "(" << node.value << ")";
        return oss.str();
    }

    template <typename V>
    std::string to_string(const DL_Node<V>* node) {
        std::ostringstream oss;
        oss << "(" << node->value << ")";
        return oss.str();
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const DL_Node<V>& node) {
        os << to_string(node);
        return os;
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const DL_Node<V>* node) {
        os << to_string(node);
        return os;
    }

    /*** SL_KV_Node ***/

    template <typename K, typename V>
    std::string to_string(const SL_KV_Node<K, V>& node) {
        std::ostringstream oss;
        oss << "(" << node.key << ", " << node.value << ")";
        return oss.str();
    }

    template <typename K, typename V>
    std::string to_string(const SL_KV_Node<K, V>* node) {
        std::ostringstream oss;
        oss << "(" << node->key << ", " << node->value << ")";
        return oss.str();
    }

    template <typename K, typename V>
    std::ostream& operator<<(std::ostream& os, const SL_KV_Node<K, V>& node) {
        os << to_string(node);
        return os;
    }

    template <typename K, typename V>
    std::ostream& operator<<(std::ostream& os, const SL_KV_Node<K, V>* node) {
        os << to_string(node);
        return os;
    }

    /*** DL_KV_Node ***/

    template <typename K, typename V>
    std::string to_string(const DL_KV_Node<K, V>& node) {
        std::ostringstream oss;
        oss << "(" << node.key << ", " << node.value << ")";
        return oss.str();
    }

    template <typename K, typename V>
    std::string to_string(const DL_KV_Node<K, V>* node) {
        std::ostringstream oss;
        oss << "(" << node->key << ", " << node->value << ")";
        return oss.str();
    }

    template <typename K, typename V>
    std::ostream& operator<<(std::ostream& os, const DL_KV_Node<K, V>& node) {
        os << to_string(node);
        return os;
    }

    template <typename K, typename V>
    std::ostream& operator<<(std::ostream& os, const DL_KV_Node<K, V>* node) {
        os << to_string(node);
        return os;
    }

    /*** TreeNode ***/

    template <typename V>
    std::string to_string(const TreeNode<V>& node) {
        std::ostringstream oss;
        oss << "(" << node.value << ")";
        return oss.str();
    }

    template <typename V>
    std::string to_string(const TreeNode<V>* node) {
        std::ostringstream oss;
        oss << "(" << node->value << ")";
        return oss.str();
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const TreeNode<V>& node) {
        os << to_string(node);
        return os;
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const TreeNode<V>* node) {
        os << to_string(node);
        return os;
    }

    /*** RB_TreeNode ***/

    template <typename V>
    std::string to_string(const RB_TreeNode<V>& node) {
        std::ostringstream oss;
        oss << "(" << node.Color() << " " << node.value << ")";
        return oss.str();
    }

    template <typename V>
    std::string to_string(const RB_TreeNode<V>* node) {
        std::ostringstream oss;
        oss << "(" << node->Color() << " " << node->value << ")";
        return oss.str();
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const RB_TreeNode<V>& node) {
        os << to_string(node);
        return os;
    }

    template <typename V>
    std::ostream& operator<<(std::ostream& os, const RB_TreeNode<V>* node) {
        os << to_string(node);
        return os;
    }
    
}

#endif // CORE_TEMPLATES_NODES_H_
