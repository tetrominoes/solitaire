//Class to represent a FoundationPile.
#include <iostream>
#include "Pile.cpp"
#include <vector>
using namespace std;

class FoundationPile : public Pile{
private:
   Pile foundPile;
   int initSize = 0;
public:
//FoundationPile Method
FoundationPile(int value){
    //foundPile.empty() == true;
}

//bool canReceive: determines if the foundation can recieve current card
bool canReceieve(Card currentCard){
    //if foundation is empty, and card is an ace
    if (foundPile.empty() && (currentCard.getCardValue() == 1)){
        return true;
    }
    //current card is the same suit, and 1 more than the previous top card
    else if((currentCard.getSuit() == foundPile.topCard().getSuit()) && (currentCard.getCardValue() == (foundPile.topCard().getCardValue() + 1))){
        return true;
    }
    return false;
}

};