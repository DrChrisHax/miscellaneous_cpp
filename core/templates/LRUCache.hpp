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

        LRUCache(const LRUCache& other) = delete;
        LRUCache(LRUCache&& other) = delete;

        ~LRUCache() {
            Node* curr = front_->next;
            while(curr != back_) {
                curr = DeleteNode(curr);
            }
            delete front_;
            delete back_;
        }

        /*** Operator Overloads ***/
        LRUCache& operator=(const LRUCache& other) = delete;
        LRUCache& operator=(LRUCache&& other) = delete;


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

    };

}




#endif