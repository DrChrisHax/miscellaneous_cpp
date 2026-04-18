#ifndef CORE_AVERAGE_CALCULATOR_HPP_
#define CORE_AVERAGE_CALCULATOR_HPP_

#include <stdexcept>

namespace core {

    class AverageCalculator {
    public:
    
        AverageCalculator() = default;
        AverageCalculator(double value) 
            : count_{1}
            , total_{value}
        {}

        AverageCalculator& operator+=(double value) {
            total_ += value;
            ++count_;
            return *this;
        }

        double constexpr operator()() const {
            if (count_ == 0) throw std::logic_error("No elements");
            return total_ / count_;
        }

    private:
        unsigned int count_{0};
        double total_{0};
    };


}



#endif // CORE_AVERAGE_CALCULATOR_HPP_