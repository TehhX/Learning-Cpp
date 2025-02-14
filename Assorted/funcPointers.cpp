#include <iostream>

int doubleInt(const int in) {
    return in * 2;
}

const double pi() {
    return 3.14159;
}

void thingOne() {
    std::cout << "Thing One!\n";
}

void thingTwo() {
    std::cout << "Thing Two!\n";
}

bool isPositive(const int x) {
    return x >= 0;
}

bool isEven(const int x) {
    return x % 2 == 0;
}

void checkCondition(const int value, bool (*condition)(const int)) {
    if (condition(value))
        std::cout << "Checks out.\n";
    else
        std::cout << "Fails.\n";
}

int main() {
    int (*doubleFunction)(const int) { &doubleInt };
    std::cout << doubleFunction(2) << '\n';

    const double (*getPi)() { &pi };
    std::cout << getPi() << '\n';

    void (*thing)() {};

    thing = &thingOne;
    thing();

    thing = &thingTwo;
    thing();

    checkCondition(15, isPositive);
    checkCondition(-16, isPositive);

    checkCondition(24, isEven);
    checkCondition(13, isEven);
}