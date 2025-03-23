#include <iostream>

class Count {
private:
    unsigned int count;

public:
    Count(unsigned int count)
    : count { count } {}

    operator int() const { return count; };
};

int main() {
    const Count cnt { 5 };

    std::cout << static_cast<int>(cnt) << std::endl;
}