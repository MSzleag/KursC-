#include "UI.h"

void UI::PrintWelcomeMessage() const {
	std::cout << "Witamy w Pokerze!" << std::endl;
	std::cout << "Zaczynajmy!" << std::endl;
}

void UI::AskForNames(std::string& playerName1, std::string& playerName2) const {
	std::cout << "Podaj imie pierwszego gracza: ";
	std::getline(std::cin, playerName1);
	std::cout << "Podaj imie drugiego gracza: ";
	std::getline(std::cin, playerName2);
}

void UI::RenderPlayersTurn(Player& player) {
	std::cout << std::endl;
	std::cout << "Teraz tura gracza: " << player.GetName() << std::endl;
	std::cout << "Twoja reka: " << std::endl;
	player.GetHand().PrintHand();
	UI::PrintMenu();
}

void UI::PrintMenu() const { //Mozliwa rozbudowa o podbijanie stawki, sprawdzanie itp. Niestety zabrak³o mi czasu.
	std::cout << std::endl;
	std::cout << "Menu:" << std::endl;
	std::cout << "1. Wymien karte" << std::endl;
	std::cout << "2. Nie zmieniaj kart" << std::endl;
	std::cout << "3. Poddaj Sie" << std::endl;
}

void UI::PrintWinner(const Player& player) const{
	std::cout << "Zwyciesca jest: " << player.GetName() << std::endl;
	std::cout << "Dziekuje za gre" << std::endl;
}

void UI::PrintBothHands(const Player& player1, const Player& player2) {
	std::cout << "Reka gracza " << player1.GetName() << std::endl;
	player1.GetHand().PrintHand();
	std::cout << std::endl;
	std::cout << "Reka gracza " << player2.GetName() << std::endl;
	player2.GetHand().PrintHand();
	std::cout << std::endl;

	int player1Value = player1.GetHand().GetHandValue();
	int player2Value = player2.GetHand().GetHandValue();
	std::cout << player1.GetName() << " Ma na rece: " << player1Value << std::endl;
	std::cout << player2.GetName() << " Ma na rece: " << player2Value << std::endl;
}