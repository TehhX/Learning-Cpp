#include <iostream>

const std::string& getThing() {
    static const std::string innerString {"Yessir"};
    std::cout << "Inner String Address: " << &innerString << '\n';
    return innerString;
}

int main() {
    const std::string& outerString {getThing()};
    std::cout << outerString << '\n';
    std::cout << "Outer String Address: " << &outerString << '\n'; // Same address as inner
}