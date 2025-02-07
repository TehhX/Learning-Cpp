#include "person.h"

Person::Person(const std::string_view name, const double salary, const int id, const Profession& profession)
: name {name}, salary {salary}, id {id}, profession {profession} {}

Person::Person()
: name {"undefName"}, salary {0.0}, id {0}, profession {static_cast<Profession>(0)} {}

void Person::calculateBonus() {
    salary *= 1.25;
}

void Person::becomeJerry() {
    name = "Jerry";
}

void Person::reset() {
    *this = Person{};
}

std::ostream& operator<<(std::ostream& out, const Profession& profession) {
    switch (profession) {
    case Profession::engineer:   return out << "Engineer";
    case Profession::plumber:    return out << "Plumber";
    case Profession::teacher:    return out << "Teacher";
    case Profession::programmer: return out << "Programmer";
    case Profession::investor:   return out << "Investor";
    case Profession::chef:       return out << "Chef";
    default:                     return out << "Profession error.";
    }
}

void print(const Person& person) {
    std::cout <<   "Name: "       << person.getName() <<
                 "\nSalary: $"    << person.getSalary() <<
                 "\nID: "         << person.getID() <<
                 "\nProfession: " << person.getProfession() << '\n';
}

void talkAboutIt(const Person& person) {
    std::cout << person.getName() << " talks about their job as a " << person.getProfession() << ".\n";
}