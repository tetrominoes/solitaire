
//Class to represent the Tableau pile in solitaire.


#include <iostream>
#include "pile.h"
#include <vector>
#include "tableau.h"
using namespace std;




    pile singlePile;

    vector<card> cardB;

    tableau::tableau(){
        
    }

    bool tableau::canRecieve(card aCard){
        if(singlePile.empty()){
            return (aCard.getCardValue() == 13);
        }
        return (aCard.getColor() != singlePile.topCard().getColor()) && 
        (aCard.getCardValue() == singlePile.topCard().getCardValue()-1);

    }
    vector<card> tableau::getCards(){
        return cardB;
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
