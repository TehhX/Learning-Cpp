#include <iostream>
#include "readWriteIO.hpp"

int readNumber() {
    std::cout << "Write a number: ";

    int num {};
    std::cin >> num;

    return num;
}

void writeAnswer(int value) {
    std::cout << "Your value is: " << value << '\n';
}