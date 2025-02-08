#pragma once

#include <string>

class Person {
public:
    enum Profession: int {
        engineer,
        plumber,
        teacher,
        programmer,
        investor,
        chef
    };

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

    // Getter declarations:
    std::string_view getName() const;
    double getSalary() const;
    int getID() const;
    Profession getProfession() const;

    // Setter declarations:
    Person& setName(const std::string_view);
    Person& setSalary(const double);
    Person& setID(const int);
    Person& setProfession(const Profession&);

    // Public member function declarations:
    void giveRaise();
    void reset();
    void print() const;
    void talkAboutIt() const;
};

std::ostream& operator<<(std::ostream&, const Person::Profession&);