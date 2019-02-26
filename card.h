// Card.h
// #ifndef __CARD_H_INCLUDED__
// #define __CARD_H_INCLUDED__
#pragma once

class card{
    
    public: 
     int cardValue;
     char suit;
     bool color;
     bool faceUp;
     card(int cardValue, char suit, bool color);
        void printCard();
    //method getSuit: returns the char representing the suit of the card.
        char getSuit();
    //method setSuit: sets a char to represent the suit of the card.
        void setSuit(char suit);
    //method getColor: returns a bool representing the color of the card.
        char getColor();
    //method setColor: sets a bool to represent the color of the card.
        void setColor(char color);
    //method getCardValue: returns an int representing the value of the card.
        int getCardValue();
    //method setCardValue: sets an int to represent the value of the card.
        void setCardValue(int newCardValue);
        bool isFaceUp();
        void flip();
        char getFaceUp();
};
