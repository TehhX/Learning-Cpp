#include <iostream>
#include <cmath>

class Point2d {
private:
    double x;
    double y;

public:
    Point2d(const double x, const double y)
    : x {x}, y {y} {}

    Point2d()
    : x {0.0}, y {0.0} {}

    void print() const {
        std::cout << "Point2d(" << x << ", " << y << ")\n"; 
    }

    double distanceTo(const Point2d& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }
};

int main() {
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();
    
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
}