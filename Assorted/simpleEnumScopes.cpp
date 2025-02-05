#include <iostream>

namespace Colors {
    enum {
        red,
        green,
        blue,
        cyan,
        magenta,
        yellow
    };
}

namespace Hues {
    enum {
        yellow,
        green,
        cyan,
        red,
        magenta,
        blue
    };
}

int main() {
    std::cout << static_cast<int>(Colors::blue) << std::endl;
    std::cout << static_cast<int>(Hues::blue) << std::endl;
}