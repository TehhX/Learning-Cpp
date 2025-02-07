#include <iostream>

class Guy {
private:
    std::string name;

public:
    Guy(const std::string_view name)
    : name {name} {}

    Guy()
    : Guy {"noName"} {}

    // Implicit copy constructor made by compiler

    void print() const {
        std::cout << "Name is " << name << ".\n";
    }
};

class Fella {
private:
    std::string name;

public:
    Fella(const std::string_view name)
    : name {name} {}

    Fella(const Fella& fella) // Copy constructor. Will append " copy".
    : name {fella.name + " copy"} {}

    void print() const {
        std::cout << "Name is " << name << ".\n";
    }
};

class DontCopyThis {
private:
    std::string name;

public:
    DontCopyThis(const std::string_view name)
    : name {name} {}

    DontCopyThis(const DontCopyThis& dontCopyThis) = delete; // Specify that this class can't be copied
};

Guy garryGuy() {
    return Guy {"Garry"}; // Temporary guy object.
}

int main() {
    Guy fella {"Larry"};
    Guy otherFella {garryGuy()};

    fella.print();
    otherFella.print();

    std::cout << '\n';

    Fella guy {"Terry"};
    Fella sameGuy {guy}; // Using copy constructor

    guy.print();
    sameGuy.print();

    DontCopyThis first {"Fella"};
    // DontCopyThis second {first}; Won't compile, deleted copy constructor.
}