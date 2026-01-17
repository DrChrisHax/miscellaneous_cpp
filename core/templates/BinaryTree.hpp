#ifndef CORE_TEMPLATES_BINARY_TREE_H_
#define CORE_TEMPLATES_BINARY_TREE_H_

#include "Nodes.hpp"
#include "Tree.hpp"

#include <concepts>

namespace core {

    template <typename T>
    requires std::three_way_comparable<T>
    class BinaryTree : public Tree<T> {
    public:
        using Node = TreeNode<T>;

        /*** Constructors and Destructors ***/
        BinaryTree() = default;
        ~BinaryTree() {  }

        BinaryTree (const BinaryTree& other) = delete;
        BinaryTree (BinaryTree&& other) noexcept = delete;

        /*** Operator Overloads ***/
        BinaryTree& operator=(const BinaryTree& other) = delete;
        BinaryTree& operator=(BinaryTree& other) noexcept = delete;

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
            return Find(root_, value) != nullptr;
        }

        Node* Find(const T& value) const {
            return Find(root_, value);
        }

        void Clear() {
            Delete(root_);
            root_ = nullptr;
            size_ = 0;
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
            if (value < current->value) return Find(current->left, value);
            return Find(current->right, value);
        }

        void Delete(Node* node) {
            if (!node) return;
            Delete(node->left);
            Delete(node->right);
            delete node;
        }
    };

} // namespace core



#endif // CORE_TEMPLATES_BINARY_TREE_H_