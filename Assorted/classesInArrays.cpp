#include <iostream>
#include <array>

struct Item {
    std::string_view name;
    int gold;
};

constexpr void printStore(const std::array<Item, 4>& array) {
    for (const auto& item : array)
        std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
}

int main() {
    constexpr std::array<Item, 4> items {{ // Double braces allow type inferring.
        { "sword", 5 },
        { "dagger", 3 },
        { "club", 2 },
        { "spear", 7 }
    }};

    printStore(items);
}