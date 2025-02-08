#include "readWriteIO.hpp"

int main() {
    int toPrint { readNumber() };

    writeAnswer( toPrint );
}