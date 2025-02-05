#include <iostream>

struct Fraction {
    int numerator {};
    int denominator {};
};

int main() {
    Fraction fraction {5, 10};

    std::cout << fraction.numerator << '/' << fraction.denominator << std::endl;
}