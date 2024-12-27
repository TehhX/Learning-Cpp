#include "templates.h"

int main() {
    // The max func from the header file in namespace Templates
    std::cout << max(1, 5) << '\n';        // Integers
    std::cout << max(1.0f, 5.0f) << '\n';  // Floats
    std::cout << max(1.0, 5.0) << '\n';    // Doubles
    std::cout << max('a', 'b') << '\n';    // Characters
    std::cout << max(10) << '\n';          // One default    
    std::cout << max<int>() << '\n';       // Two defaults (Requires specified type)

    // A type can also be specified with the diamond operators
    std::cout << max<int>(1, 5) << '\n';   // Integers

    // This will show a compiling error, because std::strings are disallowed by the delete keyword.
    // std::cout << max("maximize", "this") << '\n';
}