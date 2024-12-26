#include "constants.h"

int main() {
    std::cout << "Gravity: " << Constants::gravity << '\n';
    std::cout << "Avogadro: " << Constants::avogadro << '\n';
    std::cout << "Funny: " << Constants::funnyNumber << '\n';

    Constants::fella();

    std::cout << Constants::otherGuy() << '\n';
}