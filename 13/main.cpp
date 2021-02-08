#include <iostream>

#include "cards.hpp"
#include "deck.hpp"
using namespace std;
int findBisect(const Card& card, const vector<Card>& deck, int low, int high) {
    cout << low << ", " << high << endl;
    if (high < low) return -1;
    int mid = (high + low) / 2;
    if (card.equals(deck[mid])) return mid;
    if (deck[mid].isGreater(card)) {
        return findBisect(card, deck, low, mid - 1);
    } else {
        return findBisect(card, deck, mid + 1, high);
    }
}
int findBisectSub(const Card& card, const Deck& subdeck) {
    /* :shrug: */
    return 0;
}
/* skipping 13.8 and 13.10 exercises */
int main() {
    Deck deck;
    deck.shuffle();
    deck.sort();
    deck.printDeck();
    return 0;
}
