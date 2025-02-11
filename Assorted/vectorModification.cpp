#include <iostream>
#include <vector>

template <typename T>
void printVector(const std::vector<T>& vector) {
    for (const T& value: vector)
        std::cout << value << " ";
    std::cout << '\n';

    std::cout << "Length: " << vector.size() << " Capacity: " << vector.capacity() << "\n\n";
}

int main() {
    std::vector<int> vector { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    printVector(vector);

    vector.push_back(110); // Adds a new value
    printVector(vector);

    vector.pop_back(); // Removes the last value
    printVector(vector);

    vector.reserve(50); // Reserves capacity
    printVector(vector);

    vector.resize(75); // Actually changes length, zero initializes empty indices
    printVector(vector);

    vector.resize(11); // Same deal
    printVector(vector);

    vector.emplace_back(15); // More effecient for temporary values, if object exists just use push_back
    printVector(vector);
}