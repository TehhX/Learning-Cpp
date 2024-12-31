#include <iostream>

void passByAddress(const int* ptr) {  // Const so we don't accidentally modify the original value
    //*ptr = 10;                      // Can't modify original value because parameter is const. 
    std::cout << *ptr << '\n';
}

int main() {
    int x {5};

    passByAddress(&x);
}