#ifndef CORE_TIMER_HPP_
#define CORE_TIMER_HPP_

#include <chrono>
#include <string>

namespace core {
    
    class Timer{
    public:
        using Clock = std::chrono::steady_clock;
        using TimePoint = Clock::time_point;
        using Duration = std::chrono::nanoseconds;

        void start() {
            start_ = Clock::now();
        }

        void stop() {
            end_ = Clock::now();
        }

        [[nodiscard]] Duration elapsed() const {
            return std::chrono::duration_cast<Duration>(end_ - start_);
        }

        [[nodiscard]] std::string elapsed_str() const {
            return elapsed_str(elapsed());
        }

        [[nodiscard]] std::string elapsed_str(Duration duration) const {
            auto ns = duration.count();
            if (ns < 1'000LL) return std::to_string(ns) + " ns";
            if (ns < 1'000'000LL) return std::to_string(static_cast<double>(ns) / 1'000.0) + " us";
            if (ns < 1'000'000'000LL) return std::to_string(static_cast<double>(ns) / 1'000'000.0) + " ms";
            return std::to_string(static_cast<double>(ns) / 1'000'000'000.0) + " s";
        }

    private:
        TimePoint start_{};
        TimePoint end_{};
    };
    
} // namespace core

#endif // CORE_TIMER_HPP_