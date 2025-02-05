#include <iostream>

enum Jobs { // No base specified
    Electrician,
    Cleaner,
    Teacher,
    Plumber,
    Technician
};

enum Names: int { // Base of integer specified
    Timmy,
    Jason,
    Guy,
    Sandra,
    Ava,
    Andy
};

int main() {
    // Regular style:
    // Jobs job {0};   Won't compile
    Names name {0}; // Will compile

    // Workaround:
    Jobs job {static_cast<Jobs>(0)};    // Will now compile
    Names name {static_cast<Names>(0)}; // Will still compile
}