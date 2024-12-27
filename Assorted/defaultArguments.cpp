#include <iostream>

/* Forward declarations, if used, should be the only thing to contain
 * the default arguments. See that the definitions don't include
 * the defaults, but work just the same. These forward declarations
 * would also work in a header file.
 */

void printGiven(int x = 5);
void printMultiple(int x = 22, int y = 53, int z = 64);

void printGiven(int x) {
    std::cout << ' ' << x << '\n';
}

void printMultiple(int x, int y, int z) {
    std::cout << ' ' << x << ' ';
    std::cout << y << ' ';
    std::cout << z << ' ';
    std::cout << std::endl;
}

int main() {
    std::cout << "Print Given:\n";
    printGiven(); // No value passed, will use default argument.
    printGiven(10); // Value passed, will use the passed value.

    std::cout << "Print Multiple:\n";
    printMultiple();
    printMultiple(1);
    printMultiple(1, 2);
    printMultiple(1, 2, 3);
}