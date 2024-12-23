#include <iostream>
#include <string>

std::string inputName(int index) {
    std::cout << "Enter the name of person " << index << ": ";
    std::string input {};
    std::getline(std::cin >> std::ws, input);
    return input;
}

int inputAge(std::string_view name) {
    std::cout << "Enter the age of " << name << ": ";
    int input {};
    std::cin >> input;
    return input;
}

void outputResult(int age1, int age2, std::string_view name1, std::string_view name2) {
    std::cout << name1 << " (age " << age1 << ") " << "is older than " << name2 << " (age " << age2 << ").\n";
}

int main() {
    const std::string name1 { inputName(1) };
    const int age1 { inputAge(name1) };

    const std::string name2 { inputName(2) };
    const int age2 { inputAge(name2) };
    
    if (age1 > age2) outputResult(age1, age2, name1, name2);
    else outputResult(age2, age1, name2, name1);
}