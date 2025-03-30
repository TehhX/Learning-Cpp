#include <iostream>
#include <vector>

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

// Example of complicated function:
const std::vector<int>* getVector(const std::size_t size, const int filler, const std::string_view text) {
    std::cout << text << '\n';
    auto vector = new std::vector<int> {};
    vector->resize(size);
    
    for (auto& item : *vector)
        item = filler;
    
    return vector;
}

void printVector(const std::vector<int>* const vector) {
    for (const auto& item : *vector)
        std::cout << item << '\n';

    delete vector;
}

int main() {
    int (*doubleFunction)(const int) { doubleInt };
    std::cout << doubleFunction(2) << '\n';

    const double (*getPi)() { pi };
    std::cout << getPi() << '\n';

    void (*thing)() {};

    thing = thingOne;
    thing();

    thing = thingTwo;
    thing();

    checkCondition(15, isPositive);
    checkCondition(-16, isPositive);

    checkCondition(24, isEven);
    checkCondition(13, isEven);

    // Auto saves writing out the complex syntax manually:
    auto getVectorPointer { getVector };
    printVector( getVectorPointer(3, 15, "Wow") );

    // Compared to this mess:
    const std::vector<int>* (*pointerName)(size_t size, int filler, std::string_view text) { getVector };
    printVector( pointerName(5, 24, "Output") );
}
