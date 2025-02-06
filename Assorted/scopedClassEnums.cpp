#include <iostream>

enum class Pet: int {
    dog,
    cat,
    ferret
};

enum class Animal: int {
    cow,
    dog,
    wolf
};

int main() {
    Pet pet {Pet::dog};
    Animal animal {Animal::dog};

    // if (pet == animal)          Won't compile, classes are not comparable
    //     std::cout << "Same\n";

    // int value {Pet::dog};  Even though underlying type is int, it won't implicitly convert.
}