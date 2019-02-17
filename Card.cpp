//Class to represent a card object.
#include <iostream>
#include "Card.h"
using namespace std;

//Card object, which represents a standard playing card in a deck. There are 50 cards (minues jokers) for the game of Solitaire.
 Card::Card(int aCardValue, char aSuit, bool aColor, bool aFaceUp){
    cardValue = aCardValue;
    suit = aSuit;
    color = aColor;
    faceUp = aFaceUp;
}
    //method printCard: Prints all card attribute information to output.
    void Card::printCard(){
        cout<<"Card: " << color<< "-" << suit << "-"<< cardValue<< "-"<< faceUp<<"\n";
    }
    //method getSuit: returns the char representing the suit of the card.
    char Card::getSuit(){
        return this->suit;
    }
    //method setSuit: sets a char to represent the suit of the card.
    void Card::setSuit(char suit){
        this->suit = suit;
    };
    //method getColor: returns a bool representing the color of the card.
    char Card::getColor(){
        return this->color;
    }
    //method setColor: sets a bool to represent the color of the card.
    void Card::setColor(char color){
        this->color = color;
    }
    //method getCardValue: returns an int representing the value of the card.
    int Card::getCardValue(){
        return this->cardValue;
    }
    //method setCardValue: sets an int to represent the value of the card.
    void Card::setCardValue(int cardValue){
        this->cardValue = cardValue;
    }
    bool Card::isFaceUp(){
        return faceUp;
    }
    void Card::flip(){
        faceUp = !faceUp;
    }
}

