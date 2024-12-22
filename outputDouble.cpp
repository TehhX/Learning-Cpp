#include <iostream>

using namespace std;

int main() {
    cout << "Enter an integer: ";

    int inputValue {};
    cin >> inputValue;

    int outputValue = { inputValue * 2};
    cout << "Double that number is: " << outputValue << endl;

    return 0;
}