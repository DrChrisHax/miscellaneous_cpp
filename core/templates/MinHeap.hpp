#ifndef CORE_TEMPLATES_MIN_HEAP_H_
#define CORE_TEMPLATES_MIN_HEAP_H_

#include <vector>
#include <stdexcept>
#include <memory>
#include <string>
#include <iostream>
#include <sstream>

namespace core {
        
    template <typename T>
    class MinHeap {
    public:

        /*** Constructors and Destructors ***/

        MinHeap() : MinHeap(1uz) {}

        explicit MinHeap(std::size_t capacity)
            : size_{0uz}
            , capacity_{capacity}
        {
            std::allocator<T> alloc;
            data_ = alloc.allocate(capacity_);
        }

        MinHeap(const MinHeap& other) {
            copy(other);
        }

        MinHeap(MinHeap&& other) {
            move(std::move(other));
        }
        
        MinHeap(std::initializer_list<T> init) : MinHeap(init.size()) {
            for (const auto& val : init) {
                push(val);
            }
        }

        ~MinHeap() {
            std::allocator<T> alloc;
            alloc.deallocate(data_, capacity_);
        }

        /*** Operator Overloads ***/
        MinHeap& operator=(const MinHeap& other) {
            if (this != &other) {
                std::allocator<T> alloc;
                std::destroy(data_ , data_ + size_);
                alloc.deallocate(data_, capacity_);
                copy(other);
            }
            return *this;
        }
        MinHeap& operator=(MinHeap&& other) noexcept {
            if (this != &other) {
                std::allocator<T> alloc;
                std::destroy(data_, data_ + size_);
                alloc.deallocate(data_, capacity_);
                move(std::move(other));
            }
            return *this;
        }

        /*** Member Functions ***/

        bool empty() const { return size_ == 0; }
        std::size_t size() const { return size_; }
        std::size_t capacity() const { return capacity_; }

        void push(const T& value) {
            // Time: O(log n)
            // Space: O(1)
            if (++size_ >= capacity_) {
                resize();
            }

            std::size_t i = size_ - 1;
            data_[i] = value;

            while (i != 0 && data_[(i - 1) / 2] > data_[i]) {
                std::swap(data_[i], data_[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }

        T pop() {
            // Time O(log n)
            // Space O(log n)
            if (empty()) {
                throw std::runtime_error("MinHeap is empty");
            }
            if (size_ == 1) {
                --size_;
                return data_[0];
            } else {
                T root = data_[0];
                data_[0] = data_[size_ - 1];
                --size_;
                heapify(0);
                return root;
            }
        }

        T top() const {
            // Time: O(1)
            // Space: O(1)
            if (empty()) {
                throw std::runtime_error("MinHeap is empty");
            }

            return data_[0];
        }

        void DeleteNode(const T& key) {
            // Time: O(n)
            // Space: O(log n)
            std::size_t index = size_;
            for (std::size_t i = 0; i < size_; ++i) {
                if (data_[i] == key) {
                    index = i;
                    break;
                }
            }

            if (index == size_) {
                // Element not present

            } else if (index == size_ - 1) {
                --size_;
            } else {
                data_[index] = data_[size_ - 1];
                --size_;
                heapify(index);
            }
        }

        std::string to_string() const {
            if (empty()) {
                return "";
            }

            MinHeap<T> temp(*this);
            std::ostringstream oss;
            bool first = true;
            while (!temp.empty()) {
                if (!first) {
                    oss << " ";
                }
                oss << temp.pop();
                first = false;
            }
            return oss.str();
        }

        /*** Friend Functions ***/
        friend std::ostream& operator<<(std::ostream& os, const MinHeap& heap) {
            os << heap.to_string();
            return os;
        }

        friend std::istream& operator>>(std::istream& is, MinHeap& heap) {
            // Clear the heap first
            while (!heap.empty()) {
                heap.pop();
            }

            char c;
            is >> std::ws;
            if (is.peek() == '[') { is.get(c); }

            T value;
            while (is >> value) {
                heap.push(value);

                is >> std::ws;
                if (is.peek() == ',') {
                    is.get(c);
                } else if (is.peek() == ']') {
                    is.get(c);
                    break;
                }
            }

            return is;
        }

    private:
        T* data_;
        std::size_t size_;
        std::size_t capacity_;

        void resize() {
            std::size_t new_capacity = capacity_ * 2;
            std::allocator<T> alloc;
            T* new_data = alloc.allocate(new_capacity);
            std::uninitialized_move(data_, data_ + size_, new_data);
            std::destroy(data_, data_ + size_);
            alloc.deallocate(data_, capacity_);
            data_ = new_data;
            capacity_ = new_capacity;
        }

        void heapify(std::size_t i) {
            // Time: O(log n)
            // Space: O(log n)
            std::size_t root = i;
            std::size_t left = 2 * i + 1;
            std::size_t right = 2 * i + 2;

            if (left < size_ && data_[left] < data_[root]) {
                root = left;
            }

            if (right < size_ && data_[right] < data_[root]) {
                root = right;
            }

            if (root != i) {
                std::swap(data_[i], data_[root]);
                heapify(root);
            }
        }

        void copy(const MinHeap& other) {
            size_ = other.size_;
            capacity_ = other.capacity_;
            
            std::allocator<T> alloc;
            data_ = alloc.allocate(capacity_);
            std::uninitialized_copy(other.data_, other.data_ + size_, data_);
        }

        void move(MinHeap&& other) noexcept {
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;

            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }


    };

} // Namespace core
#endif // CORE_TEMPLATES_MIN_HEAP_H_