#include "cards.hpp"

#include <iostream>
using namespace std;
void Card::print() const {
    string suits[4];
    suits[0] = "Clubs";
    suits[1] = "Diamonds";
    suits[2] = "Hearts";
    suits[3] = "Spades";
    string ranks[15];
    ranks[1] = "Ace";
    ranks[2] = "2";
    ranks[3] = "3";
    ranks[4] = "4";
    ranks[5] = "5";
    ranks[6] = "6";
    ranks[7] = "7";
    ranks[8] = "8";
    ranks[9] = "9";
    ranks[10] = "10";
    ranks[11] = "Jack";
    ranks[12] = "Queen";
    ranks[13] = "King";
    cout << ranks[rank] << " of " << suits[suit] << endl;
}
bool Card::equals(const Card& c2) const {
    return (rank == c2.rank && suit == c2.suit);
}
int Card::find(const Card& card, const vector<Card>& deck) {
    for (int i = 0; i < 52; i++) {
        if (deck[i].equals(card)) return i;
    }
    return -1;
}
vector<Card> Card::buildDeck() {
    vector<Card> deck(52);
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit + 1)) {
        for (Rank rank = ACE; rank <= KING; rank = Rank(rank + 1)) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            i++;
        }
    }
    return deck;
}
bool Card::isGreater(const Card& c2) const {
    // first check the suits
    if (suit > c2.suit) return true;
    if (suit < c2.suit) return false;
    // if the suits are equal, check the ranks
    if (rank > c2.rank) return true;
    if (rank < c2.rank) return false;
    // if the ranks are also equal, return false
    return false;
}
bool Card::isSmaller(const Card& c2) const {
    // first check the suits
    if (suit > c2.suit) return false;
    if (suit < c2.suit) return true;
    // if the suits are equal, check the ranks
    if (rank > c2.rank) return false;
    if (rank < c2.rank) return true;
    // if the ranks are also equal, return false
    return false;
}
