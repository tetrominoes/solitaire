//Class to represent a Foundationpile.
#include <iostream>
#include "pile.h"
#include <vector>
#include "foundationPile.h"
using namespace std;


   int initSize;
   vector<card> singleFoundation;
//Foundationpile constructor
    foundationPile::foundationPile(){
        }


//bool canReceive: determines if the foundation can recieve current card
bool foundationPile::canReceieve(card currentCard){
    //if foundation is empty, and card is an ace
    if (singleFoundation.empty() && (currentCard.getCardValue() == 1)){
        return true;
    }
    //current card is the same suit, and 1 more than the previous top card
    else if((currentCard.getSuit() == singleFoundation.front().getSuit()) && 
    (currentCard.getCardValue() == (singleFoundation.front().getCardValue() + 1))){
        return true;
    }
    return false;
}

vector<card> & foundationPile::getCards(){
    return singleFoundation;
}