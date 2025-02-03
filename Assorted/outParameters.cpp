#include <iostream>

int& max(int& a, int& b) {
    return (a > b ? a : b);
}

int main() {
    int x {5};
    int y {10};

    max(x, y) = 15;

    std::cout << "X: " << x << ", Y:" << y << std::endl;
}