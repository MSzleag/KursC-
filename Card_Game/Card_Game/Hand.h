#pragma once
#include "Deck.h"

class Hand
{
public:
	Hand(Deck &deck);

	void Inialize(Deck &deck);
	void SwapCard(Deck& deck,int position);

private:
	Card h_cards[5];
};

