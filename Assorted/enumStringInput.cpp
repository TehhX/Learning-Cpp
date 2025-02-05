#include <iostream>
#include <cstdint>

// TODO: Incomplete file

enum Colors: int {
    red,
    green,
    blue,
    orange,
    brown
};

void printValue(const Colors& color) {
    using namespace std;

    switch(color) {
    case red:
        cout << "Red";
        break;
    case green:
        cout << "Green";
        break;
    case blue:
        cout << "Blue";
        break;
    case orange:
        cout << "Orange";
        break;
    case brown:
        cout << "Brown";
        break;
    default:
        cout << "???";
    }

    cout << endl;
}

int main() {
    std::cout << "Enter a value: ";

    int value {};
    std::cin >> value;

    printValue(static_cast<Colors>(value));
}