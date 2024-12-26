#include <iostream>

int main() {
    std::cout << "Enter 1 to skip, 0 to go: ";

    bool skip {};
    std::cin >> skip;

    if (skip)
        goto skipStatement;

    std::cout << "Not skipped.\n";

skipStatement:
    std::cout << "End.\n";
}