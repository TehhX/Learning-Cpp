#include <iostream>

template <typename T, typename Y, typename U>
class Triad {
private:
    T first;
    Y second;
    U third;

public:
    Triad(const T& first, const Y& second, const U& third)
    : first {first}, second {second}, third {third} {}

    const T& getFirst() const { return first; }
    const Y& getSecond() const { return second; }
    const U& getThird() const { return third; }

    void print() const;
};

template <typename T, typename Y, typename U>
void Triad<T, Y, U>::print() const {
    std::cout << '[' << first << ", " << second << ", " << third << "]\n";
}

int main() {
    Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << t1.getFirst() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';
}