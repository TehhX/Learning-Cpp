#include <iostream>

template <typename T>
struct Triad {
    T one {};
    T two {};
    T three {};

    void print() {
        std::cout << '[' << one << ", " << two << ", " << three << ']';
    }
};

// C++17 deduction guide. Means that three of the same type deduces to one of that type.
template <typename T>
Triad(T, T, T) -> Triad<T>;

int main() {
    Triad t1 {1, 2, 3};
    Triad t2 {1.2, 3.4, 5.6};

    t1.print();
    t2.print();

    std::cout << std::endl;
}