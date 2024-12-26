#include <iostream>

int localVar() {
    int local {0};
    return ++local;
}

int staticLocalVar() {
    static int staticLocal {0};
    return ++staticLocal;
}

void printInt(int value) {
    std::cout << "Value: " << value << '\n';
}

int main() {
    std::cout << "LocalVar: \n"; // Non-static, will always be 1.
    printInt(localVar());
    printInt(localVar());
    printInt(localVar());

    std::cout << "\nStaticLocalVar: \n"; // Static, will increment over calls.
    printInt(staticLocalVar());
    printInt(staticLocalVar());
    printInt(staticLocalVar());
}