// Fraction.hpp
#ifndef TEMPLATES_FRACTION_H_
#define TEMPLATES_FRACTION_H_

#include "math_helpers.hpp"

#include <string>
#include <stdexcept>
#include <numeric>
#include <type_traits>
#include <iostream>
#include <sstream>

template<typename T>
class Fraction {
public:

    // Constructors
    Fraction() : numerator_{ 0 }, denominator_ { 1 } {
        static_assert(std::is_integral_v<T>, "Fraction type must be integral");
    }

    explicit Fraction(T numerator) : numerator_{ numerator}, denominator_{ 1 } {
        // I added explicit to prevent nonsense like
        // Fraction<int> f1 = {1, 2};
        // Fraction<int> f2 = f1 * true; // We don't want true cast to 1/1, it semantically does not make sense
        static_assert(std::is_integral_v<T>, "Fraction type must be integral");
    }

    Fraction(T numerator, T denominator) : numerator_{ numerator }, denominator_{ denominator } {
        static_assert(std::is_integral_v<T>, "Fraction type must be integral");
        if (denominator_ == 0) throw std::invalid_argument("The denominator cannot be 0.");
        normalize();
    }

    Fraction(const Fraction& fraction) = default;

    // Operator overloads
    // Comparison
    bool operator==(const Fraction& other) const {
        return (numerator_ == other.numerator_) && (denominator_ == other.denominator_);
    }

    // Mathematical
    Fraction operator+(const Fraction& other) const {
        return {0, 1};
    }

    Fraction operator-(const Fraction& other) const {
        return {0, 1};
    }

    Fraction operator*(const Fraction& other) const {
        // The two fractions passed in will already be normalized
        // so we can swap the numerators and normalize again
        // These two normalizes will cut down on the number of overflows as well as
        // prevent us from having to normalize after multiplying

        Fraction f1{other.numerator_, denominator_};
        Fraction f2{numerator_, other.denominator_};

        if (would_overflow_multiplication<T>(f1.numerator_, f2.numerator_)) {
            throw std::overflow_error("Multiplication would overflow numerator");
        }
        if (would_overflow_multiplication<T>(f1.denominator_, f2.denominator_)) {
            throw std::overflow_error("Multiplication would overflow denominator");
        }

        T new_numerator = f1.numerator_ * f2.numerator_;
        T new_denominator = f1.denominator_ * f2.denominator_;

        return {new_numerator, new_denominator};

        // T new_numerator = numerator_ * other.numerator_;
        // T new_denominator = denominator_ * other.denominator_; 
        // return {new_numerator, new_denominator};
    }

    Fraction operator/(const Fraction& other) const {
        return {0, 1};
    }

    // Friend functions
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        if (f.denominator_ == 1) {
            os << f.numerator_;
        } else {
            os << f.numerator_ << "/" << f.denominator_;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Fraction& f) {

        return is;
    }

    
private:
    T numerator_ {0};
    T denominator_ {1};

    void normalize() {
        bool isNegative = (numerator_ < 0) ^ (denominator_ < 0);

        if (numerator_ < 0) numerator_ = -numerator_;
        if (denominator_ < 0) denominator_ = -denominator_;

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
    std::ostringstream oss;
    oss << f;
    return oss.str();
}


#endif // TEMPLATES_FRACTION_H_