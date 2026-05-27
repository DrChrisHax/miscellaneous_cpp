#include "SimpleLock.hpp"

#include <thread>

namespace core {

    
    void SimpleLock::lock() {
        while (true) {
            bool unlocked = UNLOCKED;
            if (state_.compare_exchange_weak(unlocked, LOCKED, 
                    std::memory_order_acquire, 
                    std::memory_order_relaxed)) return;

            for (int i = 0; i < 64; ++i) {
                if (!state_.load(std::memory_order_relaxed)) break;
            }

            if (state_.load(std::memory_order_relaxed)) std::this_thread::yield();
        }
    }

    bool SimpleLock::try_lock() {
        bool unlocked = UNLOCKED;
        return state_.compare_exchange_strong(unlocked, LOCKED, 
                std::memory_order_acquire, 
                std::memory_order_relaxed);
    }

    void SimpleLock::unlock() {
        state_.store(UNLOCKED, std::memory_order_release);
    }

} // namespace core
