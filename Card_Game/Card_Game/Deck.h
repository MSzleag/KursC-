#pragma once

#include "Card.h"

class Deck
{
public:
	Deck();

	void Inialize();
	void Shuffle();
	Card Deal();
	Card DealCard();

private:
	Card m_cards[52];
	int m_card_position;
};

