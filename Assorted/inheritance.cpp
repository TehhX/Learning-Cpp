#include <iostream>

class Base {
private:
    const int baseID;

protected:
    // Print thing is protected.
    void printThing() const {
        std::cout << "Thing.\n";
    }

public:
    Base(const int baseID)
    : baseID { baseID } {}

    int getBaseID() const { return baseID; };
};

class Derived : public Base {
private:
    const int derivedID;

public:
    Derived(const int baseID, const int derivedID)
    : Base { baseID }
    , derivedID { derivedID } {}

    int getDerivedID() const { return derivedID; }

    // Making printThing public in derived.
    using Base::printThing;
};

int main() {
    Base base { 5 };
    std::cout << base.getBaseID() << '\n';
    // base.printThing(); // Won't compule due to access modifier Protected.

    Derived derived { 10, 3 };
    std::cout << derived.getBaseID() << ' ' << derived.getDerivedID() << std::endl;
    derived.printThing(); // Will compile due to access modifier changing in Derived.
}