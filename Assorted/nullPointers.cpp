#include <iostream>

void whatAddress(int* pointerParam) {
    std::cout << pointerParam << '\n';
}

void whatValue(int* pointerParam) {
    if (pointerParam != nullptr)
        std::cout << *pointerParam << '\n';
    else                                      // If this if/else wasn't implemented, it would lead to segfaults when pointerParam == nullptr.
        std::cout << "Null Pointer.\n";
}

int main() {
    int* nullPointer {nullptr};
    // std::cout << *nullPointer << '\n'; // Will cause a segfault
    std::cout << nullPointer << '\n';     // Will print null address (0)

    int x {15};                           // Initialize an integer of value 15
    int* pointer {&x};                    // Initialize an integer pointer to x
    
    whatAddress(pointer);                 // Prints address of x
    whatAddress(nullPointer);             // Prints null address (0)
    
    whatValue(pointer);                   // Prints value of x
    whatValue(nullPointer);               // Prints "Null Pointer." (Look at func for why)
        
    pointer = nullPointer;                // VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
    pointer = nullptr;                    // These do the same thing, point "pointer" to null

    whatAddress(pointer);                 // VVVVVVVVVVVVVVVVVVVVVVV
    whatAddress(nullPointer);             // Prints null address (0)
    
    whatValue(pointer);                   // VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
    whatValue(nullPointer);               // Prints "Null Pointer." (Look at func for why)
}