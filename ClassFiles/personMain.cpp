#include "person.hpp"

#include <iostream>

int main() {
    Person jerry {"Jerry", 12'000.00, 234, Person::Profession::chef};
    jerry.print();

    jerry.talkAboutIt();

    jerry.giveRaise();
    jerry.print();

    jerry.reset();
    jerry.print();

    jerry.setName("Small Fella").setSalary(125'000.00);
    std::string guyName { jerry.getName() };
    double guySalary { jerry.getSalary() };

    jerry.setName("Big Fella");
    jerry.setSalary(250'000.00);

    std::cout << "Object name: " << jerry.getName() << "\nObject salary: $" << jerry.getSalary() << '\n';
    std::cout << "Variable name: " << guyName << "\nVariable salary: $" << guySalary << '\n';
}