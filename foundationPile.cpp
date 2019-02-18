//Class to represent a Foundationpile.
#include <iostream>
#include "pile.h"
#include <vector>
using namespace std;

class foundationPile: public pile{


   int initSize;
   vector<card> cards;
//Foundationpile Method
foundationPile(){
}


public:
//bool canReceive: determines if the foundation can recieve current card
bool canReceieve(card currentCard,pile foundpile){
    //if foundation is empty, and card is an ace
    if (foundpile.empty() && (currentCard.getCardValue() == 1)){
        return true;
    }
    //current card is the same suit, and 1 more than the previous top card
    else if((currentCard.getSuit() == foundpile.topCard().getSuit()) && (currentCard.getCardValue() == (foundpile.topCard().getCardValue() + 1))){
        return true;
    }
    return false;
}

vector<card> getCards(){
    return cards;
}
};