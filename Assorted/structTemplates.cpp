#include <iostream>

template <typename T>
struct Pair {
    T first {};
    T second {};

    T getMax() {
        return (first > second ? first : second);
    }
};

int main() {
    Pair<int> x {5, 19};
    std::cout << "X Max: " << x.getMax() << '\n';

    Pair<float> y {2.6f, 2.9f};
    std::cout << "Y Max: " << y.getMax() << '\n';

    Pair<char> z {'A', 'B'};
    std::cout << "Z Max: " << z.getMax() << std::endl;
}