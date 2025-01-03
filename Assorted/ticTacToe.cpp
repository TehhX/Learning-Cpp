#include <iostream>

char values[9] {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int moves {0};

void getInput(char c) {
    int index {};

    while (true) {
        std::cout << "Enter input (" << c << "): ";
        std::cin >> index;
        index--;

        if (values[index] == 'O' || values[index] == 'X')
            std::cout << "Already taken!\n";
        else
            break;
    }
    
    moves++;
    values[index] = c;
}

bool charWon(char c) {
    if (values[0] == c) {
        if (values[1] == c && values[2] == c)  // Top row
            return true;
        if (values[4] == c && values[8] == c)  // Diagonal TL BR
            return true;
        if (values[3] == c && values[6] == c)  // Left column
            return true;
    }

    if (values[4] == c) {
        if (values[6] == c && values[2] == c)  // Diagonal TR BL
            return true;
        if (values[3] == c && values[5] == c)  // Middle row
            return true;
        if (values[1] == c && values[7] == c)  // Middle column
            return true;
    }

    if (values[8] == c) {
        if (values[5] == c && values[2] == c)  // Right column
            return true;
        if (values[7] == c && values[6] == c)  // Bottom row
            return true;
    }

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

    if (charWon('O'))  // If player O won
        c = 'O';
    else if (charWon('X'))  // If player X won
        c = 'X';
    else if (moves == 9) {  // If all squares filled but no wins
        std::cout << "It's a tie!\n";
        return true;
    }
    else  // If nobody won or tied
        return false;

    std::cout << c << " won in " << moves << " moves!\n";  // Only executed if O or X won
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