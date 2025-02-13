#include "deck_of_cards.hpp"

#include <random>
#include <algorithm>

using Suit = Card::Suit;
using Rank = Card::Rank;

// Card

Card::Card(const Rank rank, const Suit suit)
: rank {rank}, suit {suit} {}

Card& Card::setRank(const Rank rank) {
    this->rank = rank;
    return *this;
}

Rank Card::getRank() const {
    return rank;
}

Card& Card::setSuit(const Suit suit) {
    this->suit = suit;
    return *this;
}

Suit Card::getSuit() const {
    return suit;
}

int Card::value() const {
    Rank rank { getRank() };

    if (rank < Rank::jack)
        return static_cast<int>(rank) + 1;

    else
        return 10;
}

std::ostream& operator<<(std::ostream& out, const Rank rank) {
    if (rank > Rank::ace && rank < Rank::jack)
        return out << static_cast<int>(rank) + 1;

    switch (rank) {
    case Rank::ace:   return out << "A";
    case Rank::jack:  return out << "J";
    case Rank::queen: return out << "Q";
    case Rank::king:  return out << "K";
    default:          return out;
    }
}

std::ostream& operator<<(std::ostream& out, const Suit suit) {
    switch (suit) {
    case Suit::clubs:    return out << "C";
    case Suit::diamonds: return out << "D";
    case Suit::hearts:   return out << "H";
    case Suit::spades:   return out << "S";
    default:             return out;
    }
}

std::ostream& operator<<(std::ostream& out, const Card& card) {
    return out << card.getRank() << card.getSuit();
}

// Deck

Deck::Deck() {
    cards.reserve(52);
    
    for (int i1 {0}; i1 < static_cast<int>(Suit::suit_max); i1++)
        for (int i2 {0}; i2 < static_cast<int>(Rank::rank_max); i2++)
            cards.emplace_back(static_cast<Rank>(i2), static_cast<Suit>(i1));

    shuffle();
}

Card Deck::dealCard() {
    Card temp { cards.back() };
    cards.pop_back();
    return temp;
}

void Deck::shuffle() {
    static std::random_device rd {};
    static std::seed_seq seedSequence { rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    static std::mt19937 generator { seedSequence };

    std::shuffle(cards.begin(), cards.end(), generator);
}

void Deck::print() const {
    for (const auto& card : cards)
        std::cout << card << '\n';
}