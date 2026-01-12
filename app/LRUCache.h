#ifndef APP_LRU_CACHE_H_
#define APP_LRU_CACHE_H_

#include <unordered_map>

// This is a simple LRU Cache that only takes in ints
// I will template it out in core later

// This is a solution to LeetCode problem 146. LRU Cache


class LRUCache {
public:

    LRUCache(std::size_t capacity) : capacity_{capacity} {
        head_ = new Node();
        tail_ = new Node();
        head_->next = tail_;
        tail_->prev = head_;
    }

    ~LRUCache() {
        Node* curr = head_->next;
        while (curr != tail_) {
            curr = DeleteNode(curr);
        }
        delete head_;
        delete tail_;
    }

    // For now I will delete the copy and move constructors and
    // asignment operators. I will add them in the templated version
    LRUCache(const LRUCache& other) = delete;
    LRUCache(const LRUCache&& other) = delete;

    LRUCache& operator=(const LRUCache& other) = delete;
    LRUCache& operator=(const LRUCache&& other) = delete;

    int get(int key) {
        if (keys_.find(key) != keys_.end()) {
            Node* node = keys_[key];
            RemoveNode(node);
            InsertNode(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (keys_.find(key) != keys_.end()) {
            Node* node = keys_[key];
            RemoveNode(node);
            InsertNode(node);
            node->value = value;
        } else {
            Node* node = new Node(key, value);
            keys_[key] = node;
            InsertNode(node);

            if (keys_.size() > capacity_) {
                Node* old = tail_->prev;
                keys_.erase(old->key);
                (void)DeleteNode(old);
            }
        }
    }

private:
    struct Node {
        int key{-1};
        int value{-1};
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    std::unordered_map<int, Node*> keys_;
    Node* head_;
    Node* tail_;
    std::size_t capacity_;

    void InsertNode(Node* node) {
        // Insert our node at the begining
        node->next = head_->next;
        node->next->prev = node;
        head_->next = node;
        node->prev = head_;
    }

    void RemoveNode(Node* node) {
        Node* next = node->next;
        Node* prev = node->prev;
        prev->next = next;
        next->prev = prev;
    }

    Node* DeleteNode(Node* node) {
        Node* next = node->next;
        Node* prev = node->prev;
        prev->next = next;
        next->prev = prev;
        delete node;
        return next;
    }
};


#endif // APP_LRU_CACHE_H_