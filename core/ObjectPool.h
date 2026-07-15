#pragma once

#include <cstddef>
#include <span>

/// Fixed-capacity pool that owns its objects' lifetimes.
///
/// Memory is ONE contiguous block of cells. Each cell is a union:
///   - a live Object, or
///   - a pointer to the next free cell.
///
/// free_head_ is the top of a LIFO stack threaded through the FREE cells, so
/// the free list needs no extra storage. Below, cells #1 #3 #5 are free and
/// chained; #0 #2 #4 hold live objects:
///
///     +--------+--------+--------+--------+--------+--------+
///     |  Obj   |  free  |  Obj   |  free  |  Obj   |  free  |
///     +--------+--------+--------+--------+--------+--------+
///         #0       #1       #2       #3       #4       #5
///
///     free_head_ --> #1 --> #3 --> #5 --> nullptr
///
/// TakeObject() -> pop the top free cell, construct an Object in it.
/// ReturnObject() -> destroy the Object, push its cell back on top.


template <typename Object>
class ObjectPool {
public:

    explicit ObjectPool(std::size_t capacity);
    ~ObjectPool();

    ObjectPool(const ObjectPool&) = delete;
    ObjectPool& operator=(const ObjectPool&) = delete;
    ObjectPool(ObjectPool&&) = delete;
    ObjectPool&& operator=(ObjectPool&&) = delete;

    template <typename... Args>
    Object* TakeObject(Args&&... args);

    void ReturnObject(Object* obj);

    std::size_t Capacity() const { return capacity_; }
    std::size_t Used() const { return used_; }
    std::size_t Available() const { return capacity_ - used_; }

private:

    union Cell {
        alignas(Object) std::byte storage[sizeof(Object)];
        Cell* next;
    };

    Cell* cells_;
    Cell* free_head_;
    std::size_t capacity_;
    std::size_t used_;
};
