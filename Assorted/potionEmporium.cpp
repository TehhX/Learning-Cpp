#include <iostream>
#include <array>
#include <vector>

class Potion {
public:
    enum Type {
        healing,
        mana,
        speed,
        invisibility
    };

    friend std::ostream& operator<<(std::ostream& out, const Potion::Type& type) {
        switch (type) {
        case Potion::healing:      return out << "healing";
        case Potion::mana:         return out << "mana";
        case Potion::speed:        return out << "speed";
        case Potion::invisibility: return out << "invisibility";
        default:                   return out;
        }
    }

private:
    Type type;
    int cost;

public:
    Potion(const Type type, const int cost)
    : type {type}, cost {cost} {}

    Type getType() const { return type; }
    int getCost() const { return cost; }
};

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

Character character {"Alex", 90};

void printShop() {
    std::cout << "Here is our selection for today:\n";

    int i {0};
    for (const auto& potion : potions)
        std::cout << ++i << ") " << potion.getType() << " costs " << potion.getCost() << ".\n";
}

bool takeInput() {
    std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
    char input {};

    printShop();

    while (true) {
        std::cin >> input;

        if (input == 'q')
            return false;
        
        Potion::Type type { static_cast<Potion::Type>(input - '1') };

        if (type >= 0 && type < 4) {
            if (potions[type].getCost() < character.gold) {
                character.gold -= potions[type].getCost();
                character.potions[type]++;
                return true;
            }

            else {
                std::cout << "You cannot afford that.\n\n";
                return true;
            }
        }

        else
            std::cout << "That is an invalid input. Try again: ";
    }
}

void printPotionCount(const Potion& potion) {
    if (!character.potions[potion.getType()])
        return;

    std::cout << character.potions[potion.getType()] << "x potions of " << potion.getType() << '\n';
}

int main() {
    std::cout << "Welcome to roscoe's potion emporium!\n";

    while (takeInput());

    std::cout << "Your inventory contains:\n";

    for (const auto& potion : potions)
        printPotionCount(potion);

    std::cout << "\nYou escaped with " << character.gold << " gold remaining.\n\n" <<
                   "Thank you for shopping at Roscoe's potion emporium!\n";
}