#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

Deck::Deck()
{
	Inialize();
}

void Deck::Inialize()
{
	int cardsCounter = 0;
	for (int i = 0; i < (int)Color::Size; ++i)
	{
		for (int j = 0; j < (int)Value::Size; ++j)
		{
			m_cards[cardsCounter].color = (Color)i;
			m_cards[cardsCounter].value = (Value)j;

			cardsCounter++;
		}
	}
	m_card_position = 0;
}

void Deck::Shuffle()
{
	srand(time(0));

	const int size = (int)Color::Size * (int)Value::Size;
	for (int i = 0; i < size; ++i)
	{
		int randomIndex = rand()% size;
		std::swap(m_cards[i], m_cards[randomIndex]);
	}
}

Card Deck::DealCard() {
	Card firstCard;
	firstCard.color = m_cards[m_card_position].color;
	firstCard.value = m_cards[m_card_position].value;

	m_card_position++;

	return firstCard;
}

Card Deck::Deal()
{
	return Card();
}
