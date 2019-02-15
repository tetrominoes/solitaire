//Class to represent a FoundationPile.
#include <iostream>
#include "Pile.cpp"
#include <vector>
using namespace std;

class FoundationPile{
private:
   Pile foundPile;
   int initSize =0;
public:
//FoundationPile Method
FoundationPile(int value){
    foundPile.empty = true;
}

//bool canReceive: determines if the foundation can recieve current card
bool canReceieve(card currentCard){
    //if foundation is empty, and card is an ace
    if (foundPile.empty() && (currentcard.getCardValue = 1)){
        return true;
    }
    //current card is the same suit, and 1 more than the previous top card
    else if((currentcard.getSuit() = foundPile.topCard.getSuit()) && (currentcard.getValue() = (topCard.getValue() + 1))){
        return true;
    }
    return false;
}

}