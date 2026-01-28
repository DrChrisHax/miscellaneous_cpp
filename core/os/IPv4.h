#ifndef CORE_OS_IPV4_H_
#define CORE_OS_IPV4_H_

#include <cstdint>
#include <string>
#include <string_view>
#include <stdexcept>
#include <array>
#include <compare>
#include <iostream>

namespace core {
    class IPv4 {
    public:

        /*** Constructors ***/
        constexpr IPv4() : value_{0} {}
        constexpr explicit IPv4(uint32_t addr) : value_{addr} {}
        constexpr IPv4(uint8_t a, uint8_t b, uint8_t c, uint8_t d) 
            : value_{static_cast<uint32_t>((a << 24) | (b << 16) | (c << 8) | d)} {}
        explicit IPv4(std::string_view addr);

        /*** Static Methods ***/
        static IPv4 from_network_order(uint32_t network_order_value);

        // Common addresses
        static constexpr IPv4 any()       { return IPv4{0u}; }
        static constexpr IPv4 loopback()  { return IPv4{127, 0, 0, 1}; }
        static constexpr IPv4 broadcast() { return IPv4{255, 255, 255, 255}; }
        static constexpr IPv4 localhost() { return loopback(); }

        /*** Accessors ***/
        constexpr uint8_t octet(std::size_t index) const {
            if (index > 3) {
                throw std::out_of_range("Octet index must be 0-3");
            }
            return static_cast<uint8_t>((value_ >> (24 - (index * 8))) & 0xFF);
        }

        constexpr uint8_t a() const { return static_cast<uint8_t>((value_ >> 24) & 0xFF); }
        constexpr uint8_t b() const { return static_cast<uint8_t>((value_ >> 16) & 0xFF); }
        constexpr uint8_t c() const { return static_cast<uint8_t>((value_ >> 8) & 0xFF); }
        constexpr uint8_t d() const { return static_cast<uint8_t>(value_ & 0xFF); }

        constexpr std::array<uint8_t, 4> octets() const {
            return {a(), b(), c(), d()};
        }

        constexpr uint32_t value() const { return value_; }

        /*** Conversion Methods ***/
        std::string to_string() const;
        uint32_t to_network_order() const;

        /*** Address classification ***/
        constexpr bool is_set() const { return value_ != 0; }
        constexpr bool is_any() const { return value_ == 0; }
        constexpr bool is_loopback() const { return a() == 127; }
        constexpr bool is_broadcast() const { return value_ == 0xFFFFFFFF; }
        constexpr bool is_multicast() const { return (a() >= 224) && (a() <= 239); }
        constexpr bool is_private_class_a() const { return (a() == 10); }
        constexpr bool is_public_class_a() const { return (a() >= 1) && (a() < 127) && !(is_private_class_a()); }
        constexpr bool is_private_class_b() const { return (a() == 172) && (b() >= 16) && (b() < 32); }
        constexpr bool is_public_class_b() const { return (a() >= 128) && (a() < 192) && !(is_private_class_b()); }
        constexpr bool is_private_class_c() const { return (a() == 192) && (b() == 168); }
        constexpr bool is_public_class_c() const { return (a() >= 192) && (a() < 224) && !(is_private_class_c()); }
        constexpr bool is_class_d() const { return (a() >= 224) && (a() < 240); }
        constexpr bool is_class_e() const { return a() >= 240; }
        constexpr bool is_link_local() const { return (a() == 169) && (b() == 254); }
        constexpr bool is_reserved() const { return is_any() || is_broadcast() || is_loopback() || is_multicast() || is_link_local(); }
        constexpr bool is_private() const { return is_private_class_a() || is_private_class_b() || is_private_class_c(); }
        constexpr bool is_public() const { return !is_private() && !is_reserved(); }

        /*** Subnet Operations ***/
        // CIDR
        constexpr IPv4 apply_mask(uint8_t prefix_length) const {
            if (prefix_length > 32) {
                throw std::out_of_range("Prefix length must be 0-32");
            }
            if (prefix_length == 0) return IPv4{0u};
            if (prefix_length == 32) return *this;

            uint32_t mask = ~((1u << (32 - prefix_length)) - 1);
            return IPv4{value_ & mask};
        }

        constexpr bool is_in_subnet(const IPv4& network, uint8_t prefix_length) const {
            return apply_mask(prefix_length) == network.apply_mask(prefix_length);
        }

        static constexpr IPv4 netmask_from_prefix(uint8_t prefix_length) {
            if (prefix_length > 32) {
                throw std::out_of_range("Prefix length must be 0-32");
            }
            if (prefix_length == 0) return IPv4{0u};
            if (prefix_length == 32) return IPv4{0xFFFFFFFFu};

            uint32_t mask = ~((1u << (32 - prefix_length)) - 1);
            return IPv4{mask};
        }

        /*** Comparison Operators ***/
        constexpr auto operator<=>(const IPv4&) const = default;

        /*** Arithmetic Operators ***/
        constexpr IPv4& operator++() {
            if (value_ == 0xFFFFFFFF) {
                throw std::overflow_error("IPv4 addition would cause an overflow.");
            }
            ++value_;
            return *this;
        }

        constexpr IPv4 operator++(int) {
            if (value_ == 0xFFFFFFFF) {
                throw std::overflow_error("IPv4 addition would cause an overflow.");
            }
            IPv4 temp{*this};
            ++value_;
            return temp;
        }

        constexpr IPv4& operator--() {
            if (value_ == 0x00) {
                throw std::underflow_error("IPv4 subtraction would cause an underflow.");
            }
            --value_;
            return *this;
        }

        constexpr IPv4 operator--(int) {
            if (value_ == 0x00) {
                throw std::underflow_error("IPv4 subtraction would cause an underflow.");
            }
            IPv4 temp{*this};
            --value_;
            return temp;
        }

        constexpr IPv4 operator+(uint32_t value) const {
            if ((0xFFFFFFFF - value) < value_) {
                throw std::overflow_error("IPv4 addition would cause an overflow.");
            }
            return IPv4{value_ + value};
        }

        constexpr IPv4 operator-(uint32_t value) const {
            if (value > value_) {
                throw std::underflow_error("IPv4 subtraction would cause an underflow.");
            }
            return IPv4{value_ - value};
        }

        constexpr uint32_t operator-(const IPv4& other) const {
            if (other.value_ > value_) {
                throw std::underflow_error("IPv4 subtraction would cause an underflow.");
            }
            return value_ - other.value_;
        }

        /*** Non-Member Functions ***/
        friend std::ostream& operator<<(std::ostream& os, const IPv4& addr) {
            return os << std::to_string(addr.a()) << '.' 
                      << std::to_string(addr.b()) << '.' 
                      << std::to_string(addr.c()) << '.' 
                      << std::to_string(addr.d());
        }

        friend std::istream& operator>>(std::istream& is, IPv4& addr) {
            uint8_t a, b, c, d;
            char dot1, dot2, dot3;

            if (is >> a >> dot1 >> b >> dot2 >> c >> dot3 >> d) {
                if (dot1 == '.' && dot2 == '.' && dot3 == '.' &&
                    a <= 255 && b <= 255 && c <= 255 && d <= 255) {
                    addr = IPv4{a, b, c, d};
                } else {
                    is.setstate(std::ios::failbit);
                }
            } else {
                is.setstate(std::ios::failbit);
            }
            return is;
        }

    private:
        uint32_t value_; // Stored in host byte order
    };
} // namespace core

#endif // CORE_OS_IPV4_H_