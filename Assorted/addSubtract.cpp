#include <iostream>

int main() {
    int valueOne {};
    int valueTwo {};

    std::cout << "Enter two integers: ";

    std::cin >> valueOne >> valueTwo;

    std::cout << valueOne << " + " << valueTwo << " is " << valueOne + valueTwo << ".\n";
    std::cout << valueOne << " - " << valueTwo << " is " << valueOne - valueTwo << ".\n";

    return 0;
}