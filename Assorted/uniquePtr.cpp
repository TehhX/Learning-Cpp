#include <iostream>
#include <memory>

struct Fraction {
    int numerator;
    int denominator;
};

int main() {
    Fraction normalFrac { 1, 2 };
    std::unique_ptr<Fraction> uniqueFrac { new Fraction { 3, 4 } };
    auto betterUniqueFrac { std::make_unique<Fraction>( 5, 6 ) };
}