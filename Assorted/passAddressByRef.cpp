#include <iostream>

void nullifyNoRef(int* ptr) {
    ptr = nullptr;
}

void nullify(int*& ptrRef) {
    ptrRef = nullptr;
}

int main() {
    int x {1};
    int y {2};

    int* ptr {&x};
    std::cout << ptr << '\n';

    nullifyNoRef(ptr); // Points a copy of ptr towards nothing
    std::cout << ptr << '\n';

    nullify(ptr); // Points ptr itself towards nothing
    std::cout << ptr << '\n';
}