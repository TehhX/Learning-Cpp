#include <iostream>

int main() {
    int x { 5 };
    int y { 6 };

    int* ptr1 { &x };
    int* ptr2 { &y };

    std::cout << *ptr1 << " is first, " << *ptr2 << " is second.\n";

    std::cout << ptr1 << " is 4 bytes lower in address than " << ptr2 << '\n';

    ptr1++; // Move one size of pointer type higher (in this case, int, therefore 4 bytes)
    ptr2--; // Same thing, but inversed

    std::cout << *ptr1 << " has swapped with " << *ptr2 << '\n';

    const int arr[] { 5, 10, 15, 20 };
    const int* ptr { arr };

    std::cout << "First: " << ptr[0] << ", Second: " << ptr[1] << ".\n";
}