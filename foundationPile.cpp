/**
    foundationPile.cpp
    Purpose: Represents a foundation pile of cards. The foundation pile is ordered Ace to King, and when all cards are placed here in order, a game is won.

    @author tetrominoes
    @version 1.0 Feb. 2019
*/

#include <iostream>
#include "pile.h"
#include <vector>
#include "foundationPile.h"
using namespace std;


   int initSize;
   vector<card> singleFoundation;
/**
     * foundationPile()
     * Establish the foundationPile
 */
 
    foundationPile::foundationPile(){
        }

/**
     * canRecieve()
     * Method to determine if the foundation pile can recieve a given card
     * 
     * @param card currentCard: the card to be recieved
     * @param pile foundpile: the given foundation pile to recieve a card
     * @return bool true if card can be recieved
 */
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

/**
     * getCards()
     * Returns the cards in the foundation pile
     * 

     * @return vector<card> cardC: the vector of cards representing the pile
 */
vector<card> & foundationPile::getCards(){
    return singleFoundation;
}
