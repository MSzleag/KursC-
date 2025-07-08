#include "Hand.h"
#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

Hand::Hand() {};

Hand::Hand(Deck& deck)
{
	Inialize(deck);
}

void Hand::Inialize(Deck &deck) {
	for (int i = 0;i < amountInHand; i++) {
		m_cards[i] = deck.DealCard();
	}
	SortHand();
}

void Hand::SwapCard(Deck& deck,int position) {
	m_cards[position] = deck.DealCard();
}
int Hand::GetHandValue() const {// Mozna rozbudowac o strukture ukladow
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
void Hand::SortHand() {
	std::sort(m_cards, m_cards + amountInHand, [](const Card& a, const Card& b) {
		return a.value < b.value;
	});
}
void Hand::PrintHand() const {  
    for (int i = 0; i < amountInHand; ++i) {
		std::cout << m_cards[i].toString() << std::endl;
    }  
}
bool Hand::is_RoyalFlush() const {
	int counter = 0;
	if (m_cards[0].value == Value::Ten && m_cards[1].value == Value::Jack &&
		m_cards[2].value == Value::Queen && m_cards[3].value == Value::King &&
		m_cards[4].value == Value::Ace && is_Flush()) {
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
	for (int i = 0; i < amountInHand; ++i) {
		int count = 0;
		for (int j = 0; j < amountInHand; ++j) {
			if (m_cards[i].value == m_cards[j].value) {
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
	for (int i = 1; i < amountInHand; ++i) {
		if (m_cards[i].color != m_cards[0].color) {
			return false;
		}
	}
	return true;
}
bool Hand::is_Straight() const {  
    for (int i = 1; i < amountInHand; ++i) {
        if (static_cast<int>(m_cards[i].value) != (static_cast<int>(m_cards[i-1].value) + 1)) {  
            return false;  
        }  
    }  
    return true;  
}
bool Hand::is_ThreeOfAKind() const {
	for (int i = 0; i < amountInHand; ++i) {
		int count = 0;
		for (int j = 0; j < amountInHand; ++j) {
			if (m_cards[i].value == m_cards[j].value) {
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
	for (int i = 0; i < amountInHand; ++i) {
		int count = 0;
		for (int j = 0; j < amountInHand; ++j) {
			if (m_cards[i].value == m_cards[j].value) {
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
	for (int i = 0; i < amountInHand; ++i) {
		int count = 0;
		for (int j = 0; j < amountInHand; ++j) {
			if (m_cards[i].value == m_cards[j].value) {
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
	int highCardValue = static_cast<int>(m_cards[4].value);
	return highCardValue;
}
int Hand::GetPair() const {
	int biggerPair = 0;
	for (int i = 0; i < amountInHand; ++i) {
		int count = 0;
		for (int j = 0; j < amountInHand; ++j) {
			if (m_cards[i].value == m_cards[j].value) {
				count++;
			}
		}
		if (count == 2) {
			if(static_cast<int>(m_cards[i].value) > biggerPair)
				biggerPair = static_cast<int>(m_cards[i].value);
			break;
		}
	}
	return biggerPair;
}
int Hand::GetThreeOfAKind() const {
	for (int i = 0; i < amountInHand; ++i) {
		int count = 0;
		for (int j = 0; j < amountInHand; ++j) {
			if (m_cards[i].value == m_cards[j].value) {
				count++;
			}
		}
		if (count == 3) {
			return static_cast<int>(m_cards[i].value);
		}
	}
	return -1;
}	

