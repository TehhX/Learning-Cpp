#include <iostream>
#include <cstdint>

// TODO: Incomplete file

enum Colors: int {
    red,
    greed,
    blue,
    orange,
    brown
};

void printValue(const Colors color) {
    using namespace std;

    switch(color) {
    case red:
    case greed:
    case blue:
    case orange:
    case brown:
    }
}

int main() {
    std::cout << "Enter a value: ";

    int value {};
    std::cin >> value;

    std::cout << value << std::endl;
}