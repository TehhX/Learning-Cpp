#include <iostream>
#include <optional>

std::optional<float> divideBy(const int x, const int y) {
    if (y == 0)
        return std::nullopt;

    return x / y;
}

void print(const std::optional<float>& optional) {
    if (optional)
        std::cout << optional.value() << '\n';
    else
        std::cout << "Bad value.\n";
}

void print(const float& optional) {
    std::cout << optional << '\n';
}

int main() {
    const std::optional<float> alpha {divideBy(10, 5)};
    const std::optional<float> beta {divideBy(10, 0)};

    print(alpha);
    print(beta);

    const float alphaReal {alpha ? alpha.value() : -1.0f};
    const float betaReal {beta ? beta.value() : -1.0f};

    print(alphaReal);
    print(betaReal);
}