#include "person.hpp"

#include <iostream>

// Private -----------------------------------------------------------
void Person::becomeJerry() {
    name = "Jerry";
}

// Public ------------------------------------------------------------
Person::Person(const std::string_view name, const double salary, const int id, const Profession& profession)
: name {name}, salary {salary}, id {id}, profession {profession} {}

Person::Person()
: Person {"undefName", 0.0, 0, Profession{0}} {}

// Getter definitions ------------------------------------------------
std::string_view Person::getName() const {
    return name;
}

double Person::getSalary() const {
    return salary;
}

int Person::getID() const {
    return id;
}

Person::Profession Person::getProfession() const {
    return profession;
}

// Setter definitions ------------------------------------------------
Person& Person::setName(const std::string_view name) {
    this->name = name;
    return *this;
}

Person& Person::setSalary(const double salary) {
    this->salary = salary;
    return *this;
}

Person& Person::setID(const int id) {
    this->id = id;
    return *this;
}

Person& Person::setProfession(const Profession& profession) {
    this->profession = profession;
    return *this;
}

// Member function definitions --------------------------------------
void Person::giveRaise() {
    salary *= 1.25;
}

void Person::reset() {
    *this = Person{};
}

void Person::print() const {
    std::cout <<   "Name: "       << getName() <<
                 "\nSalary: $"    << getSalary() <<
                 "\nID: "         << getID() <<
                 "\nProfession: " << getProfession() << '\n';
}

void Person::talkAboutIt() const {
    std::cout << getName() << " talks about their job as a " << getProfession() << ".\n";
}

// Operator overloads -----------------------------------------------
std::ostream& operator<<(std::ostream& out, const Person::Profession& profession) {
    switch (profession) {
    case Person::Profession::engineer:   return out << "Engineer";
    case Person::Profession::plumber:    return out << "Plumber";
    case Person::Profession::teacher:    return out << "Teacher";
    case Person::Profession::programmer: return out << "Programmer";
    case Person::Profession::investor:   return out << "Investor";
    case Person::Profession::chef:       return out << "Chef";
    default:                             return out << "Profession error.";
    }
}