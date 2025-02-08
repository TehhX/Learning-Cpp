#include <iostream>

class SelfDestruct {
public:
    std::string name;

    SelfDestruct(const std::string_view name) 
    : name {name} {
        std::cout << "Constructing:   " << name << '\n';
    }

    // Destructor needs a ~ before the name.
    ~SelfDestruct() {
        std::cout << "Destructing:    " << name << '\n';
    }
};

int main() {
    SelfDestruct obj {"Outer"};

    {
        SelfDestruct objInner {"  Inner"};

        for (int i {0}; i < 3; i++) {
            SelfDestruct objLoop {"    Loop #" + std::to_string(i)};
        } // objLoop constructs and destructs repeatedly
    } // objInner destructs
} // obj destructs