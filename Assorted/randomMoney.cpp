#include <iostream>
#include <random>

constexpr int repeatTimes {10'000'000};

float randomMoney() {
    static std::random_device rd {};
    static std::seed_seq seedSeq {rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    static std::mt19937 gen {seedSeq};
    static std::uniform_int_distribution dist {1, 10'000};

    return dist(gen) / 100.0f;
}

float calculateSalary() {
    float sum {0};

    for (int i {0}; i < 365; i++)
        sum += randomMoney();

    return sum;
}

float calculateAverage() {
    float sum {0};

    for (int i {0}; i < repeatTimes; i++) {
        sum += calculateSalary();
        std::cout << "Progress: " << float(i) / repeatTimes  * 100 << '%' << "\t\tAverage: " << sum / i << '\n';
    }

    return sum / repeatTimes;
}

int main() {
    std::cout << "Average over " << repeatTimes << " repeats: $" << calculateAverage() << '\n';
}