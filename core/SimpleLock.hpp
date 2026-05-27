#ifndef CORE_SIMPLE_LOCK_HPP_
#define CORE_SIMPLE_LOCK_HPP_

#include <atomic>

namespace core {

    class SimpleLock {
    public:
        
        SimpleLock() = default;
        ~SimpleLock() = default;

        SimpleLock(const SimpleLock& other) = delete;
        SimpleLock& operator=(const SimpleLock& other) = delete;
        SimpleLock(SimpleLock&& other) = delete;
        SimpleLock& operator=(SimpleLock&& other) = delete;

        void lock();
        bool try_lock();
        void unlock();

    private:
        static constexpr bool UNLOCKED = false;
        static constexpr bool LOCKED = true;

        std::atomic<bool> state_;
    };
} // namespace core

#endif // CORE_SIMPLE_LOCK_HPP_