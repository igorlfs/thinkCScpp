#ifndef DECK
#define DECK
#include <vector>

#include "cards.hpp"
class Deck {
    std::vector<Card> cards;

   public:
    Deck(int n);
    Deck();
    void printDeck() const;
    int find(const Card& card) const;
    Card* findLowestCard(const int& index);
    void shuffle();
    void sort();
    Deck subdeck(int low, int high) const;
};
#endif
