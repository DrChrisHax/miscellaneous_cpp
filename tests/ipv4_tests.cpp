#include "tests.h"
#include "IPv4.h"

#include <string>
#include <sstream>
#include <cstring> // For memcpy

// =============================================================================
// Constructor Tests
// =============================================================================

bool ipv4_constructor_default() {
    std::cout << "[TEST] IPv4 default constructor creates 0.0.0.0\n";
    
    core::IPv4 addr;
    std::string expected = "0.0.0.0";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_constructor_uint32() {
    std::cout << "[TEST] IPv4 uint32_t constructor (0x7F000001 -> 127.0.0.1)\n";
    
    core::IPv4 addr{0x7F000001};
    std::string expected = "127.0.0.1";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_constructor_four_octets() {
    std::cout << "[TEST] IPv4 four-octet constructor (192, 168, 1, 100)\n";
    
    core::IPv4 addr{192, 168, 1, 100};
    std::string expected = "192.168.1.100";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_constructor_four_octets_max() {
    std::cout << "[TEST] IPv4 four-octet constructor (255, 255, 255, 255)\n";
    
    core::IPv4 addr{255, 255, 255, 255};
    std::string expected = "255.255.255.255";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_constructor_string_valid() {
    std::cout << "[TEST] IPv4 string constructor (\"10.0.0.1\")\n";
    
    core::IPv4 addr{"10.0.0.1"};
    std::string expected = "10.0.0.1";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_constructor_string_loopback() {
    std::cout << "[TEST] IPv4 string constructor (\"127.0.0.1\")\n";
    
    core::IPv4 addr{"127.0.0.1"};
    std::string expected = "127.0.0.1";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_constructor_string_invalid_throws() {
    std::cout << "[TEST] IPv4 string constructor throws on invalid format\n";
    
    try {
        core::IPv4 addr{"not.an.ip"};
        return test_helper("exception", "no exception");
    } catch (const std::invalid_argument&) {
        return test_helper("exception", "exception");
    } catch (...) {
        return test_helper("invalid_argument", "other exception");
    }
}

bool ipv4_constructor_string_out_of_range_throws() {
    std::cout << "[TEST] IPv4 string constructor throws on octet > 255\n";
    
    try {
        core::IPv4 addr{"192.168.1.256"};
        return test_helper("exception", "no exception");
    } catch (const std::out_of_range&) {
        return test_helper("exception", "exception");
    } catch (const std::invalid_argument&) {
        // Also acceptable
        return test_helper("exception", "exception");
    } catch (...) {
        return test_helper("out_of_range or invalid_argument", "other exception");
    }
}

// =============================================================================
// Static Factory Tests
// =============================================================================

bool ipv4_from_network_order_little_endian() {
    std::cout << "[TEST] IPv4::from_network_order (0x0100007F -> 127.0.0.1 on LE)\n";
    
    // Simulate bytes arriving from network: [127, 0, 0, 1]
    // When memcpy'd into a uint32_t, the value depends on system endianness
    uint8_t network_bytes[4] = {0xAB, 0xCD, 0xEF, 0x12};
    uint32_t network_order;
    std::memcpy(&network_order, network_bytes, sizeof(network_order));

    core::IPv4 addr = core::IPv4::from_network_order(network_order);
    
    // Verify the value is correctly converted
    std::string expected = "171.205.239.18";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_from_host_order() {
    std::cout << "[TEST] IPv4::from_host_order (0xC0A80101 -> 192.168.1.1)\n";
    
    core::IPv4 addr = core::IPv4::from_host_order(0xC0A80101);
    std::string expected = "192.168.1.1";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_static_any() {
    std::cout << "[TEST] IPv4::any() returns 0.0.0.0\n";
    
    core::IPv4 addr = core::IPv4::any();
    std::string expected = "0.0.0.0";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_static_loopback() {
    std::cout << "[TEST] IPv4::loopback() returns 127.0.0.1\n";
    
    core::IPv4 addr = core::IPv4::loopback();
    std::string expected = "127.0.0.1";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_static_broadcast() {
    std::cout << "[TEST] IPv4::broadcast() returns 255.255.255.255\n";
    
    core::IPv4 addr = core::IPv4::broadcast();
    std::string expected = "255.255.255.255";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_static_localhost() {
    std::cout << "[TEST] IPv4::localhost() equals loopback()\n";
    
    core::IPv4 localhost = core::IPv4::localhost();
    core::IPv4 loopback = core::IPv4::loopback();
    
    std::string expected = "true";
    std::string result = (localhost == loopback) ? "true" : "false";
    
    return test_helper(expected, result);
}

// =============================================================================
// Accessor Tests
// =============================================================================

bool ipv4_octect() {
    std::cout << "[TEST] IPv4 octet(index) accessor (192.168.254.127)\n";
    
    core::IPv4 addr{192, 168, 254, 127};
    
    std::ostringstream oss;
    oss << static_cast<uint32_t>(addr.octet(0)) << "."
        << static_cast<uint32_t>(addr.octet(1)) << "."
        << static_cast<uint32_t>(addr.octet(2)) << "."
        << static_cast<uint32_t>(addr.octet(3));
    
    std::string expected = "192.168.254.127";
    std::string result = oss.str();
    
    return test_helper(expected, result);
}

bool ipv4_cotect_out_of_range() {
    std::cout << "[TEST] IPv4 octet(index) throws on index > 3\n";
    
    core::IPv4 addr{192, 168, 254, 127};
    
    try {
        addr.octet(4);
        return test_helper("exception", "no exception");
    } catch (const std::out_of_range&) {
        return test_helper("exception", "exception");
    } catch (...) {
        return test_helper("out_of_range", "other exception");
    }
}

bool ipv4_a_b_c_d() {
    std::cout << "[TEST] IPv4 a(), b(), c(), d() accessors (10.20.30.40)\n";
    
    core::IPv4 addr{10, 20, 30, 40};
    
    std::ostringstream oss;
    oss << static_cast<uint32_t>(addr.a()) << "."
        << static_cast<uint32_t>(addr.b()) << "."
        << static_cast<uint32_t>(addr.c()) << "."
        << static_cast<uint32_t>(addr.d());
    
    std::string expected = "10.20.30.40";
    std::string result = oss.str();
    
    return test_helper(expected, result);
}

bool ipv4_octects_array() {
    std::cout << "[TEST] IPv4 octets() returns array [172, 16, 254, 1]\n";
    
    core::IPv4 addr{172, 16, 254, 1};
    auto octets = addr.octets();
    
    std::ostringstream oss;
    oss << static_cast<uint32_t>(octets[0]) << "."
        << static_cast<uint32_t>(octets[1]) << "."
        << static_cast<uint32_t>(octets[2]) << "."
        << static_cast<uint32_t>(octets[3]);
    
    std::string expected = "172.16.254.1";
    std::string result = oss.str();
    
    return test_helper(expected, result);
}

bool ipv4_value() {
    std::cout << "[TEST] IPv4 value() returns uint32_t (0xC0A8FE7F for 192.168.1.100)\n";
    
    core::IPv4 addr{192, 168, 254, 127};
    uint32_t expected = 0xC0A8FE7F;
    uint32_t result = addr.value();
    
    return test_helper(std::to_string(expected), std::to_string(result));
}
