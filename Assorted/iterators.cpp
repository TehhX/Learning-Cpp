#include <iostream>
#include <vector>
#include <array>

template <typename T>
void print(T arr) { // General format for iterator loops
    for (auto i { std::begin(arr) }; i != std::end(arr); i++)
        std::cout << *i << ' ';

    std::cout << '\n';
}

int main() {
    std::vector vector { 1.5, 3.0, 4.5, 6.0, 7.5, 9.0};
    std::array array { 2, 4, 6, 8, 10, 12 };

    print(vector);
    print(array);
}