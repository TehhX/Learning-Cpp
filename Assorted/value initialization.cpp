#include <iostream>

using namespace std;

int main() {
    int x {49};
    int y {0};
    int z {};
    cout << "X: " << x << endl; // 49
    cout << "Y: " << y << endl; // 0
    cout << "Z: " << z << endl; // 0 (Same)
    return 0;
}