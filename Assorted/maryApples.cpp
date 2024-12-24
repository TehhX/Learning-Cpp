#include <iostream>
#include <string_view>

std::string_view getQuantityPhrase(int count) {
    switch (count) {
        case 0: return "no";
        case 1: return "a single";
        case 2: return "a couple of";
        case 3: return "a few";
    }

    if (count < 0) return "negative";
    if (count > 6) return "too many";
    return "many";
}

std::string_view getApplesPluralized(int count) {
    return count == 1 ? "apple" : "apples";
}

int main()
{
    constexpr int maryApples { 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}