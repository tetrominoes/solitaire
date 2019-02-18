//Class to represent a card object.
#include "card.h"
#include <iostream>
using namespace std;



    int cardValue;
    char suit;
    bool color;
    bool faceUp;
    
    //Card object, which represents a standard playing card in a deck. There are 52 cards (minues jokers) for the game of Solitaire.
    
     card::card(int aCardValue, char aSuit, bool aColor){
        cardValue = aCardValue;
        suit = aSuit;
        color = aColor;
        faceUp = false;
    }
        //method printCard: Prints all card attribute information to output.
        void printCard(){
            cout<<"Card: " << color<< "-" << suit << "-"<< cardValue<< "-"<< faceUp<<"\n";
        }
        //method getSuit: returns the char representing the suit of the card.
        char getSuit(){
            return suit;
        }
        //method setSuit: sets a char to represent the suit of the card.
        void setSuit(char newSuit){
            suit = newSuit;
        }
        //method getColor: returns a bool representing the color of the card.
        char getColor(){
            return color;
        }
        //method setColor: sets a bool to represent the color of the card.
        void setColor(char newColor){
            color = newColor;
        }
        //method getCardValue: returns an int representing the value of the card.
        int getCardValue(){
            return cardValue;
        }
        //method setCardValue: sets an int to represent the value of the card.
        void setCardValue(int newCardValue){
            cardValue = newCardValue;
        }
        bool isFaceUp(){
            return faceUp;
        }
        void flip(){
            faceUp = !faceUp;
        }
        

