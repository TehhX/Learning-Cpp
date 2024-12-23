#include <iostream>

int main() {
    std::cout << "Enter the height of the tower in meters: ";

    float startingHeight {};
    std::cin >> startingHeight;

    int index {};
    float currentHeight {};

    while (1) {
        currentHeight = startingHeight - 9.81f * index * index / 2;
        if (currentHeight <= 0) break;
        std::cout << "At " << index << " seconds, the ball is at height: " << currentHeight << " meters.\n";
        index++;
    }

    std::cout << "At " << index << " seconds, the ball is on the ground.\n";
}