#include <iostream>

class A {
public:
    A() {
        std::cout << "A::A()\n";
    }

    virtual ~A() {
        std::cout << "A::~A()\n";
    }
};

class B : A {
public:
    B() {
        std::cout << "B::B()\n";
    }

    // Without marking as virtual, would only call this destructor.
    // When marked as virtual, will first destruct derived, then base.
    virtual ~B() {
        std::cout << "B::~B()\n";
    }
};

int main() {
    /* A Scope. */ {
        std::cout << "Entered A scope.\n";
        A a { A() };
        std::cout << "\nExiting A scope.\n";
    }

    /* B Scope. */ {
        std::cout << "\nEntered B scope.\n";
        B b { B() };
        std::cout << "\nExiting B scope.\n";
    }

    return 0;
}