#include "readWriteIO.h"

int main() {
    int toPrint { readNumber() };

    writeAnswer( toPrint );
}