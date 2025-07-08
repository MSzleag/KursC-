#pragma once
#include <iostream>
#include "Hand.h"

class Player
{
public:
	Player();
	Player(const std::string& name);
	Player(const std::string& name, Deck& deck);
	
	void SwapCard(Deck& deck, int position);
	std::string GetName() const;
	const Hand& GetHand() const;
	void SortHand();
private:
	std::string m_name;
	Hand m_hand;
};

