#include <iostream>

// Two overloaded max funcs:
template <typename T>
T max(T x = 0, T y = 1) {
    return x > y ? x : y;
}

template <typename T, typename U>
auto max(T x, U y) {
    return x > y ? x : y;
}

// Use of max func with character array made illegal:
template <>
const char* max(const char*, const char*) = delete;

// Multiple types:
template <typename T, typename U>
void print(T x, U y) {
    std::cout << "X: " << x << ", Y: " << y << '\n';
}

// Auto will return the correct type given input types:
template <typename T, typename U>
auto maxMultiAuto(T x, U y) {
    return x > y ? x : y;
}

// This will return the type of T, given by the call:
template <typename T, typename U>
T maxMulti(T x, U y) {
    return x > y ? x : y;
}

int main() {
    // Calling a template with a single type:
    std::cout << max(1, 5) << '\n';        // Integers
    std::cout << max(1.0, 5.0) << '\n';    // Doubles
    std::cout << max('a', 'b') << '\n';    // Characters

    // Using defaults:
    std::cout << max(10) << '\n';          // One default    
    std::cout << max<int>() << '\n';       // Two defaults (Requires specified type)

    // A type can also be specified with the diamond operators
    std::cout << max<int>(1, 5) << '\n';   // Integers

    // This will show a compiling error, because char arrays are disallowed by the delete keyword.
    // std::cout << max("maximize", "this") << '\n';

    print("\"X is a string\"", 1234.0f);          // This template can accept multiple types in one.

    std::cout << maxMultiAuto(5, 5.8) << '\n';    // This template returns the revevant type
    std::cout << maxMulti(5, 5.8) << '\n';        // This is a semantic error, even though the only difference is the auto returm
}