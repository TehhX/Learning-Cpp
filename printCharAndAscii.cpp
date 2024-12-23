#include <iostream>

int main() {
    std::cout << "Input character: ";

    char character {};
    std::cin >> character;

    std::cout << "You entered '" << character << "', which has an ascii code of " << static_cast<int>(character) << '\n';
}