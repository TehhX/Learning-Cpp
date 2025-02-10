#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores { 12, 43, 96, 83, 28};
    std::cout << "First score: " << scores[0] << '\n';
    std::cout << "Last score: " << scores[4] << '\n';

    std::vector<float> temps (365);

    std::vector<int> values (3);
    std::cin >> values[0] >> values[1] >> values[2];
    std::cout << "Sum: " << (values[0] + values[1] + values[2]) << '\n';
    std::cout << "Sum: " << (values[0] * values[1] * values[2]) << '\n';
}