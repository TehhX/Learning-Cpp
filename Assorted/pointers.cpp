#include <iostream>

int main() {
    int x {5};
    int* ptrX {&x};

    std::cout << "X-Int: " << x << "\nX-Int-Pointer: " << ptrX << "\nX-Int-Pointer-Dereferenced: " << *ptrX << '\n';

/*
    Type mismatched between variable and variable pointer, not allowed:
    int y {5};
    double* ptrY {&y};
*/

   int y {21};
   int* ptr {&y};                                       // New integer pointer pointed at var y
            
   std::cout << "\nY: " << *ptr << '\n';            
            
   int z {45};            
   ptr = &z;                                            // Repointing ptrY towards var z
            
   std::cout << "Z: " << *ptr << '\n';            
        
   int a {62};            
   *ptr = a;                                            // Changing value of whatever ptr is pointing to, in this case z, to 62

   std::cout << "A: " << *ptr << ", Z: " << z << '\n';  // A and Z are the same
}