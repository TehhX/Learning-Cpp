#include <iostream>
#include <cstdint>

enum Color : std::uint8_t { // 8 bit means size of 1 byte, shown in cout.
    red,
    green,
    blue
};

int main() {
    Color color {red};

    std::cout << "Color size: " << sizeof(color) << std::endl;
}