#ifndef CORE_TEMPLATES_LRU_CACHE_H_
#define CORE_TEMPLATES_LRU_CACHE_H_

#include "Nodes.hpp"

#include <unordered_map>

namespace core {

    template <typename K, typename V>
    class LRUCache {
    public:
        using Node = DL_KV_Node<K, V>;

        /*** Constructors and Destructors ***/
        LRUCache() = delete;
        explicit LRUCache(std::size_t capacity) : capacity_{capacity}, front_{new Node()}, back_{new Node()} {
            front_->next = back_;
            back_->prev = front_;
        }

        LRUCache(const LRUCache& other)  {
            Copy(other);
        };

        LRUCache(LRUCache&& other) {
            Move(std::move(other));
        }

        ~LRUCache() {
            DeleteList();
        }

        /*** Operator Overloads ***/
        LRUCache& operator=(const LRUCache& other) {
            if (this == &other) return *this;

            // Clean up any data in the current object
            keys_.clear();
            DeleteList();

            Copy(other);

            return *this;
        }

        LRUCache& operator=(LRUCache&& other) {
            if (this == &other) return *this;
            keys_.clear();
            
            Move(std::move(other));
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const LRUCache& cache) {
            if (cache.keys_.size() == 0) return os; // Cache is empty
            if (cache.keys_.size() == 1) {
                os << cache.front_->next;
                return os;
            }

            Node* curr = cache.front_->next;
            Node* last = cache.back_->prev;
            while (curr != last) {
                os << curr << "-->";
                curr = curr->next;
            }
            os << curr;

            return os;
        }

        /*** Public Functions ***/
        std::size_t size() { return keys_.size(); }
        std::size_t capacity() { return capacity_; }

        bool contains(const K& key) const {
            return keys_.contains(key);
        }
  
        V* get(const K& key) {
            auto it = keys_.find(key);
            if (it != keys_.end()) {
                // Move the node to the front of the list
                Node* node = it->second;
                RemoveNode(node);
                InsertNode(node);
                return &node->value;
            } else {
                return nullptr;
            }
        }

        void put(const K& key, const V& value) {
            auto it = keys_.find(key);
            if (it != keys_.end()) {
                // The values already exists
                // just move it to the front
                Node* node = it->second;
                node->value = value;
                RemoveNode(node);
                InsertNode(node);
            } else {            
                Node* node = new Node{key, value};
                InsertNode(node);
                keys_[key] = node;
                
                if (keys_.size() > capacity_) {
                    Node* old = back_->prev;
                    keys_.erase(old->key);
                    DeleteNode(old);
                }
            }
        }

    private:
        std::size_t capacity_;
        std::unordered_map<K, Node*> keys_;
        Node* front_{nullptr};
        Node* back_{nullptr};

        void InsertNode(Node* node) {
            // Nodes always go at the front of the list
            node->next = front_->next;
            node->prev = front_;

            front_->next->prev = node;
            front_->next = node;
        }

        void RemoveNode(Node* node) {
            // Removes the node from the list
            Node* prev = node->prev;
            Node* next = node->next;
            prev->next = next;
            next->prev = prev;
        }

        Node* DeleteNode(Node* node) {
            // Delete the node from the list
            // and returns the next node in the list
            Node* prev = node->prev;
            Node* next = node->next;
            prev->next = next;
            next->prev = prev;
            delete node;
            return next;
        }

        void DeleteList() {
            Node* curr = front_->next;
            while(curr != back_) {
                curr = DeleteNode(curr);
            }
            delete front_;
            delete back_;
            front_ = nullptr;
            back_ = nullptr;
        }

        void Copy(const LRUCache& other) {
            capacity_ = other.capacity_;
            keys_ = other.keys_;

            // Copy the linked list
            front_ = new Node();
            back_ = new Node();
            front_->next = back_;
            back_->prev = front_;

            Node* our_curr = front_;
            Node* oth_curr = other.front_->next;
            while (oth_curr != other.back_) {
                Node* node = new Node{oth_curr->key, oth_curr->value};

                node->prev = our_curr;
                node->next = back_;
                our_curr->next = node;
                back_->prev = node;

                our_curr = node;
                keys_[node->key] = node;
                oth_curr = oth_curr->next;
            }
        }

        void Move(LRUCache&& other) {
            capacity_ = other.capacity_;
            front_ = other.front_;
            back_ = other.back_;

            other.capacity_ = 0uz;
            other.front_ = nullptr;
            other.back_ = nullptr;

            std::swap(keys_, other.keys_);
        }

    };

}

#endif