#ifndef CORE_TIMER_H_
#define CORE_TIMER_H_

#include <chrono>

namespace core {


    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1> >;

    class Timer {
    public:
        void reset() { begin_ = Clock::now(); }
        double elapsed() const { return std::chrono::duration_cast<Second>(Clock::now() - begin_).count(); }
    
    private:
        std::chrono::time_point<Clock> begin_{ Clock::now() };
    };
};

#endif // CORE_TIMER_H_