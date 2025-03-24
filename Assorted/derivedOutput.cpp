#include <iostream>

class A {
private:
    int id;
    std::string name;
public:
    A(const int id, const std::string_view name)
    : id { id }, name { name } {}

    // Function that handles output.
    virtual std::ostream& toString(std::ostream& out) const {
        return out << "ID: " << id << ", Name: " << name;
    }

    // Base class operator override.
    friend std::ostream& operator<<(std::ostream& out, const A& a) {
        return a.toString(out);
    }
};

class B : public A {
private:
    char special;
public:
    B(const int id, const std::string_view name, const char special)
    : A { id, name }, special { special } {}

    // Derived output handling override.
    virtual std::ostream& toString(std::ostream& out) const override {
        return A::toString(out) << ", Special: " << special;
    }
};

int main() {
    A a { 15, "Timmy" };
    B b { 56, "James", 'X' };

    std::cout << a << '\n'; // Calls operator<< using A::toString(std::ostream&)
    std::cout << b << '\n'; // Calls operator<< using B::toString(std::ostream&)

    return 0;
}