#include <cstdint>
#include <iostream>

int main() {
    std::cout << "Main began.\n";

    std::int8_t x {10};
    std::cout << "Num is: " << x << ", okay?\n";
    std::cout << "It is gamig: " << sizeof(x) << " and " << sizeof((int) x) << '\n';

    float testFloat {10000000000000000000000000000000000000.0f};
    std::cout << "Test Float: " << testFloat << '\n'; // Prints with scientific notation
}