#include <iostream>

int add(int, int);

int main() {
    std::cout << add(1, 5);
}

int add(int a, int b) {
    return a + b;
}