#include "person.h"

int main() {
    Person jerry {"Jerry", 12'000.00, 234, Profession::chef};
    print(jerry);

    talkAboutIt(jerry);

    jerry.calculateBonus();
    print(jerry);

    jerry.reset();
    print(jerry);
}