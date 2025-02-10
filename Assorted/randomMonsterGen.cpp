#include <iostream>
#include <assert.h>
#include <random>

class Monster {
public:
    enum Type : int{
        dragon,
        goblin,
        ogre,
        orc,
        skeleton, 
        troll,
        vampire,
        zombie,
        maxmonstertypes
    };

private:
    Type type;
    std::string name;
    std::string roar;
    int hp;

public:
    Monster(const Type type, const std::string name, const std::string roar, const int hp)
    : type {type}, name {name}, roar {roar}, hp {hp} {}

    Monster()
    : Monster {static_cast<Type>(0), "noName", "noRoar", 0} {}

    constexpr std::string_view getType() const {
        switch (type) {
        case dragon: return "dragon";
        case goblin: return "goblin";
        case ogre: return "ogre";
        case orc: return "orc";
        case skeleton: return "skeleton";
        case troll: return "troll";
        case vampire: return "vampire";
        case zombie: return "zombie";
        default: return "noType";
        }
    }

    void print() {
        std::cout << name << " the " << getType();

        if (hp > 0)
            std::cout << " has " << hp << " hit points and says " << roar << ".\n";
        else
            std::cout << " is dead.\n";
    }
};

namespace MonsterGenerator {
    int getRandomInt(const int max) {
        static std::random_device rd {};
        static std::seed_seq seedSequence { rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
        static std::mt19937 generator { seedSequence };
        std::uniform_int_distribution<> rnd {0, max};
        
        return rnd(generator);
    }

    std::string getName(const int i) {
        switch (i) {
        case 0: return "Jerry";
        case 1: return "Howard";
        case 2: return "Samantha";
        case 3: return "Molly";
        case 4: return "Jason";
        default: assert(!"Bad input");
        }
    }

    std::string getRoar(const int i) {
        switch (i) {
        case 0: return "ROAR!!!";
        case 1: return "Argh";
        case 2: return "Yelp";
        case 3: return "Wooo";
        case 4: return "Aieee";
        default: assert(!"Bad input");
        }
    }

    Monster generate() {
        return {
            static_cast<Monster::Type>(getRandomInt(Monster::maxmonstertypes - 1)),
            getName(getRandomInt(4)),
            getRoar(getRandomInt(4)),
            getRandomInt(99) + 1
        };
    }
}

int main() {
    Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
	skeleton.print();

	Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
	vampire.print();

    Monster m{ MonsterGenerator::generate() };
	m.print();
}