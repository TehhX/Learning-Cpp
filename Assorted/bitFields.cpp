#include <iostream>

/*
    Use a bit-field like:
        <TYPE> <NAME> : <BITS>;

    A boolean named "Size" 1 bit wide would be:
        bool Size : 1;
*/

// This struct uses a bitfield.
struct BF_Options {
    bool a : 1;
    bool b : 1;
    bool c : 1;
    bool d : 1;
    bool e : 1;
    bool f : 1;
    bool g : 1;
    bool h : 1;
};

// This one doesn't
struct NBF_Options {
    bool a;
    bool b;
    bool c;
    bool d;
    bool e;
    bool f;
    bool g;
    bool h;
};

int main() {
    int bf_size = sizeof(BF_Options);
    int nbf_size = sizeof(NBF_Options);

    // Bit field should ALWAYS be smaller than an NBF
    std::cout <<  "Size of BF: " <<  bf_size << '\n';
    std::cout << "Size of NBF: " << nbf_size << "\n\n";

    if (bf_size < nbf_size)
        std::cout << "Bit field is smaller.\n";
    else // Shouldn't happen
        std::cout << "Non bit field is smaller.\n";
}
