#include <iostream>
#include <optional>

// TODO: Incomplete file

enum Colors: int {
    red,
    green,
    blue,
    orange,
    brown
};

constexpr std::string_view getString(const Colors color) {
    switch (color) {
    case red:
        return "Red";
    case green:
        return "Green";
    case blue:
        return "Blue";
    case orange:
        return "Orange";
    case brown:
        return "Brown";
    default:
        return NULL;
    }
}

constexpr std::optional<Colors> getColor(const std::string_view string) {
    if (string == "red")
        return red;
    if (string == "green")
        return green;
    if (string == "blue")
        return blue;
    if (string == "orange")
        return orange;
    if (string == "brown")
        return brown;

    return std::nullopt;
}

int main() {
    std::cout << "Enter a color: ";

    std::string value {};
    std::getline(std::cin >> std::ws, value);

    std::optional<Colors> color {getColor(value)};

    if (!color)
        std::cout << "Incorrect value.\n";
    else
        std::cout << getString(color.value()) << std::endl;
}