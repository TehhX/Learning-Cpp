#include <iostream>

class Ball {
private:
    std::string color;
    float radius;

public:
    // Has both
    Ball(const std::string_view color, const float radius) 
    : color {color}, radius {radius} {
        std::cout << "Ball(" << color << ", " << radius << ")\n";
    }

    // Has color
    Ball(const std::string_view color)
    : Ball {color, 10.0f} {}

    // Has radius
    Ball(const float radius)
    : Ball {"black", radius} {}

    // Has neither
    Ball() 
    : Ball {"black", 10.0f} {}
};

int main() {
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };
}