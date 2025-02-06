#include <iostream>

class Person {
private:
    std::string name;
    int id;

public:
    // Constructor with all parameters
    Person(std::string_view name, int id)
        : name {name}, id {id} // Member initialization list
    {
        std::cout << "Constructed with input.\n";
    }

    // Constructor with no parameters
    Person()
        : name {"Timmy"}, id {12345} // Member initialization list
    {
        std::cout << "Constructed without input.\n";
    }

    void print() const {
        std::cout << "Name: " << name << "\nID: " << id << '\n';
    }

    // Set/Get Name
    void setName(const std::string_view name) { this->name = name; }
    std::string_view getName() const { return name; }

    // Set/Get ID
    void setID(const int id) { this->id = id; }
    int getID() const { return id; }
};

int main() {
    Person fella {"Jason", 859};
    fella.print();

    std::cout << '\n';

    Person otherGuy {};
    otherGuy.print();
}