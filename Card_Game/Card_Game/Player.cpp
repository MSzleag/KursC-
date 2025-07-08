#include "Player.h"

Player::Player() : m_name(""), m_hand() {
}
Player::Player(const std::string& name)
	: m_name(name), m_hand() {
}

Player::Player(const std::string& name, Deck& deck)
	: m_name(name), m_hand(deck) {
}

std::string Player::GetName() const {
	return m_name;
}
const Hand& Player::GetHand() const {
	return m_hand;
}

void Player::SwapCard(Deck& deck, int position) {
	m_hand.SwapCard(deck, position);
}
void Player::SortHand() {
	m_hand.SortHand();
}
