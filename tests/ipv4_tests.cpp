#include "tests.h"
#include "IPv4.h"

#include <string>
#include <sstream>

// =============================================================================
// Constructor Tests
// =============================================================================

bool ipv4_constructor_default() {
    std::cout << "[TEST] IPv4 default constructor creates 0.0.0.0: ";
    
    core::IPv4 addr;
    std::string expected = "0.0.0.0";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_constructor_uint32() {
    std::cout << "[TEST] IPv4 uint32_t constructor (0x7F000001 -> 127.0.0.1): ";
    
    core::IPv4 addr{0x7F000001};
    std::string expected = "127.0.0.1";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_constructor_four_octets() {
    std::cout << "[TEST] IPv4 four-octet constructor (192, 168, 1, 100): ";
    
    core::IPv4 addr{192, 168, 1, 100};
    std::string expected = "192.168.1.100";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_constructor_four_octets_max() {
    std::cout << "[TEST] IPv4 four-octet constructor (255, 255, 255, 255): ";
    
    core::IPv4 addr{255, 255, 255, 255};
    std::string expected = "255.255.255.255";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_constructor_string_valid() {
    std::cout << "[TEST] IPv4 string constructor (\"10.0.0.1\"): ";
    
    core::IPv4 addr{"10.0.0.1"};
    std::string expected = "10.0.0.1";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_constructor_string_loopback() {
    std::cout << "[TEST] IPv4 string constructor (\"127.0.0.1\"): ";
    
    core::IPv4 addr{"127.0.0.1"};
    std::string expected = "127.0.0.1";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_constructor_string_invalid_throws() {
    std::cout << "[TEST] IPv4 string constructor throws on invalid format: ";
    
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
    std::cout << "[TEST] IPv4 string constructor throws on octet > 255: ";
    
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
    std::cout << "[TEST] IPv4::from_network_order (0x0100007F -> 127.0.0.1 on LE): ";
    
    // 127.0.0.1 in network byte order (big endian) is 0x7F000001
    // On a little-endian machine, if you have the bytes [0x7F, 0x00, 0x00, 0x01] 
    // stored in memory, reading as uint32_t gives 0x0100007F
    uint32_t network_order = 0x7F000001; // Already in network byte order representation
    core::IPv4 addr = core::IPv4::from_network_order(network_order);
    
    // Verify the value is correctly converted
    std::string expected = "127.0.0.1";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_from_host_order() {
    std::cout << "[TEST] IPv4::from_host_order (0xC0A80101 -> 192.168.1.1): ";
    
    core::IPv4 addr = core::IPv4::from_host_order(0xC0A80101);
    std::string expected = "192.168.1.1";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_static_any() {
    std::cout << "[TEST] IPv4::any() returns 0.0.0.0: ";
    
    core::IPv4 addr = core::IPv4::any();
    std::string expected = "0.0.0.0";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_static_loopback() {
    std::cout << "[TEST] IPv4::loopback() returns 127.0.0.1: ";
    
    core::IPv4 addr = core::IPv4::loopback();
    std::string expected = "127.0.0.1";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_static_broadcast() {
    std::cout << "[TEST] IPv4::broadcast() returns 255.255.255.255: ";
    
    core::IPv4 addr = core::IPv4::broadcast();
    std::string expected = "255.255.255.255";
    std::string result = addr.to_string();
    
    return test_helper(expected, result);
}

bool ipv4_static_localhost() {
    std::cout << "[TEST] IPv4::localhost() equals loopback(): ";
    
    core::IPv4 localhost = core::IPv4::localhost();
    core::IPv4 loopback = core::IPv4::loopback();
    
    std::string expected = "true";
    std::string result = (localhost == loopback) ? "true" : "false";
    
    return test_helper(expected, result);
}