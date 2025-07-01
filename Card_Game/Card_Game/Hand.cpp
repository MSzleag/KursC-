#include "Hand.h"
#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

Hand::Hand(Deck& deck)
{
	Inialize(deck);
}

void Hand::Inialize(Deck& deck) {
	for (int i = 0;i < 5; i++) {
		h_cards[i] = deck.DealCard();
	}

}

void Hand::SwapCard(Deck& deck,int position) {
	h_cards[position] = deck.DealCard();
}

