#pragma once
#include "Deck.h"

class Hand
{
public:
	Hand(Deck &deck);

	void Inialize(Deck &deck);
	void SwapCard(Deck &deck,int position);
	int GetHandValue() const;
	void PrintHand() const;

    private:
		Card h_cards[5];
		bool is_RoyalFlush() const;
        bool is_StraightFlush() const;
        bool is_FourOfAKind() const;
        bool is_FullHouse() const;
        bool is_Flush() const;
        bool is_Straight() const;
        bool is_ThreeOfAKind() const;
        bool is_TwoPair() const;
        bool is_OnePair() const;
        bool is_HighCard() const;
		int getHighCard() const;

		void sortHand();
};

