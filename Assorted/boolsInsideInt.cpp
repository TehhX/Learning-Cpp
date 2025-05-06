/*
    BoolInsideInt.cpp Description and Notes:

        This program demonstrates passing several unique boolean values in a single integer.
    It uses bit manipulation to see which options were passed inside the integer.

        The values must not be mutually exclusive i.e. all the values can be chosen, none can, or some combo of any.
    I have also made a struct "DinnerOptions" to demonstrate an easier way to do this.

        However, the struct is 8 bytes, while the "Bools Inside Int" (BII) integer is only 1 byte (on my machine).
    This seems to be the most obvious and largest advantage of the BII method.

        I'm not quite sure why this happens, but it seems that each boolean is taking an entire byte, when it only
    requires a bit. Maybe something to do with packing, like issues that sometimes arise with boolean arrays. After
    all, both methods store the EXACT same amount of data, at least bitwise.

        Another, smaller advantage is that order is not enforced for BII integers, as it is with structs.
    Out-of-order initializers are non-standard for C++, and will show a warning if it is attempted.
    This is a much smaller issue than size constraints could potentially be.
*/

#include <iostream>

// "Bools Inside Int" method:
// --------------------------

// Note: I'm using 8 options in both methods because they neatly fit into a single byte of data.

enum BII_Options : unsigned char {
    APPETIZER = 0b00'00'00'01, // Use the 0b bit syntax to select specific bits to set to 1.
    ENTREE    = 0b00'00'00'10, // Note: Numbers of other bases may also be used, but this demonstates the point better.
    BREAD     =             4, // Although, just as an example, 0b00'00'01'00 is 4 in decimal, so this will work exactly the same.
    SAUCE     = 0b00'00'10'00,
    MAIN      = 0b00'01'00'00,
    FRIES     = 0b00'10'00'00,
    DESSERT   = 0b01'00'00'00,
    COFFEE    = 0b10'00'00'00,

    BII_ALL   = 0b11'11'11'11  // If you want an option for all, fill all bits with 1's, or use the decimal value of 255.
};

// A simple function to demonstrate extracting options from the integer:
void printOptions(int input) {
    if (APPETIZER & input)
        std::cout << "Appetizer ";

    if (ENTREE & input)
        std::cout << "Entree ";

    if (BREAD & input)
        std::cout << "Bread ";

    if (SAUCE & input)
        std::cout << "Sauce ";

    if (MAIN & input)
        std::cout << "Main ";

    if (FRIES & input)
        std::cout << "Fries ";

    if (DESSERT & input)
        std::cout << "Dessert ";

    if (COFFEE & input)
        std::cout << "Coffee ";

    std::cout << '\n';
}

// "Struct" method:
// ----------------

struct DinnerOptions {
    bool appetizer { false }; // Initialize all to false
    bool entree    { false };
    bool bread     { false };
    bool sauce     { false };
    bool main      { false };
    bool fries     { false };
    bool dessert   { false };
    bool coffee    { false };
};

// ST_ALL copies the behavior of BII_ALL, but for use in the Struct method:
constexpr DinnerOptions ST_ALL { true, true, true, true, true, true, true, true };

// A simple function to demonstrate accessing member bools inside struct:
void printOptions(const DinnerOptions& input) {
    if (input.appetizer)
        std::cout << "Appetizer ";

    if (input.entree)
        std::cout << "Entree ";

    if (input.bread)
        std::cout << "Bread ";

    if (input.sauce)
        std::cout << "Sauce ";

    if (input.main)
        std::cout << "Main ";

    if (input.fries)
        std::cout << "Fries ";

    if (input.dessert)
        std::cout << "Dessert ";

    if (input.coffee)
        std::cout << "Coffee ";

    std::cout << '\n';
}

int main() {
// This portion demonstrates the "Bools Inside Int" approach:
    printOptions( APPETIZER | BREAD | SAUCE );
    printOptions( ENTREE | SAUCE | FRIES | DESSERT | COFFEE ); // Pick and choose any using bitwise OR's "|"

    std::cout << '\n';
    printOptions(255);
    printOptions(BII_ALL); // These two calls do the exact same thing.

// This portion demonstrates the "Struct" approach:
    std::cout << '\n';
    printOptions({ .entree = true, .coffee = true }); // This syntax for choosing
    printOptions({ .appetizer = true, .sauce = true, .dessert = true, .coffee = true });

    std::cout << '\n';
    printOptions(ST_ALL);

// Comparing the sizes in bytes:
    std::cout << "\nSize of BII type in bytes: " << sizeof(APPETIZER) << '\n';
    std::cout << "Size of Struct type in bytes: " << sizeof(DinnerOptions) << '\n';
}
