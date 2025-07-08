#include "Game.h"
#include <stdlib.h>

Game::Game() {
	
	Game::Start();
	while (!m_end) {//Game Loop
		Input();
		Update();	
		Render();
	}
	
}
void Game::Start() {
	m_deck.Inialize();
	m_deck.Shuffle();

	m_ui.PrintWelcomeMessage();
	m_ui.AskForNames(m_playerName1, m_playerName2);

	m_player1 = Player(m_playerName1, m_deck);
	m_player2 = Player(m_playerName2, m_deck);

	currentPlayer = m_player1;
	system("CLS");
	m_ui.RenderPlayersTurn(currentPlayer);
}

Player Game::EvaluateWinner(Player& player1, Player& player2) {
	int player1Value = player1.GetHand().GetHandValue();
	int player2Value = player2.GetHand().GetHandValue();
	m_end = true; // Koniec gry, po zwyciêzcê
	if (player1Value > player2Value) {
		return player1;
	}
	else if (player1Value < player2Value) {
		return player2;
	}
	else { 
		Player tie("Remis");
		switch (player1Value) {
		case 10: return tie; // remis przy takim uk³adzie u obydwu graczy (Poker Królewski)
		case 9://Poker
			if (player1.GetHand().getHighCard() > player2.GetHand().getHighCard()) {
				return player1;
			}
			else if (player1.GetHand().getHighCard() < player2.GetHand().getHighCard()) {
				return player2;
			}
			return tie;
		case 8: { //Czworka
			if (player1.GetHand().GetPair() > player2.GetHand().GetPair()) {
				return player1;
			}
			else {
				return player2;
			}
		}
		case 7: { //Ful
			if (player1.GetHand().GetThreeOfAKind() > player2.GetHand().GetThreeOfAKind()) {
				return player1;
			}
			else {
				return player2;
			}
		}
		case 6: { //Kolor
			if (player1.GetHand().getHighCard() > player2.GetHand().getHighCard()) {
				return player1;
			}
			else if (player1.GetHand().getHighCard() < player2.GetHand().getHighCard()) {
				return player2;
			}
			return tie;
		}
		case 5: { //Strit
			if (player1.GetHand().getHighCard() > player2.GetHand().getHighCard()) {
				return player1;
			}
			else if (player1.GetHand().getHighCard() < player2.GetHand().getHighCard()) {
				return player2;
			}
			return tie;
		}
		case 4: { //Trójka
			if (player1.GetHand().GetThreeOfAKind() > player2.GetHand().GetThreeOfAKind()) {
				return player1;
			}
			else if (player1.GetHand().GetThreeOfAKind() < player2.GetHand().GetThreeOfAKind()) {
				return player2;
			}
		}
		case 3: { //Dwie pary
			if (player1.GetHand().GetPair() > player2.GetHand().GetPair()) {
				return player1;
			}
			else if (player1.GetHand().GetPair() < player2.GetHand().GetPair()) {
				return player2;
			}
			return tie;
		}
		case 2: { //Para
			if (player1.GetHand().GetPair() > player2.GetHand().GetPair()) {
				return player1;
			}
			else if (player1.GetHand().GetPair() < player2.GetHand().GetPair()) {
				return player2;
			}
			return tie;
		}
		case 1: { // karta
			if (player1.GetHand().getHighCard() > player2.GetHand().getHighCard()) {
				return player1;
			}
			else if (player1.GetHand().getHighCard() < player2.GetHand().getHighCard()) {
				return player2;
			}
			return tie;
		}
		default:
			return tie;
		}
	}
}

void Game::MenuExchange(Player& player) {
	int amount;
	int positions[5] = { 0, 0, 0, 0, 0 }; // Pozycje kart od 0 do 4
	std::cout << "Podaj iloœæ kart do wymiany (1-4): ";
	std::cin >> amount;
	if (amount < 1 || amount > 4) {
		std::cout << "Nieprawid³owa iloœæ kart do wymiany." << std::endl;
		return;
	}
	for (int i = 0; i < amount; ++i) {
		std::cout << "Podaj pozycje karty do wymiany (1-5): ";
		std::cin >> positions[i];
		if (positions[i] != 0 && positions[i] != positions[i-1]) {
			if ((positions[i] - 1) >= 0 && (positions[i] - 1) < 5) {
				player.SwapCard(m_deck, positions[i] - 1);
			}
			else {
				std::cout << "Nieprawid³owa pozycja karty." << std::endl;
				MenuExchange(player);
			}
		}
	}
	player.SortHand();
	player.GetHand().PrintHand();
	system("pause");
}

void Game::Input() {
	int choice = 0;
	std::cout << "Wybierz opcje: ";
	std::cin >> choice;
	if (choice == 1) {
		if (currentPlayer.GetName() == m_player1.GetName())
			MenuExchange(m_player1);
		else
			MenuExchange(m_player2);
	}
	else if (choice == 2 || choice == 3) {
		m_choice = choice;
	}
	else {
		std::cout << "Nieprawid³owy wybór. Spróbuj ponownie." << std::endl;
	}
}
void Game::Update() {
	if (m_choice == 3) {
		m_end = true;
		if (currentPlayer.GetName() == m_player1.GetName())
			currentPlayer = m_player2;
		else
			currentPlayer = m_player1;
	}
	else {
		if (currentPlayer.GetName() == m_player1.GetName()) {
			currentPlayer = m_player2;
		}
		else {
			m_end = true;
			currentPlayer = EvaluateWinner(m_player1, m_player2);
		}
	}

	system("CLS");

}
void Game::Render() {

	if (m_end) {
		m_ui.PrintBothHands(m_player1, m_player2);
		m_ui.PrintWinner(currentPlayer);
	}
	else {
		m_ui.RenderPlayersTurn(currentPlayer);
	}
		
}


