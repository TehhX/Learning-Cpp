#include <iostream>

int integerInput(std::string_view text) {
    std::cout << text;

    int value {};
    std::cin >> value;

    return value;
}

int main() {
    int smaller { integerInput("Enter an integer: ") };
    int larger { integerInput("Enter a larger integer: ") };

    if (smaller > larger) {
        std::cout << "Swapping the values\n";
        int temp { larger };
        larger = smaller;
        smaller = temp;
    }

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value us " << larger << '\n';
}