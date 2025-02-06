#include <iostream>

struct Employee {
    int id;
    int age;
    int hireYear;
    int hireMonth;
    int hireDate;
};

struct Place {
    std::string name {"undefined"};
    int ticketCost {1'200};
};

// Overloads the << operator for printing the employee struct all at once.
// Acts like toString in Java
std::ostream& operator<<(std::ostream& out, const Employee& e) {
    std::string_view pause {", "};

    return out << e.id << pause << e.age << pause << e.hireYear << pause <<
            e.hireMonth << pause << e.hireDate;
}

int main() {
    Employee joseph {};
    joseph.id = 1234;
    joseph.age = 24;
    joseph.hireYear = 2013;
    joseph.hireMonth = 3;
    joseph.hireDate = 8;
    std::cout << joseph.id << '\n';

    Employee timmy {345, 46, 1998, 5, 12};
    std:: cout << timmy << '\n';
    timmy = {timmy.id, 345, 3445, 765, timmy.hireDate}; // Change some values with initializer list, keep some the same by using their names
    std:: cout << timmy << '\n';

    Place spain {"Spain"};
    std::cout << spain.ticketCost << '\n';
}