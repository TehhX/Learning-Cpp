#include <iostream>
#include <array>
#include <vector>

int main() {
    std::array<std::array<int, 4>, 4> array {{ // Array of arrays.
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    }};

    for (const auto& outerArr : array) {
        for (const auto& innerValue : outerArr)
            std::cout << innerValue << " ";

        std::cout << '\n';
    }

    std::vector<std::vector<int>> vector {};

    vector.emplace_back(std::vector<int> { 5, 10, 15, 20, 25, 30 });
    vector.emplace_back(std::vector<int> { 35, 40, 45, 50, 55, 60 });

    for (const auto& outerArr : vector) {
        for (const auto& innerValue : outerArr)
            std::cout << innerValue << ' ';

        std::cout << '\n';
    }
}