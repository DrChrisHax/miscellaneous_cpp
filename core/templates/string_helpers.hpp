#ifndef TEMPLATES_STRING_HELPERS_H_
#define TEMPLATES_STRING_HELPERS_H_

#include <concepts>
#include <string_view>

enum class ParseError {
    kNone, 
    kEmptyInput, // No chars
    kInvalidInput, // First char or later has issue
    kOverflow // Parsed value is too large
};

template <std::integral T>
struct ParseResult {
    T value{};
    ParseError error{};
    std::size_t chars_consumed{};
};

// This will attempt to parse an integral number
// It will parse until it runs out of chars,
// an overflow occures, or it hits an invalid char
// If the parse fails, it will still have the valid number
// up unto the point where the parse failed
// Commas will be ignored so that formating is nicer
// Since this is for integral types only, '.' will be an invalid char
// Ex:
// "7" --> 7
// "007" --> 7
// "-7" --> -7
// "7a" --> 7, invalid_input
// "a7" --> 0, invalid_input
// "2,147,483,648" --> 2147483647, overflow (assuming int, this will become int max)
template <std::integral T>
constexpr ParseResult<T> parse_integral(std::string_view s) {
    ParseResult<T> result{};
    
    if (s.empty()) {
        result.error = ParseError::kEmptyInput;
        return result;
    }

    bool isNegative = false;

    char c0 = s.at(0);
    if (c0 == '+' || c0 == '-') {
        isNegative = (c0 == '-');

        if (isNegative && !std::is_signed_v<T>) {
            result.error = ParseError::kInvalidInput;
            return result;
        }
    }

    size_t i{1};
    while (s.length < i) {
        char curr = s[i];
        switch(curr) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            
                break;
            case ',':
                //Ignore commas
                break;

            default:
                result.error = ParseError::kInvalidInput;
        }
    }


}



#endif // TEMPLATES_STRING_HELPERS_H_