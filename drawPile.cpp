//Class to represent the Draw pile in solitaire.
//Once a card needs to be taken off the stock, it gets placed on the draw pile, a seperate pile of faceUp cards, where the top card can be accessed and move to Tableau or Foundation.


#include <iostream>
#include "pile.h"
#include <vector>
using namespace std;

class drawPile : public pile{
private:
pile theDrawPile;
int initSize = 0;

public:
//DrawPile Method
drawPile(int value){
    theDrawPile.empty() == true;
}

//void placeCard(pile placementPile){
    //placementPile.push(theDrawPile.pop());
    //}


};