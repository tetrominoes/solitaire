/**
    tableau.cpp
    Purpose: Represent a tableau of cards: The tableau is the "playing space" of the Solitaire game

    @author tetrominoes
    @version 1.0 Feb. 2019
*/
#include <iostream>
//#include "pile.h"
#include <vector>
#include "tableau.h"
#include "card.h"
using namespace std;
    //being to phase out pile
    //pile singlePile;

    vector<card> singleTableau;

/**
     * tableau::tableau()
     * Establish the tableau of cards
     * 
 */
    tableau::tableau(){
        
    }

/**
     * canRecieve()
     * Method to determine if the tableau pile can recieve a given card
     * 
     * @param card potentialCard: the card to be recieved

     * @return bool true if card can be recieved
 */
    bool tableau::canRecieve(card potentialCard){
        if(singleTableau.empty()){
            return (potentialCard.getCardValue() == 13);
        }
        return (potentialCard.getColor() != singleTableau.front().getColor()) && 
        (potentialCard.getCardValue() == singleTableau.front().getCardValue()-1);

    }
    
/**
     * getCards()
     * Returns the cards in the tableau pile
     * 

     * @return vector<card> singleTableau: the vector of cards representing the pile
 */    
    vector<card> & tableau::getCards(){
        return singleTableau;
    }
    
/**
     * topOfTableau()
     * Return the index of the card at athe topof the tableau
     * 

     * @return int t
 */    
    int tableau::topOfTableau(){
        for(int t = 0; t < singleTableau.size(); t++){
            if(singleTableau.at(t).isFaceUp()){
                 return t;
             }
        }
        return -50;
        
    }
    
    // void placeCard(){
    //     if(pile.empty()){
    //         return;
    //     }
    //     Card topCard = pile.topCard();
    //     if(!topCard.isFaceUp()){
    //         topCard.flip();
    //         return;
    //     }
    //     topCard = pile.pop();
    //     for (int i = 0; i <4; i++){
    //         if(Solitaire.FoundationPile(i).canRecieve(topCard)){
    //             Solitaire.FoundationPile(i).push(topCard);
    //             return;
    //         }
    //     }
    //     for (int i =0; i <7; i++){
    //         if (Solitaire.tableau(i).canReceive(topCard)){
    //             Solitaire.tableau(i).push(topCard);
    //             return;
    //         }
    //     }
    //     push(topCard);
    // }
