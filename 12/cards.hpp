#ifndef CARDS
#define CARDS
#include <vector>
struct Card {
    int suit, rank;
    Card();
    Card(int s, int r);
    void print() const;
    bool equals(const Card& c1, const Card& c2);
    int find(const Card& card, const std::vector<Card>& deck);
    bool isGreater(const Card& c2) const;
    std::vector<Card> buildDeck();
};
#endif
