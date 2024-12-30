#include <iostream>
#include <iomanip>

constexpr float calculateTax(float cost) {
    constexpr float taxRate {1.13};
    return cost * taxRate;
}

int main() {
    constexpr float tax { calculateTax(15.00) };
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "Total Cost: $" << tax << '\n';
}