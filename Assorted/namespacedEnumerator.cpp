#include <iostream>

namespace Color {
    enum Color {
        red,
        green,
        blue
    };
}

int main() {
    std::cout << Color::Color {Color::red} << '\n';
    std::cout << Color::Color {Color::green} << '\n';
    std::cout << Color::Color {Color::blue} << '\n';
}