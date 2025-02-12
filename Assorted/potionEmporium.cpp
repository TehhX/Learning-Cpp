#include <iostream>
#include <array>
#include <vector>

// TODO: Unfinished.

class Potion {
public:
    enum Type {
        healing,
        mana,
        speed,
        invisibility
    };

private:
    Type type;
    int cost;

public:
    Potion(const Type type, const int cost)
    : type {type}, cost {cost} {}

    Type getType() const { return type; }
    int getCost() const { return cost; }
};

std::ostream& operator<<(std::ostream& out, const Potion::Type& type) {
    switch (type) {
    case Potion::healing:      return out << "healing";
    case Potion::mana:         return out << "mana";
    case Potion::speed:        return out << "speed";
    case Potion::invisibility: return out << "invisibility";
    default:                   return out;
    }
}

const std::array<Potion, 4> potions {{
    {Potion::healing, 20},
    {Potion::mana, 30},
    {Potion::speed, 12},
    {Potion::invisibility, 50}
}};

struct Character {
    std::string name;
    int gold;
    std::array<int, 4> potions;
};

void printShop() {
    std::cout << "Here is our selection for today:\n";

    int i {0};
    for (const auto& potion : potions)
        std::cout << ++i << ") " << potion.getType() << " costs " << potion.getCost() << ".\n";
}

Character character {"Alex", 90};

bool takeInput() {
    std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
    char input {};

    printShop();

    while (true) {
        std::cin >> input;

        if (input == 'q')
            return false;
        
        Potion::Type type { static_cast<Potion::Type>(input - '0') };

        if (type > 0 && type <= 4) {
            character.potions[type - 1]++;
            
            return true;
        }

        else
            std::cout << "That is an invalid input. Try again: ";
    }
}

int getPotionCount(const Potion::Type& type) {
    return character.potions[type];
}

int main() {
    std::cout << "Welcome to roscoe's potion emporium!\n";
    Character character {"Alex", 90};

    while (takeInput());

    std::cout << "Your inventory contains:\n" <<
                 getPotionCount(Potion::healing) << "x potion of speed\n" <<
                 getPotionCount(Potion::mana) << "x potion of mana\n" <<
                 getPotionCount(Potion::speed) << "x potion of speed\n" <<
                 getPotionCount(Potion::invisibility) << "x potion of invisibility\n" <<
                 "You escaped with " << character.gold << " gold remaining.\n\n" <<
                 
                 "Thank you for shopping at Roscoe's potion emporium!\n";
}