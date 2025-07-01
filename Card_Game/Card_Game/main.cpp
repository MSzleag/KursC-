#include <iostream>
#include "Deck.h"
#include "Hand.h"


using namespace std;



int main()
{
	Deck deck;
	deck.Shuffle();  
	Hand hand(deck);
	Hand secondHand(deck);

	int position;
	cout << "Ktora:";
	cin >> position;

	hand.SwapCard(deck, position);

	return 0;
}

