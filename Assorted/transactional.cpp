#include <iostream>

struct Set {
    int x;
    int y;
    int z;
};

int main() {
    int x, y, z;
    Set set {};

    if (std::cin >> x >> y >> z) // Will equate to false if error occurs.
        set = { x, y, z };
    else {
        std::cout << "Error.\n";
        return -1;
    }

    std::cout << set.x << set.y << set.z << std::endl;
}