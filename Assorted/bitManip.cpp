#include <iostream>
#include <string>

#define arrayItem const auto&

using u_long = unsigned long;
using u_char = unsigned char;

int main() {
    u_long hexIn { 0xAA'BB'CC'DD };

	// This puts each byte from hexIn into its own byte.
    u_char bytes[4] {
        static_cast<u_char>(hexIn & 0xFF),
        static_cast<u_char>((hexIn & 0xFF'00) >> 8),
        static_cast<u_char>((hexIn & 0xFF'00'00) >> 16),
        static_cast<u_char>((hexIn & 0xFF'00'00'00) >> 24)
    };

    for (arrayItem byte : bytes)
        std::cout << std::hex << int(byte) << ' ';
    
    std::cout << std::endl;
}