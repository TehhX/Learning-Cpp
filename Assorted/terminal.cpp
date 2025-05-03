#include <cstdlib>
#include <iostream>

int main() {
    int x = system("echo This works.");
    int y = system("git --version"); // Will only work if Git is installed
    int z = system("bad command here");

    std::cout << x << ", " << y << ", " << z << '\n';
}
