#pragma once

#include <iostream>

enum class Profession: int {
    engineer,
    plumber,
    teacher,
    programmer,
    investor,
    chef
};

class Person {
private:
    // Private instance variables:
    std::string name;
    double salary;
    int id;
    Profession profession;

    // Private member function declarations:
    void becomeJerry();

public:
    // Constructor declarations:
    Person(const std::string_view, const double, const int, const Profession&);
    Person();

    // Getter definitions:
    std::string_view getName()           const { return name; }
    constexpr double getSalary()         const { return salary; }
    constexpr int getID()                const { return id; }
    constexpr Profession getProfession() const { return profession; }

    // Setter definitions:
    void setName(const std::string_view name) { this->name = name; }
    void setSalary(const double salary) { this->salary = salary; }
    void setID(const int id) { this->id = id; }
    void setProfession(const Profession& profession) { this->profession = profession; }

    // Public member function declarations:
    void calculateBonus();
    void reset();
};

// Non-member function declarations:
void print(const Person&);
void talkAboutIt(const Person&);