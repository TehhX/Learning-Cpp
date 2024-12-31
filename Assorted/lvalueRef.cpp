#include <iostream>

void printBoth(int valueOne, int valueTwo) {
    std::cout << "Original: " << valueOne << ", Reference: " << valueTwo << '\n';
}

int main() {
    { // New scope
    int original {5};
    int& reference { original };

    printBoth(original, reference);

    original += 10;  // Will increment both the original and reference

    printBoth(original, reference);

    // Will set reference and original to 30, not reseat the reference itself to target newValue
    int newValue {30};
    reference = newValue;

    printBoth(original, reference);
    }

    { // New scope
    const int original {10};
    const int& reference {original};

    printBoth(original, reference);

    // original = 5; Won't compile, cant change consts.
    }

    { // New scope
    int original {22};
    const int& reference {original};

    printBoth(original, reference);

    // reference = 5; Won't compile, can't change consts.

    original = 10;

    printBoth(original, reference);
    }
}