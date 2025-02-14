#include <iostream>

int main() {
    int x { 5 };
    float y { 12.5f };
    double z { 19.99 };
    void* ptr {};

    ptr = &x;
    std::cout << *(static_cast<int*>(ptr)) << '\n';

    ptr = &y;
    std::cout << *(static_cast<float*>(ptr)) << '\n';

    ptr = &z;
    std::cout << *(static_cast<double*>(ptr)) << '\n';
}