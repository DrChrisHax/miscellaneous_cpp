#ifndef CORE_SIMPLE_LOCK_HPP_
#define CORE_SIMPLE_LOCK_HPP_

namespace core {

    class SimpleLock {
    public:
        
        SimpleLock() = default;
        ~SimpleLock() = default;

        SimpleLock(const SimpleLock& other) = delete;
        SimpleLock& operator=(const SimpleLock& other) = delete;
        SimpleLock(SimpleLock&& other) = delete;
        SimpleLock& operator=(SImpleLock&& other) = delete;

        lock();
        try_lock();
        unlock();

    private:
        static constexpr bool UNLOCKED = false;
        static constexpr bool LOCKED = true;

        std::atomic<bool> isLocked_;
    };
}

#endif // CORE_SIMPLE_LOCK_HPP_