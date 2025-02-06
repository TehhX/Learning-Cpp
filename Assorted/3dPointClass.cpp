#include <iostream>

class Point3D {
private:
    int x {0};
    int y {0};
    int z {0};
public:
    void setValues(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void print() const {
        std::cout << '<' << x << ", " << y << ", " << z << ">\n";
    }

    bool isEqual(Point3D& other) const {
        return this->x == other.x &&
               this->y == other.y &&
               this->z == other.z;
    }
};

int main() {
    Point3D point;
    point.setValues(1, 2, 3);
    point.print();

    Point3D point1{};
	point1.setValues(1, 2, 3);

	Point3D point2{};
	point2.setValues(1, 2, 3);
	std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

	Point3D point3{};
	point3.setValues(3, 4, 5);
	std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";
}