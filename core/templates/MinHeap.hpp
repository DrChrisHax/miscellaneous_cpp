#ifndef CORE_TEMPLATES_MIN_HEAP_H_
#define CORE_TEMPLATES_MIN_HEAP_H_

#include <vector>
#include <stdexcept>
#include <memory>

namespace core {
        
    template <typename T>
    class MinHeap {
    public:

        /*** Constructors and Destructors ***/
        MinHeap()
            : size_{0uz}
            , capacity_{1uz}
        {
            std::allocator<T> alloc;
            data_ = alloc.allocate(capacity_);
        }

        ~MinHeap() {
            std::allocator<T> alloc;
            alloc.deallocate(data_, capacity_);
        }

        /*** Operator Overloads ***/

        /*** Member Functions ***/

        bool Empty() const {
            return size_ == 0;
        }

        void Heapify(std::size_t i) {
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
                Heapify(root);
            }
        }

        void BuildHeap(const T* data, const std::size_t capacity) {
            // Time: O(n)
            // Space: O(log n)
            capacity_{capacity};
            size_{capacity};
            data_{data};

            for (std::size_t i{capacity - 1} / 2; i >= 0; --i) {
                Heapify(i);
            }
        }

        void Push(const T& value) {
            // Time: O(log n)
            // Space: O(1)
            if (++size_ >= capacity_) {
                Resize();
            }

            std::size_t i = size - 1;
            data_[i] = value;

            while (i != 0 && data_[(i - 1) / 2] > data_[i]) {
                std::swap(data_[i], data_[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }

        void Pop() {
            // Time O(log n)
            // Space O(log n)
            if (Empty()) {
                throw std::runtime_error("MinHeap is empty");
            }

            
            

        }

        T& Peek() {
            // Time: O(1)
            // Space: O(1)
            if (Empty()) {
                throw std::runtime_error("MinHeap is empty");
            }

            return data_[0];
        }

        void DeleteNode() {
            // Time: O(log n)
            // Space: O(log n)
        }

    private:
        T* data_;
        std::size_t size_;
        std::size_t capacity_;

        void Resize() {
            std::size_t new_capacity = capacity_ * 2;
            std::allocator<T> alloc;
            T* new_data = alloc.allocate(new_capacity);

            for (std::size_t i{0uz}; i < size_; ++i) {
                alloc.construct(new_data + i, data_[i]);
                alloc.destroy(data_ + i);
            }

            alloc.deallocate(data_, capacity_);
            data_ = new_data;
            capacity_ = new_capacity;
        }
    };
}



#endif // CORE_TEMPLATES_MIN_HEAP_H_