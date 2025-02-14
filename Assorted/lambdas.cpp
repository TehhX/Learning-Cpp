#include <iostream>

void check(const int value, bool (*condition)(const int)) {
    if (condition(value))
        std::cout << "True.\n";
    else
        std::cout << "False.\n";
}

int main() {
    auto isEven = [](const int x) { return (x % 2) == 0; };
    auto isPositive = [](const int x) { return x >= 0; };

    check(4, isEven);
    check(7, isEven);

    check(-10, isPositive);
    check(15, isPositive);

    check(25, [](const int x) -> bool { return x == 0; });
    check(13, [](const int x) -> bool { return x == 13; });
}