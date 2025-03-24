#include <iostream>

class Animal {
private:
    const std::string_view name;
    unsigned int age;

public:
    Animal(const std::string_view name, const unsigned int age)
    : name { name }, age { age } {}

    void printInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << '\n';
    }

    virtual void speak() const = 0;
};

class Dog : public Animal {
public:
    Dog(const std::string_view name, const unsigned int age)
    : Animal { name, age } {}

    virtual void speak() const override { std::cout << "Woof.\n"; }
};

class Cat : public Animal {
public:
    Cat(const std::string_view name, const unsigned int age)
    : Animal { name, age } {}

    virtual void speak() const override { std::cout << "Meow.\n"; }
};

int main() {
    // Won't compile beacuse Animal is abstract. This is due to a pure virtual function in Animal.
    // Animal animal { "Animal", 0 };

    Dog dog { "Terry", 2 };
    Cat cat { "Winston", 4 };

    dog.printInfo();
    cat.printInfo();
    std::cout << '\n';

    dog.speak();
    cat.speak();

    return 0;
}