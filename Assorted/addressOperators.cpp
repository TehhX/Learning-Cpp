#include <iostream>

int main() {
    int x {10};

    std::cout << "Memory Address: " << &x << '\n';      // "address of" operator on a variable
    std::cout << "Address Value: " << *(&x) << '\n';    // Dereference on the "address of" operator
}