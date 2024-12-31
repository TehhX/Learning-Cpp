#include <iostream>

void exampleOne();
void exampleTwo();
void exampleThree();

void passValue(std::string text) {         // <type> <name> means pass value.
    std::cout << text << '\n';
}

void passReference(std::string& text) {    // <type>& <name> means pass reference.
    std::cout << text << '\n';
}

void changeValue(std::string text) {       // Changes a copy of the original
    text = "Changed text!";
}

void changeReference(std::string& text) {  // Changes the actual original
    text = "Changed text!";
}

void mutableParameter(float& value) {
    std::cout << "Value: " << value << '\n';
}

void constParameter(const float& value) {
    std::cout << "Constant Value: " << value << '\n';
}

int main() {
    exampleOne();    // Pass By Value (PBV) and Pass By Reference (PBR) Functions
    exampleTwo();    // Editing PBV and PBR Variables
    exampleThree();  // Const Reference Function Example
}

void exampleOne() {
    std::string original {"Hello World!"};

    passValue(original);          // Expensive, creates a copy of class object hw
    passReference(original);      // Inexpensive, creates reference to hw
}

void exampleTwo() {
    std::string original {"Unchanged Text!"};

    changeValue(original);
    passReference(original);     // Will print unchanged text.

    changeReference(original);
    passReference(original);     // Will print changed text.
}

void exampleThree() {
    const float value {9.81};

    // mutableParameter(value); Won't compile, parameter is non-const
    constParameter(value);
}