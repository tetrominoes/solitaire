//Class to represent the Draw pile in solitaire.
//Once a card needs to be taken off the stock, it gets placed on the draw pile, a seperate pile of faceUp cards, where the top card can be accessed and move to Tableau or Foundation.


#include <iostream>
#include "Pile.cpp"
#include <vector>
using namespace std;

class DrawPile{
private:
Pile drawPile;
int initSize = 0;

public:
//DrawPile Method
DrawPile(int value){
    drawPile.empty() == true;
}

void placeCard(Pile placementPile){
    placementPile.push(drawPile.pop());
    }


};