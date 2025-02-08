#include <iostream>

class Guy {
private:
    // Static constant
    static constexpr int funnyNumber {69};

    static int count;

public:
    Guy() {
        count++;
    }

    const int& getCount() const { return count; }

    // Static function
    static constexpr int getFunnyNumber() { return funnyNumber; }
};

// No static before type
int Guy::count {0};

void print(const int& num) {
    std::cout << num << '\n';
}

int main() {
    Guy fella {};
    print(fella.getCount());

    for (int i {0}; i < 10; i++)
        Guy {};

    print(fella.getCount());

    // Calling static function
    print(Guy::getFunnyNumber());
}