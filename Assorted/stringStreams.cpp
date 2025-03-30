#include <iostream>
#include <sstream>

int main() {
    constexpr char name[] { "Timmy" };
    constexpr char container[] { "bag" };
    constexpr short appleCount { 15 };

    std::stringstream stringStream {};
    stringStream << "There are " << appleCount << " apples in " << name << "'s " << container << ".\n";
    
    std::cout << stringStream.str();

    return 0;
}