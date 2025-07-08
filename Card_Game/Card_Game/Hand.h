#pragma once
#include "Deck.h"

class Hand
{
public:
    Hand();
	Hand(Deck &deck);

	void Inialize(Deck &deck);
	void SwapCard(Deck &deck,int position);
	int GetHandValue() const;
	void PrintHand() const;
    int GetPair() const;
	int GetThreeOfAKind() const;
    int getHighCard() const;
    void SortHand();

    private:
        int static const amountInHand = 5;
		Card m_cards[amountInHand];
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


};

