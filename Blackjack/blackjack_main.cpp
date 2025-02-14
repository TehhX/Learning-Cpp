#include "deck_of_cards.hpp"

namespace Settings {
    constexpr int blackjack   { 21 };
    constexpr int stopDrawing { 17 };
}

bool playerTurn(Deck& deck, int& player) {
    while (true) {
        std::cout << "(h) to hit, or (s) to stand: ";

        char in {};
        std::cin >> in;

        std::cout << '\n';

        if (in == 's')
            return false;
        
        if (in == 'h') {
            Card playerCard { deck.dealCard() };
            player += playerCard.value();

            std::cout << "You were dealt " << playerCard << ". You now have " << player << ".\n";

            return true;
        }
    }
}

bool dealerTurn(Deck& deck, int& dealer) {
    Card dealerCard { deck.dealCard() };
    dealer += dealerCard.value();

    std::cout << "The dealer flips a " << dealerCard << ". They now have " << dealer << ".\n";

    return true;
}

int main() {
    Deck deck {};

    int dealer { deck.dealCard().value() };
    int player { deck.dealCard().value() };

    std::cout << "You have a score of " << player <<
               "\nThe dealer is showing a score of " << dealer << '\n';
               
    bool dealerActive { true };
    bool playerActive { true };

    while (dealerActive || playerActive) {
        if (playerActive)
            playerActive = playerTurn(deck, player);

        if (player == Settings::blackjack) {
            std::cout << "You got blackjack!\n";
            return 0;
        }

        if (player > Settings::blackjack) {
            std::cout << "You went bust!\n";
            return 0;
        }

        if (dealerActive)
            dealerActive = dealerTurn(deck, dealer);

        if (dealer == Settings::blackjack) {
            std::cout << "The dealer got blackjack!\n";
            return 0;
        }
    
        if (dealer > Settings::blackjack) {
            std::cout << "The dealer went bust!\n";
            return 0;
        }
            
        if (dealer > Settings::stopDrawing)
            dealerActive = false;
    }

    if (dealer == player)
        std::cout << "You tied!\n";

    else if (player > dealer)
        std::cout << "You win!\n";

    else
        std::cout << "You lose.\n";
}