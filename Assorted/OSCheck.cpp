#include <iostream>

int main() {
#if defined(__linux__)
    std::cout << "Linux";
#elif defined(_WIN64) || defined(_WIN32)
    std::cout << "Windows ";
#elif defined(__APPLE__)
    std::cout << "Apple";
#elif
    std::cout << "Unknown"
#endif
}
