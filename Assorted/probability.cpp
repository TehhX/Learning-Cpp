#include <iostream>
#include <random>

std::mt19937& getGenerator() {
    static std::random_device rd {};
    static std::seed_seq seedSequence {rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    static std::mt19937 generator {seedSequence};

    return generator;
}

int getOfThree() {
    static std::uniform_int_distribution dist {0, 2};
    return dist(getGenerator()); 
}

int getOfTwo() {
    static std::uniform_int_distribution dist {0, 1};
    return dist(getGenerator()); 
}

bool doNotSwap() {
    const int correct {getOfThree()};
    const int chosen {getOfThree()};

    return correct == chosen;
}

bool swap() {
    const int correct {getOfThree()};
    int chosen {getOfThree()};
    int toRemove {};

    while (1) {
        toRemove = getOfTwo();
        if (toRemove != chosen)
            break;
    }

    bool taken[] {0, 0, 0};
    taken[chosen] = true;
    taken[toRemove] = true;

    for (int i = 0; i < 3; i++)
        if (!taken[i])
            return i == correct;
}

int main() {
    int results[] {0, 0};


}