#include <iostream>

#define ENABLE_DEBUG

int main() {
    // Will print when definition is there.
    #ifdef ENABLE_DEBUG
    std::cerr << "Debug on.\n";
    #endif

    // Will print when definition is not there, or when commented out.
    #ifndef ENABLE_DEBUG
    std::cout << "Debug off.\n";
    #endif

    // Will always print.
    std::cout << "Always prints.\n";
}