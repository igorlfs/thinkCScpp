#include "cards.hpp"

#include <iostream>
using namespace std;
Card::Card() {
    suit = 0;
    rank = 0;
}
Card::Card(int s, int r) {
    suit = s;
    rank = r;
}
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
bool equals(const Card& c1, const Card& c2) {
    return (c1.rank == c2.rank && c1.suit == c2.suit);
}
int find(const Card& card, const vector<Card>& deck) {
    for (int i = 0; i < 52; i++) {
        if (equals(deck[i], card)) return i;
    }
    return -1;
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
vector<Card> Card::buildDeck() {
    vector<Card> deck(52);
    int i = 0;
    for (int suit = 0; suit <= 3; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            i++;
        }
    }
    return deck;
}
bool equals(const Card& c1, const Card& c2) {
    return (c1.rank == c2.rank && c1.suit == c2.suit);
}
void printDeck(const vector<Card>& deck) {
    for (int i = 0; i < 52; i++) {
        deck[i].print();
    }
}
int findBisect(const Card& card, const vector<Card>& deck, int low, int high) {
    cout << low << ", " << high << endl;
    if (high < low) return -1;
    int mid = (high + low) / 2;
    if (equals(deck[mid], card)) return mid;
    if (deck[mid].isGreater(card)) {
        return findBisect(card, deck, low, mid - 1);
    } else {
        return findBisect(card, deck, mid + 1, high);
    }
}
