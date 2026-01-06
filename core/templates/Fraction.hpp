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
#include <concepts>

template<std::integral T>
class Fraction {
public:

    // Constructors
    Fraction() : numerator_{ 0 }, denominator_ { 1 } {}
    explicit Fraction(T numerator) : numerator_{ numerator}, denominator_{ 1 } {}
    Fraction(T numerator, T denominator) : numerator_{ numerator }, denominator_{ denominator } {
        if (denominator_ == 0) throw std::invalid_argument("The denominator cannot be 0.");
        normalize();
    }

    Fraction(const Fraction& fraction) = default;

    explicit operator bool() const {
        return numerator_ != 0;
    }

    // Operator overloads
    // Comparison
    bool operator==(const Fraction& other) const {
        return (numerator_ == other.numerator_) && (denominator_ == other.denominator_);
    }

    std::strong_ordering operator<=>(const Fraction& other) {
        Fraction diff = (*this) - other;
        if (diff.numerator_ < 0) return std::strong_ordering::less;
        if (diff.numerator_ > 0) return std::strong_ordering::greater;
        return std::strong_ordering::equal;
    }

    //Unary
    Fraction operator+() const {
        return Fraction{numerator_, denominator_};
    }

    Fraction operator-() const {
        return Fraction{-numerator_, denominator_};
    }

    bool operator!() const {
        return (numerator_ == 0);
    }

    // Mathematical
    Fraction operator+(const Fraction& other) const {
        // a/b + c/d = (ad + cb) / bd
        // Above is the naive method, we can instead use the LCM
        
        T lcm = std::lcm(denominator_, other.denominator_);
        T num = (numerator_ * (lcm / denominator_)) + (other.numerator_ * (lcm / other.denominator_));

        return Fraction{num, lcm};
    }

    Fraction operator-(const Fraction& other) const {
        return (*this) + Fraction{-other.numerator_, other.denominator_};
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
        // Use the property that 1/2 / 3/4 = 1/2 * 4/3
        return (*this) * Fraction{other.denominator_, other.numerator_};
    }

    Fraction& operator+=(const Fraction& other) {
        *this = (*this) + other;
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {
        *this = (*this) - other;
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {
        *this = (*this) * other;
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {
        *this = (*this) / other;
        return *this;
    }

    // Arithmetic friend functions
    friend Fraction operator+(T x, const Fraction& f) {
        return Fraction{x} + f;
    }
    friend Fraction operator+(const Fraction& f, T x) {
        return Fraction{x} + f;
    }

    friend Fraction operator-(T x, const Fraction& f) {
        return Fraction{x} - f;
    }
    friend Fraction operator-(const Fraction& f, T x) {
        return f - Fraction{x};
    }

    friend Fraction operator*(T x, const Fraction& f) {
        return Fraction{f.numerator_ * x, f.denominator_};
    }
    friend Fraction operator*(const Fraction& f, T x) {
        return x * f;
    }

    friend Fraction operator/(T x, const Fraction& f) {
        return Fraction{x * f.denominator_, f.numerator_};
    }
    friend Fraction operator/(const Fraction& f, T x) {
        return Fraction{f.numerator_, f.denominator_ * x};
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
        T n{};
        char ignore{};
        T d{};

        is >> n >> ignore >> d;
        if (d == 0){ is.setstate(std::ios_base::failbit); }
        if (is){ f = Fraction{n, d}; }

        return is;
    }
        
    friend double to_double(const Fraction<T>& f) {
        return static_cast<double>(f.numerator_) / f.denominator_;
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

template<std::integral T>
std::string to_string(const Fraction<T>& f) {
    std::ostringstream oss;
    oss << f;
    return oss.str();
}



#endif // TEMPLATES_FRACTION_H_