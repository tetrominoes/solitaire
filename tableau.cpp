
//Class to represent the Tableau pile in solitaire.


#include <iostream>
#include "pile.h"
#include <vector>
#include "tableau.h"
using namespace std;



    //being to phase out pile
    //pile singlePile;

    vector<card> singleTableau;

    tableau::tableau(){
        
    }

    bool tableau::canRecieve(card potentialCard){
        if(singleTableau.empty()){
            return (potentialCard.getCardValue() == 13);
        }
        return (potentialCard.getColor() != singleTableau.front().getColor()) && 
        (potentialCard.getCardValue() == singleTableau.front().getCardValue()-1);

    }
    vector<card> & tableau::getCards(){
        return singleTableau;
    }
    int tableau::topOfTableau(){
        for(int t = 0; t < singleTableau.size(); ++t){
            if(singleTableau.at(t).isFaceUp()){
                return t;
            }
        }
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
