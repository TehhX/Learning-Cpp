int main() {
    const int constInt {5};
    int* intPointer {};

    //intPointer = &constInt;                           // Not possible, non const pointer to const integer
    int integer {10};
    intPointer = &integer;                              // Fine, both are non constant

    *intPointer = 21;                                   // Can modify value, both non const

    const int* constIntPointer {&constInt};             // Fine, pointer to const int can point to const int
    constIntPointer = &integer;                         // Fine, pointer to const int can point to non const integer

    //*constIntPointer = 56;                            // Not possible, pointer to const cannot modify what it points at
    *intPointer = 89;                                   // Fine, pointer to const int can modify what it points at

    int x {5};
    int y {10};
    int* const intConstPointer {&x};                    // The pointer ITSELF is const in this case, instead of the pointer's type.
    //intConstPointer = &y;                             // This means that the address of the pointer cannot be changed.
    *intConstPointer = 10;                              // However, the dereferenced value at the address CAN be changed.

    const int* const constIntConstPointer {&constInt};  // A const pointer pointing at a const int.
}