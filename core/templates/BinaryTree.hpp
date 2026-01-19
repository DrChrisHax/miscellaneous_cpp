#ifndef CORE_TEMPLATES_BINARY_TREE_H_
#define CORE_TEMPLATES_BINARY_TREE_H_

#include "Nodes.hpp"
#include "Tree.hpp"

#include <concepts>
#include <iostream>
#include <vector>

namespace core {

    template <typename T>
    requires std::three_way_comparable<T>
    class BinaryTree : public Tree<T> {
    public:
        using Node = TreeNode<T>;

        /*** Constructors and Destructors ***/
        BinaryTree() = default;
        ~BinaryTree() { Clear(); }

        BinaryTree (const BinaryTree& other) = delete;

        BinaryTree (BinaryTree&& other) noexcept {
            root_ = other.root_;
            size_ = other.size_;

            other.root_ = nullptr;
            other.size_ = 0;
        }

        /*** Operator Overloads ***/
        BinaryTree& operator=(const BinaryTree& other) = delete;

        BinaryTree& operator=(BinaryTree&& other) noexcept {
            if (this == &other) return *this;

            root_ = other.root_;
            size_ = other.size_;

            other.root_ = nullptr;
            other.size_ = 0;

            return *this;
        }

        /*** Public Functions ***/
        bool Empty() const { return root_ == nullptr; }
        std::size_t Size() const { return size_; } 
        Node* Root() { return root_; }
        const Node* Root() const { return root_; }

        void Insert(const T& value) {
            Node* newNode = new Node{value};

            if (!root_) {
                root_ = newNode;
            } else {
                InsertNode(root_, newNode);
            }
            ++size_;
        }

        bool Contains(const T& value) const {
            return FindNode(root_, value) != nullptr;
        }

        Node* Find(const T& value) const {
            return FindNode(root_, value);
        }

        void Clear() {
            Delete(root_);
            root_ = nullptr;
            size_ = 0;
        }

        std::string PreOrderTraversal() const {
            std::string out{};
            PreOrderTraversal(root_, out);
            return out;
        }

        std::string InOrderTraversal() const {
            std::string out{};
            InOrderTraversal(root_, out);
            return out;
        }

        std::string PostOrderTraversal() const {
            std::string out{};
            PostOrderTraversal(root_, out);
            return out;
        }

        std::string BFS() const {
            std::string out{};
            if (!root_) return out;

            std::vector<Node*> currentLevel{root_};
            while (!currentLevel.empty()) {
                std::vector<Node*> nextLevel;
                for (Node* node : currentLevel) {
                    out += to_string(node);
                    if (node->left) nextLevel.push_back(node->left);
                    if (node->right) nextLevel.push_back(node->right);
                }
                currentLevel = std::move(nextLevel);
            }
            return out;
        }

        /*** Friend Functions ***/
        friend std::ostream& operator<<(std::ostream& os, const BinaryTree& tree) {
            os << tree.BFS();
            return os;
        }

    private:
        Node* root_{nullptr};
        std::size_t size_{0}; // Number of nodes

        void InsertNode(Node* current, Node* newNode) {
            if (newNode->value < current->value) {
                if (!current->left) current->left = newNode;
                else InsertNode(current->left, newNode);
            } else {
                if (!current->right) current->right = newNode;
                else InsertNode(current->right, newNode);
            }
        }

        Node* FindNode(Node* current, const T& value) const {
            if (!current) return nullptr;
            if (value == current->value) return current;
            if (value < current->value) return FindNode(current->left, value);
            return FindNode(current->right, value);
        }

        void Delete(Node* node) {
            if (!node) return;
            Delete(node->left);
            Delete(node->right);
            delete node;
        }

        void PreOrderTraversal(const Node* node, std::string& list) const {
            if (!node) return;
            list += to_string(node);
            PreOrderTraversal(node->left, list);
            PreOrderTraversal(node->right, list);
        }

        void InOrderTraversal(const Node* node, std::string& list) const {
            if (!node) return;
            InOrderTraversal(node->left, list);
            list += to_string(node);
            InOrderTraversal(node->right, list);
        }

        void PostOrderTraversal(const Node* node, std::string& list) const {
            if (!node) return;
            PostOrderTraversal(node->left, list);
            PostOrderTraversal(node->right, list);
            list += to_string(node);
        }

    };

} // namespace core



#endif // CORE_TEMPLATES_BINARY_TREE_H_