#ifndef CARDS
#define CARDS
#include <vector>
enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum Rank {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};
struct Card {
    Suit suit;
    Rank rank;
    void print() const;
    bool equals(const Card& c2) const;
    int find(const Card& card, const std::vector<Card>& deck);
    bool isGreater(const Card& c2) const;
    bool isSmaller(const Card& c2) const;
    std::vector<Card> buildDeck();
};
#endif
