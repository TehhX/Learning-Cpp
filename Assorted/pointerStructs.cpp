#include <iostream>

struct Employee {
    std::string name {"undef"};
    short id {0000};
};

int main() {
    Employee e1 {"Timmy", 1234};
    std::cout << e1.name << '\n';
    
    Employee& e1Reference {e1};
    std::cout << e1.name << '\n';

    Employee* e1Pointer {&e1};
    std::cout << (*e1Pointer).name << '\n'; // Bulky, but works with dereferencing
    std::cout << e1Pointer->name << '\n';   // Standard technique with arrow notation
}