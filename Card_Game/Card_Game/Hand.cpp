#include "Hand.h"
#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

Hand::Hand(Deck& deck)
{
	Inialize(deck);
}

void Hand::Inialize(Deck &deck) {
	for (int i = 0;i < 5; i++) {
		h_cards[i] = deck.DealCard();
	}
	sortHand();

}

void Hand::SwapCard(Deck& deck,int position) {
	h_cards[position] = deck.DealCard();
	sortHand();
}
int Hand::GetHandValue() const {
	if (is_RoyalFlush()) {
		return 10;
	} else if (is_StraightFlush()) {
		return 9;
	} else if (is_FourOfAKind()) {
		return 8;
	} else if (is_FullHouse()) {
		return 7;
	} else if (is_Flush()) {
		return 6;
	} else if (is_Straight()) {
		return 5;
	} else if (is_ThreeOfAKind()) {
		return 4;
	} else if (is_TwoPair()) {
		return 3;
	} else if (is_OnePair()) {
		return 2;
	} else if (is_HighCard()) {
		return 1;
	}
	return 0; 
}
void Hand::sortHand() {
	std::sort(h_cards, h_cards + 5, [](const Card& a, const Card& b) {
		return a.value < b.value;
	});
}
void Hand::PrintHand() const {  
    for (int i = 0; i < 5; ++i) {  
		std::cout << h_cards[i].toString() << std::endl;
    }  
}
bool Hand::is_RoyalFlush() const {
	int counter = 0;
	if (h_cards[0].value == Value::Ten && h_cards[1].value == Value::Jack &&
		h_cards[2].value == Value::Queen && h_cards[3].value == Value::King &&
		h_cards[4].value == Value::Ace && is_Flush()) {
			return true;
		}
	return false;
}

bool Hand::is_StraightFlush() const {
	if (is_Straight() && is_Flush()) {
		return true;
	}
	return false;
}
bool Hand::is_FourOfAKind() const {
	for (int i = 0; i < 5; ++i) {
		int count = 0;
		for (int j = 0; j < 5; ++j) {
			if (h_cards[i].value == h_cards[j].value) {
				count++;
			}
		}
		if (count == 4) {
			return true;
		}
	}
	return false;
}
bool Hand::is_FullHouse() const {
	return (is_ThreeOfAKind() && is_OnePair());
}
bool Hand::is_Flush() const {
	for (int i = 1; i < 5; ++i) {
		if (h_cards[i].color != h_cards[0].color) {
			return false;
		}
	}
	return true;
}
bool Hand::is_Straight() const {  
    for (int i = 1; i < 5; ++i) {  
        if (static_cast<int>(h_cards[i].value) != (static_cast<int>(h_cards[i-1].value) + 1)) {  
            return false;  
        }  
    }  
    return true;  
}
bool Hand::is_ThreeOfAKind() const {
	for (int i = 0; i < 5; ++i) {
		int count = 0;
		for (int j = 0; j < 5; ++j) {
			if (h_cards[i].value == h_cards[j].value) {
				count++;
			}
		}
		if (count == 3) {
			return true;
		}
	}
	return false;
}
bool Hand::is_TwoPair() const {
	int pairCount = 0;
	for (int i = 0; i < 5; ++i) {
		int count = 0;
		for (int j = 0; j < 5; ++j) {
			if (h_cards[i].value == h_cards[j].value) {
				count++;
			}
		}
		if (count == 2) {
			pairCount++;
			i++; // Skip the next card to avoid counting the same pair again
		}
	}
	return pairCount == 2;
}
bool Hand::is_OnePair() const {
	for (int i = 0; i < 5; ++i) {
		int count = 0;
		for (int j = 0; j < 5; ++j) {
			if (h_cards[i].value == h_cards[j].value) {
				count++;
			}
		}
		if (count == 2) {
			return true;
		}
	}
	return false;
}
bool Hand::is_HighCard() const {
	return !is_RoyalFlush() && !is_StraightFlush() && !is_FourOfAKind() &&
		!is_FullHouse() && !is_Flush() && !is_Straight() &&
		!is_ThreeOfAKind() && !is_TwoPair() && !is_OnePair();
}

int Hand::getHighCard() const {
	int highCardValue = static_cast<int>(h_cards[4].value);
	return highCardValue;
}

