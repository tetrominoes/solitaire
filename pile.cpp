/**
    pile.cpp
    Purpose: Represent a pile object

    @author tetrominoes
    @version 1.0 Feb. 2019
*/

#include <iostream>
#include "card.h"
#include "pile.h"
#include <vector>

using namespace std;

vector<card> cards;

/**
     * deck::deck()
     * Establish each card in the deck.
     * 
 */
pile::pile(){
 }
 
  /**
     * push()
     * Push a card to the pile
     * 
     *@param card addCard: the card to push
 */
void pile::push(card newCard){
    cards.push_back(newCard);
}

 /**
     * topCard()
     * Return the top card of the pile
     * 
     *@return card: the card at the top of the pile
 */

card pile::topCard(){
    return cards.at(cards.size()-1);
}

 /**
     * empty()
     * Returns a bool to see if the pile is empty
     * 
     *@return bool: true if pile is empty
 */

bool pile::empty(){
    if(cards.size()==0)
        return true;
    else
        return false;
}

/**
     * getCards()
     * Returns the cards in the pile
     * 

     * @return vector<card> cards: the vector of cards representing the pile
 */

vector<card> pile::getCards(){
    return cards;
}


