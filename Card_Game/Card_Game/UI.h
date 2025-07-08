#pragma once
#include <iostream>
#include "Player.h"
class UI
{
public:
	void PrintWelcomeMessage() const;
	void AskForNames(std::string& playerName1, std::string& playerName2) const;
	
	void RenderPlayersTurn(Player& player);
	void PrintMenu() const;
	void PrintWinner(const Player& player) const;
	void PrintBothHands(const Player& player1, const Player& player2);

};
