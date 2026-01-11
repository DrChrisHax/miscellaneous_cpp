#ifndef CORE_VECTOR_H_
#define CORE_VECTOR_H_

#include <initializer_list>
#include <memory>

template <typename T, class Allocator = std::allocator<T>>
class Vector {
public:

    /*** Constructors and Destructor ***/
    // Constructors
    Vector() noexcept;

    // Fill constructor
    explicit Vector(const std::size_t size);
    Vector(const std::size_t size, const T& value);

    // Copy constructor
    Vector(const Vector& other);

    // Move constructor
    Vector(Vector&& other);

    // Initializer List constructor
    Vector(std::initializer_list<T> list);

    // Destructor
    ~Vector();

    /*** Operator Overloads ***/
    Vector& operator=(const Vector& other); // Copy assignment operator
    Vector& operator=(Vector&& other); // Move assignment operator
    Vector& operator=(std::initializer_list<T> list); // Initializer list assigmnet operator

    T& operator[](const std::size_t index);
    const T& operator[](const std::size_t index);

    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

    /*** Element Access ***/
    T& at(const std::size_t index);
    const T& at(const std::size_t index) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back();

    /*** Iterators ***/
    T* begin() noexcept;
    const T* begin() const noexcept;
    const T* cbegin() const noexcept;
    T* end() noexcept;
    const T* end() const noexcept;
    const T* cend const noexcept;

    /*** Modifiers ***/
    void push_back(const T* value);
    void push_back(const T&& value);
    void pop_back();

    T* erase(T* index);
    T* erase(T* first, T* last);
    void clear();

    void resize(const std::size_t new_size);
    void reserve(const size_t new_size);
    void shrink_to_fit();

    /*** Size & Capacity ***/
    bool empty() const noexcept;
    std::size_t size() const noexcept;
    std::size_t capacity() const noexcept;
    std::size_t max_size() const noexcept;

private:
    std::size_t size_;
    std::size_t capacity_;
    T* data_;

};

#endif // CORE_VECTOR_H_