#include <iostream>

struct Monster {
    enum Type: int {
        ogre,
        dragon,
        orc,
        giant_spider,
        slime
    };

    Type monsterType {ogre};
    std::string name {"noname"};
    int health {0};

    void print() {
        std::cout << "This " << getType() << " is named " << name << " and has " << health << " health.\n";
    }

    constexpr std::string_view getType() {
        switch (monsterType) {
        case ogre:
            return "Ogre";
            break;
        case dragon:
            return "Dragon";
            break;
        case orc:
            return "Orc";
            break;
        case giant_spider:
            return "Giant Spider";
            break;
        case slime:
            return "Slime";
            break;
        default:
            return "bad type";
        }
    }
};

int main() {
    Monster monsterOne {Monster::ogre, "Torg", 145};
    Monster monsterTwo {Monster::slime, "Blurp", 23};

    monsterOne.print();
    monsterTwo.print();
}