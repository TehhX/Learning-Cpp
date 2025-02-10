#include <string>

class Holder {
private:
    std::string name;

public:
    Holder(const std::string_view name)
    : name {name} {}

    // Getters
    const std::string& getName() const & { return name; } // Single '&' qualifies for a reference return.
    std::string getName() const && { return name; } // Double '&' qualifies for a copy r-value return.
};

int main() {
    Holder held1 {"Joseph"};

    std::string name1 {held1.getName()}; // Permenant l-value object, uses reference func with '&'
    std::string name2 {Holder{"Jerry"}.getName()}; // Temporary r-value object, uses copy func with "&&"
}