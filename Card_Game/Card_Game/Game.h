#pragma once
#include "Deck.h"
#include "Player.h"
#include "UI.h"
class Game
{
public:
	Game();
	
	void Start();
	Player EvaluateWinner(Player& player1, Player& player2);
	void MenuExchange(Player& player);

private:  
    int m_choice = 0;
	Player currentPlayer;
	Player m_player1;
	Player m_player2;
	UI m_ui;
	Deck m_deck;
	std::string m_playerName1, m_playerName2;
	bool m_end = false;
	void Input();
	void Update();
	void Render();
};

