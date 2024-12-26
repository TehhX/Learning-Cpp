#include <iostream>

constexpr double gravity {9.81};

int main() {
    // The constexpr if statements (and if else statements) will be checked at compule time, instead of at runtime.

    if constexpr (gravity == 0)
        std::cout << "Zero gravity.\n";
    else if constexpr (gravity == 9.81)
        std::cout << "Regular gravity.\n";
    else
        std::cout << "Anomalous gravity.\n";

    // The preceding code is, with gravity equal to 9.81, equvilant to the following code.

    //std::cout << "Regular gravity.\n";
}