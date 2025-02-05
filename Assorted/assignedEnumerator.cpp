#include <iostream>

namespace Numbers {
    enum Numbers {
        one = 1,
        ten = 10,
        hundred = 100,
        thousand = 1'000,
        after,              // Will continue number sequence from last enumeration, in this case 1001.
        tenTimesTen = 100   // Same value as hundred, they are essentially the same thing.
    };
}

int main() {
    std::cout << Numbers::Numbers {Numbers::one} << '\n';
    std::cout << Numbers::Numbers {Numbers::ten} << '\n';
    std::cout << Numbers::Numbers {Numbers::hundred} << '\n';
    std::cout << Numbers::Numbers {Numbers::thousand} << '\n';
    std::cout << Numbers::Numbers {Numbers::after} << '\n';
    std::cout << Numbers::Numbers {Numbers::tenTimesTen} << '\n';
}