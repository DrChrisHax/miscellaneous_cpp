#ifndef CORE_IP_HEADER_H_
#define CORE_IP_HEADER_H_

#include <cstdint>
#include <array>
#include <string>
#include <string_view>
#include <stdexcept>

namespace core {

    // RFC 790
    enum class Protocol : uint8_t {
        ICMP = 1,
        TCP = 6,
        UDP = 17,
    };

    // 0 1 2
    // Bit 0: reserved, must be zero
    // Bit 1: (DF) 0 = May Fragment, 1 = Don't Fragment
    // Bit 2: (MF) 0 = Last Fragment, 1 = More Fragments
    enum class IP_Flags : uint8_t {
        //Reserved    = 0x4,   // Bit 0
        MayFragment   = 0x0,   // Bit 1
        DontFragment  = 0x2,   // Bit 1
        LastFragment  = 0x0,   // Bit 2
        MoreFragments = 0x1,   // Bit 3
    };

    inline IP_Flags operator|(IP_Flags a, IP_Flags b) {
        return static_cast<IP_Flags>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
    }

    inline IP_Flags operator&(IP_Flags a, IP_Flags b) {
        return static_cast<IP_Flags>(static_cast<uint8_t>(a) & static_cast<uint8_t>(b));
    }

    // Bits 0-2: Precedence
    // Bit    3: 0 = Normal Delay,      1 = Low Delay.
    // Bit    4: 0 = Normal Throughput, 1 = High Throughput.
    // Bit    5: 0 = Normal Relibility, 1 = High Relibility.
    // Bits 6-7: Reserved for Future Use.
    enum class IP_Type_Of_Service : uint8_t {
        Precedence_NetworkControl      = 0xE0, // Bits 0 - 2
        Precedence_InternetworkControl = 0xC0, // Bits 0 - 2
        Precedence_CRITIC_ECP          = 0xA0, // Bits 0 - 2
        Precedence_FlashOverride       = 0x80, // Bits 0 - 2
        Precedence_Flash               = 0x60, // Bits 0 - 2
        Precedence_Immediate           = 0x40, // Bits 0 - 2
        Precedence_Priority            = 0x20, // Bits 0 - 2
        Precedence_Routine             = 0x00, // Bits 0 - 2
        NormalDelay                    = 0x00, // Bit 3
        LowDelay                       = 0x10, // Bit 3
        NormalThroughput               = 0x00, // Bit 4
        HighThroughput                 = 0x08, // Bit 4
        NormalRelibility               = 0x00, // Bit 5
        HighRelibility                 = 0x04, // Bit 5
        // Reserved
    };

    inline IP_Type_Of_Service operator|(IP_Type_Of_Service a, IP_Type_Of_Service b) {
        return static_cast<IP_Type_Of_Service>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
    }

    

    // RFC 791
    // Version: 4 bits
    // IHL: 4 bits
    // Type of Service: 8 bits
    // Total Length: 16 bits
    // Identification: 16 bits
    // Flags: 3 bits
    // Fragment Offset: 13 bits
    // Time to Live: 8 bits
    // Protocol: 8 bits
    // Header Checksum: 16 bits
    // Source Address: 32 bits
    // Destination Address: 32 bits

    
    class IP_Header {
    public:

        IP_Header();

        void set_source_address(std::string_view addr);
        void set_source_address(uint32_t addr);
        void set_destination_address(std::string_view addr);
        void set_destination_address(uint32_t addr);

        void set_protocol(Protocol protocol);
        void set_ttl(uint8_t ttl);
        void set_total_length(uint16_t length);
        void set_identification(uint16_t id);
        void set_flags(IP_Flags flags);
        void set_fragment_offset(uint16_t offset);
        void set_type_of_service(IP_Type_Of_Service tos);

        /*** Getters ***/
        uint8_t version() const;
        uint8_t ihl() const;
        


        

    private:
        uint8_t  _version_and_ihl;
        uint8_t  _type_of_service;
        uint16_t _total_length;
        uint16_t _identification;
        uint16_t _flags_and_fragment_offset;
        uint8_t  _time_to_live;
        uint8_t  _protocol;
        uint16_t _header_checksum;
        uint32_t _source_address;
        uint32_t _destination_address;
    };

} // namespace core

#endif // CORE_IP_HEADER_H_