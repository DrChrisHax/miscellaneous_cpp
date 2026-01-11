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
    Fraction() : numerator_{ 0 }, denominator_ { 1 } {
        //std::cout << (*this) << " constructed.\n";
    }

    explicit Fraction(T numerator) : numerator_{ numerator}, denominator_{ 1 } {
        //std::cout << (*this) << " constructed.\n";
    }

    Fraction(T numerator, T denominator) : numerator_{ numerator }, denominator_{ denominator } {
        if (denominator_ == 0) throw std::invalid_argument("The denominator cannot be 0.");
        normalize();
        //std::cout << (*this) << " constructed.\n";
    }

    // Destructor
    ~Fraction() {
        //std::cout << (*this) << " destroyed.\n";
    };

    // Copy Constructor
    Fraction(const Fraction& other) : numerator_{ other.numerator_ }, denominator_{ other.denominator_ } {
        //std::cout << (*this) << " copy constructed.\n";
    }

    // Move Constructor
    Fraction(Fraction&& other) noexcept : numerator_{other.numerator_}, denominator_{other.denominator_} {
        //std::cout << (*this) << " move constructed.\n";
    }

    // Copy assignment operator
    Fraction& operator=(const Fraction& other) {
        //std::cout << (*this) << " copy assignment constructed.\n";

        if (this == &other) {
            // We do not really need this conditional for
            // the Fraction class, but it is here for reference.
            // Classes that hold dynamic data need to include this
            // to avoid memory leaks or data deletion when
            // assigning to itself
            return *this;
        }

        numerator_ = other.numerator_;
        denominator_ = other.denominator_;

        return *this; // Return *this so the copy assignmnet operator can be chained
    }

    // Move assignment operator
    Fraction& operator=(Fraction&& other) noexcept {
        //std::cout << (*this) << " move assignment constructed.\n";
        if (this == &other) {
            return *this;
        }

        numerator_ = other.numerator_;
        denominator_ = other.denominator_;

        return *this;
    }


    // Type casts
    explicit operator bool() const {
        return numerator_ != 0;
    }

    explicit operator float() const {
        return static_cast<float>(numerator_) / static_cast<float>(denominator_);
    }

    operator double() const {
        // Double is not marked explicit
        // because this makes the most semantic sense to 
        // be the default type cast to a primative type
        return static_cast<double>(numerator_) / static_cast<double>(denominator_);
    }

    explicit operator long double() const {
        return static_cast<long double>(numerator_) / static_cast<long double>(denominator_);
    }

    explicit operator T() const {
        return numerator_ / denominator_;
    }

    explicit operator std::string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }

    // Operator overloads
    // Comparison
    bool operator==(const Fraction& other) const {
        return (numerator_ == other.numerator_) && (denominator_ == other.denominator_);
    }

    std::strong_ordering operator<=>(const Fraction& other) const {
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

    // Imagine we have Fraction f{3/11};
    // Should f++ yield 4/11 or 14/11 ?
    // Same question for the -- operator
    // Since there is no clear answer I think it is
    // symantically best to delete these operators
    Fraction& operator++() = delete;
    Fraction& operator--() = delete;
    Fraction operator++(int x) = delete;
    Fraction operator--(int x) = delete;

    // No need for the [] operator
    // so this is just for reference
    T& operator[](int index) = delete;

    // No need for the () operator
    // so this is just for reference.
    // These can take any number of parameters
    // and return any type
    void operator()() = delete;
    void operator()() const = delete;

    // Mathematical
    Fraction operator+(const Fraction& other) const {
        // a/b + c/d = (ad + cb) / bd
        // Above is the naive method, we can instead use the LCM
        
        T lcm = std::lcm(denominator_, other.denominator_);
        T mult1 = lcm / denominator_;
        T mult2 = lcm / other.denominator_;

        if (would_overflow_multiplication<T>(numerator_, mult1)) {
            throw std::overflow_error("Addition would overflow in first term");
        }
        if (would_overflow_multiplication<T>(other.numerator_, mult2)) {
            throw std::overflow_error("Addition would overflow in second term");
        }

        T term1 = numerator_ * mult1;
        T term2 = other.numerator_ * mult2;

        if (would_overflow_addition<T>(term1, term2)) {
            throw std::overflow_error("Addition would overflow in final sum");
        }

        T num = term1 + term2;

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
    
private:
    T numerator_ {0};
    T denominator_ {1};

    // TODO: In the future, make a rational fraction that 
    // holds a whole number part
    // Each object will take 50% more space but it will also
    // be able to hold a much larger range

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
    return static_cast<std::string>(f);
}
template<std::integral T>
const Fraction<T>& max(const Fraction<T>& a, const Fraction<T>& b) {
    return (a < b) ? b : a;
}


#endif // TEMPLATES_FRACTION_H_