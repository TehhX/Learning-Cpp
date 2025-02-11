#include <iostream>
#include <vector>
#include <functional>

void printArray(const std::vector<std::reference_wrapper<int>> array) {
    for (const int& value : array)
        std::cout << value << ' ';
    std::cout << '\n';
}

int main() {
    int x { 1 };
    int y { 2 };
    int z { 3 };

    int& a { x };

    std::vector<std::reference_wrapper<int>> array { x, y, z };
    printArray(array);

    array[1].get() = 50; // Must use "get()" to change the reference. Using = without get will reseat the reference.
    printArray(array);    

    array[1].get() = 2; // Undo previous
    printArray(array);

    array[0] = array[1] = array[2] = a; // Set them all to int& a
    printArray(array);
    
    x = 50; // Set x, and consequently reference a to 50
    printArray(array);

    int b { 25 }; // Make a new integer, set a to reference it
    a = b;
    printArray(array);
}