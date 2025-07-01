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
	cout << "Pierwsza reka:" << endl;
    hand.PrintHand();
    cout << "Uklad: " << hand.GetHandValue();
	cout << "Druga reka:" << endl;
	secondHand.PrintHand();
    cout << "Uklad: " << secondHand.GetHandValue();

    int position = 0; // Initialize the variable to fix lnt-uninitialized-local error  
    cout << "Ktora:";  
    cin >> position;  

    hand.SwapCard(deck, position);  
	hand.PrintHand();
	cout << "Uklad: " << hand.GetHandValue();

    return 0;  
}
