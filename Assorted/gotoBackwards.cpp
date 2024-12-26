#include <iostream>

int takeInteger(std::string_view text) {
    std::cout << text;
    int value {};
    std::cin >> value;
    return value;
}

int main() {
    int value {};

getValue: // goto statements should be unindented.
    value = takeInteger("Enter a negative integer: ");
    if (value >= 0)
        goto getValue;
    std::cout << "Your value was " << value << ".\n";
}