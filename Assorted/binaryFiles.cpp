#include <iostream>
#include <fstream>

#define FILE_NAME "myFile.bin"

// Types of each value
#define TYPE_ONE   char
#define TYPE_TWO   int
#define TYPE_THREE unsigned long long

// Sizes of the types
#define SIZE_ONE   sizeof(TYPE_ONE)
#define SIZE_TWO   sizeof(TYPE_TWO)
#define SIZE_THREE sizeof(TYPE_THREE)

// Arbitrary values to use
#define VALUE_ONE   87
#define VALUE_TWO   12'000
#define VALUE_THREE 0xFFFFFFFFFF

void write() {
    std::ofstream out { FILE_NAME, std::ios::out | std::ios::binary };

    if (out.fail())
        exit(EXIT_FAILURE);

    TYPE_ONE valOne { VALUE_ONE };
    out.write(reinterpret_cast<char*>(&valOne), SIZE_ONE);

    TYPE_TWO valTwo { VALUE_TWO };
    out.write(reinterpret_cast<char*>(&valTwo), SIZE_TWO);

    TYPE_THREE valThree { VALUE_THREE };
    out.write(reinterpret_cast<char*>(&valThree), SIZE_THREE);

    out.close();

    if (out.fail())
        exit(EXIT_FAILURE);
}

void read() {
    std::ifstream in { FILE_NAME, std::ios::in | std::ios::binary };

    if (in.fail())
        exit(EXIT_FAILURE);

    TYPE_ONE valOne;
    in.read(reinterpret_cast<char*>(&valOne), SIZE_ONE);
    std::cout << "Value one: " << static_cast<int>(valOne) << '\n';

    TYPE_TWO valTwo;
    in.read(reinterpret_cast<char*>(&valTwo), SIZE_TWO);
    std::cout << "Value two: " << valTwo << '\n';

    TYPE_THREE valThree;
    in.read(reinterpret_cast<char*>(&valThree), SIZE_THREE);
    std::cout << "Value three: " << valThree << '\n';

    // Check if the values match from write to read
    if (valOne != VALUE_ONE || valTwo != VALUE_TWO || valThree != VALUE_THREE)
        std::cout << "Some values mismatch.\n";
    else
        std::cout << "All values match.\n";
}

// Writes data to a file, reads data from same file
int main() {
    write();
    read();
}
