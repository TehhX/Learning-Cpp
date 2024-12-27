#include <iostream>
#include <random>

int main() {
    constexpr int count { 1000 };

    std::random_device rd {};
    std::seed_seq seedSequence { rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 generator { seedSequence };

    // Uniform distributors can be initialized and reused:
        // std::uniform_int_distribution<> die6 {1, 6};
        // std::uniform_int_distribution<> die12 {1, 12};
        // std::uniform_int_distribution<> die20 {1, 20};
        std::uniform_int_distribution<> die40 {1, 500};

    for (int i = 0; i < count; i++) {
        // std::cout << "6-Sided: " << die6(generator) << '\t';
        // std::cout << "12-Sided: " << die12(generator) << '\t';
        // std::cout << "20-Sided: " << die20(generator) << '\t';
        std::cout << die40(generator) << "\n";
    }
}