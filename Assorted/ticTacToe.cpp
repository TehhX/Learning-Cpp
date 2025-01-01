#include <iostream>

char values[9] {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int moves {0};

void getInput(char c) {
    int index {};

    while (true) {
        std::cout << "Enter input (" << c << "): ";
        std::cin >> index;

        if (values[index] != ' ')
            std::cout << "Already taken!\n";
        else
            break;
    }

    moves++;
    values[index] = c;
}

bool charWon(char c) {
    if (values[0] == c)
        if (values[1] + values[2] == 2 * c)  // Top row
            return true;
        if (values[4] + values[8] == 2 * c)  // Diagonal TL BR
            return true;
        if (values[3] + values[6] == 2 * c)  // Left column
            return true;

    if (values[8] == c)
        if (values[5] + values[2] == 2 * c)  // Right column
            return true;
        if (values[7] + values[6] == 2 * c)  // Bottom row
            return true;

    if (values[4] == c)
        if (values[6] + values[2] == 2 * c)  // Diagonal TR BL
            return true;
        if (values[3] + values[5] == 2 * c)  // Middle row
            return true;
        if (values[1] + values[7] == 2 * c)  // Middle column
            return true;

    return false;
}

void printBoard() {
    std::cout << "\nP1: O | P2: X | Moves: " << moves << "\n\n";
    std::cout << "       " << values[0] << " | " << values[1] << " | " << values[2] << '\n';
    std::cout << "      ---|---|---\n";
    std::cout << "       " << values[3] << " | " << values[4] << " | " << values[5] << '\n';
    std::cout << "      ---|---|---\n";
    std::cout << "       " << values[6] << " | " << values[7] << " | " << values[8] << "\n\n";
}

bool checkForWinner() {
    char c {};

    if (charWon('O'))
        c = 'O';
    else if (charWon('X'))
        c = 'X';
    else
        return false;

    std::cout << c << " won in " << moves << " moves!\n";
    return true;
}

int main() {
    printBoard();

    while (true) {
        getInput('O');
        printBoard();
        if (checkForWinner())
            break;

        getInput('X');
        printBoard();
        if (checkForWinner())
            break;
    }
}