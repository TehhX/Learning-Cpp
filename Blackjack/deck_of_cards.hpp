#pragma once

#include <iostream>
#include <vector>

class Card {
public:
    enum class Rank {
        ace,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king,
        rank_max
    };

    enum class Suit {
        clubs,
        diamonds,
        hearts,
        spades,
        suit_max
    };

private:
    Rank rank;
    Suit suit;

public:
    Card(const Rank, const Suit);
    Card();
    
    Card& setRank(const Rank);
    Rank getRank() const;

    Card& setSuit(const Suit);
    Suit getSuit() const;

    int value() const;
};

class Deck {
private:
    std::vector<Card> cards; // The deck of cards

public:
    Deck();                  // Create and shuffle the deck

    Card dealCard();         // Removes and returns the card at the top of the deck

    void shuffle();          // Mixes the card order randomly

    void print() const;      // Prints all the cards in order
};

std::ostream& operator<<(std::ostream&, const Card::Rank);
std::ostream& operator<<(std::ostream&, const Card::Suit);
std::ostream& operator<<(std::ostream&, const Card&);