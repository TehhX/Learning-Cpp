#include <iostream>

void printWhen(int i) {
    bool none { true };

    if (i % 3 == 0) {
        std::cout << "fizz";
        none = false;
    } if (i % 5 == 0) {
        std::cout << "buzz";
        none = false;
    } if (i % 7 == 0) {
        std::cout << "pop";
        none = false;
    }

    if (none)
        std::cout << i;
    
    std::cout << '\n';
}

int main() {
    constexpr int max { 150 };

    for (int i = 1; i <= max; i++) 
        printWhen(i);
}