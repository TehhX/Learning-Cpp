#include "deck_of_cards.hpp"

namespace Settings {
    constexpr int blackjack   { 21 };
    constexpr int stopDrawing { 17 };
}

int main() {
    Deck deck {};

    int dealer { deck.dealCard().value() };
    int player { deck.dealCard().value() };

    std::cout << "The dealer is showing a score of " << dealer <<
               "\nYou have a score of " << player << '\n';

    bool playing { true };

    while (true) {
        Card dealerCard { deck.dealCard() };
        dealer += dealerCard.value();

        while (playing) {
            std::cout << "(h) to hit, or (s) to stand: ";

            char in {};
            std::cin >> in;

            std::cout << '\n';

            if (in == 's')
                playing = false;
            
            else if (in == 'h') {
                Card playerCard { deck.dealCard() };
                player += playerCard.value();

                std::cout << "You were dealt " << playerCard << ". You now have " << player << ".\n";

                break;
            }
        }

        std::cout << "The dealer flips a " << dealerCard << ". They now have " << dealer << ".\n";

        if (dealer > Settings::stopDrawing)
            break;

        if (player > Settings::blackjack)
            break;
    }

    if (dealer == player)
        std::cout << "You tied!\n";

    else if (dealer == Settings::blackjack)
        std::cout << "The dealer got blackjack!\n";

    else if (player == Settings::blackjack)
        std::cout << "You got blackjack!\n";

    else if (dealer > Settings::blackjack)
        std::cout << "The dealer went bust!\n";

    else if (player > Settings::blackjack)
        std::cout << "You went bust!\n";

    else if (player > dealer)
        std::cout << "You win!\n";

    else
        std::cout << "You lose.\n";
}