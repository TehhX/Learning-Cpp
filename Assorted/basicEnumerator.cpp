#include <iostream>

enum Color {
    red,
    green,
    blue
};

int main() {
    std::cout << Color {red} << '\n';       // Prints 0
    std::cout << Color {green} << '\n';     // Prints 1
    std::cout << Color {blue} << std::endl; // Prints 2
}