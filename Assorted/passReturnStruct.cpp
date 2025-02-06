#include <iostream>

struct Guy {
    std::string_view name {"undef"};
    int age {0};
};

void printGuy(const Guy& guy) {
    std::cout << "Name: " << guy.name << "\nAge: " << guy.age << '\n';
}

constexpr Guy defaultGuy() {
    return {"Charles", 12};
}

int main() {
    constexpr Guy timmy {"Timmy", 15};
    constexpr Guy jason {"Jason", 43};

    printGuy(timmy);
    printGuy(jason);
    printGuy(Guy {"Walter", 67});
    printGuy(defaultGuy());
}