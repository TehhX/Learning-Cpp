#include <iostream>
#include <random>

std::string_view posMatrix(std::string_view computer, std::string_view player) {
    if (computer == player)
        return "tied.";

    if (computer == "rock") {
        if (player == "paper")
            return "won!";
        if (player == "scissors")
            return "lost.";
    }

    if (computer == "paper") {
        if (player == "rock")
            return "lost.";
        if (player == "scissors")
            return "won!";
    }

    if (computer == "scissors") {
        if (player == "rock")
            return "won!";
        if (player == "paper")
            return "lost.";
    }

    return "Unknown match."; // Should never happen.
}

std::string_view randomResponse() {
    static std::mt19937 gen {std::random_device{}()};
    static std::uniform_int_distribution<> dist {0, 2};

    switch (dist(gen)) {
    case 0:
        return "rock";
    case 1:
        return "paper";
    case 2:
        return "scissors";
    }
    
    return "Error"; // Should never happen.
}

std::string getInput(std::string_view text) {
    std::cout << text;

    std::string input;
    std::getline(std::cin >> std::ws, input);

    return input;
}

void gameplayLoop() {
    std::string_view player {getInput("Choose a move: ")};

    std::string_view computer {randomResponse()};
    std::cout << "Computer chose " << computer << ".\n";

    std::cout << "You " << posMatrix(computer, player) << "\n\n";
}

int main() {
    while (true) {
        gameplayLoop(); }
}