// Fraction.hpp
#ifndef TEMPLATES_FRACTION_H_
#define TEMPLATES_FRACTION_H_

#include <string>
#include <stdexcept>
#include <numeric>
#include <iostream>

template<typename T>
class Fraction {
public:

    // Constructors
    Fraction(T numerator = 0, T denominator = 1) 
        : numerator_{ numerator }, denominator_{ denominator } {
        if (denominator_ == 0) throw std::invalid_argument("The denominator cannot be 0.");
        normalize();
    }

    // Getters & Setters
    T get_numerator() const { return numerator_; }
    T get_denominator() const { return denominator_; }

    
private:
    T numerator_ {0};
    T denominator_ {1};

    void normalize() {
        bool isNegative = (numerator_ < 0) ^ (denominator_ < 0);

        numerator_ = std::abs(numerator_);
        denominator_ = std::abs(denominator_);

        if (denominator_ == 1) {
            numerator_ = (isNegative)? -numerator_ : numerator_;
            return;
        }

        T gcd = std::gcd(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;

        numerator_ = (isNegative)? -numerator_ : numerator_;
    }
};

template<typename T>
std::string to_string(const Fraction<T>& f) {
    if (f.get_denominator() == 1) {
        return std::to_string(f.get_numerator());
    } else {
        return std::to_string(f.get_numerator()) + "/" + std::to_string(f.get_denominator());
    }
}


#endif // TEMPLATES_FRACTION_H_