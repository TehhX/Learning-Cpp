#include <iostream>

class Person {
private:
    std::string name;
    double money;

public:
    Person(const std::string_view name, const double money)
    : name {name}, money {money} {}

    Person()
    : name {"noname"}, money {0.0} {}

    // Getters
    std::string_view getName() const { return name; }
    double getMoney() const { return money; }

    // Chain-compliant mutators
    Person& giveMoney(const double money) {
        this->money += money;
        return *this;
    }

    Person& takeMoney(const double money) {
        this->money -= money;
        return *this;
    }

    Person& changeName(const std::string_view name) {
        this->name = name;
        return *this;
    }

    // Reset function, uses Person() constructor.
    void reset() {
        *this = {};
    }
};

void print(const Person& person) {
    std::cout << "Name: " << person.getName() << "\nMoney: $" << person.getMoney() << '\n';
}

int main() {
    Person guy {"Timmy", 20'000.0};
    print(guy);

    guy.changeName("Joseph").giveMoney(50'000.0); // Chaining member functions.
    print(guy);

    guy.changeName("Fella"); // Don't need to chain even with "Person&" return type.
    print(guy);

    guy.reset(); // Resets using default constructor.
    print(guy);
}