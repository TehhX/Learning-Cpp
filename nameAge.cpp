#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your full name: ";
    std::string name {};
    std::cin >> name;

    std::cout << "Enter your age: ";
    int age {};
    std::cin >> age;

    std::cout << "Your age + length of name is: " << age + static_cast<int>(name.length()) << '\n';
}