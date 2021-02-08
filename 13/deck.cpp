#include "deck.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
Deck::Deck(int size) {
    vector<Card> temp(size);
    cards = temp;
}
Deck::Deck() {
    vector<Card> temp(52);
    cards = temp;
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit + 1)) {
        for (Rank rank = ACE; rank <= KING; rank = Rank(rank + 1)) {
            cards[i].suit = suit;
            cards[i].rank = rank;
            i++;
        }
    }
}
void Deck::printDeck() const {
    for (int i = 0; i < 52; i++) {
        cards[i].print();
    }
}
int Deck::find(const Card &card) const {
    for (int i = 0; i < 52; i++) {
        if (card.Card::equals(cards[i])) return i;
    }
    return -1;
}
int randomInt(const int &low, const int &high) {
    int partial = rand();
    while ((partial % high) < low) {
        partial = (rand() % high);
    }
    int result = partial % high;
    return result;
}
void swapCards(Card *card1, Card *card2) {
    Card temp = *card1;
    *card1 = *card2;
    *card2 = temp;
}
void Deck::shuffle() {
    srand((unsigned)time(0));
    for (int i = 0; i < 52; i++) {
        // choose a random number between i and cards.length()
        int j = randomInt(i, 52);
        // swap the ith card and the randomly-chosen card
        swapCards(&cards[i], &cards[j]);
    }
}
Card *Deck::findLowestCard(const int &index) {
    Card *_lowest = &cards[index];
    for (int j = index + 1; j < 52; j++) {
        if (!cards[j].isGreater(*_lowest)) {
            _lowest = &cards[j];
        }
    }
    return _lowest;
}
void Deck::sort() {
    for (int i = 0; i < 52; i++) {
        // find the lowest card at or to the right of i
        Card *lowest = findLowestCard(i);
        // swap the ith card and the lowest card
        swapCards(&cards[i], lowest);
    }
}
Deck Deck::subdeck(int low, int high) const {
    Deck sub(high - low + 1);
    for (int i = 0; i < high - low + 1; i++) {
        sub.cards[i] = cards[low + i];
    }
    return sub;
}
