/**
    card.cpp
    Purpose: Represent a card object

    @author tetrominoes
    @version 1.0 Feb. 2019
*/

#include "card.h"
#include <iostream>
using namespace std;



    int cardValue;
    char suit;
    bool color;
    //TRUE = BLACK
    //FALSE = RED
    bool faceUp;
    
/**
   card:::card(int aCardValue, char aSuit, bool aColor)
 * Create a new card object.
 * 
 * @param int aCardValue: face value of the card
 * @param char aSuit: suit of the card
 * @param bool aColor: bool value of the card color
*/
    
     card::card(int aCardValue, char aSuit, bool aColor){
        cardValue = aCardValue;
        suit = aSuit;
        color = aColor;
        faceUp = false;
    }
    
/**
    printCard()
    Print of the string representation of a card
*/
        void card::printCard(){
            cout<<"Card: " << color<< "-" << suit << "-"<< cardValue<< "-"<< faceUp<<"\n";
            
        }
/**
    getSuit()
    Returns the suit of a card

    @return char suit
*/
        char card::getSuit(){
            return suit;
        }
        
/**
    setSuit()
    Sets the suit of a card

    @param char newSuit
*/
        void card::setSuit(char newSuit){
            suit = newSuit;
        }
        
/**
    getColor()
    Returns the color of a card

    @return char color
*/
        char card::getColor(){
            return color;
        }
        
/**
    setColor()
    Sets the color of a card

    @param char newColor
*/
        void card::setColor(char newColor){
            color = newColor;
        }
        
/**
    getCardValue()
    Returns the value of a card

    @return int cardValue
*/
        int card::getCardValue(){
            return cardValue;
        }

/**
    setCardValue()
    Sets the value of a card

    @param int newCardValue
*/
        void card::setCardValue(int newCardValue){
            cardValue = newCardValue;
        }
    
/**
    isFaceUp()
    Returns a boolean determining if the card is face up

    @return bool faceUp
*/            
        bool card::isFaceUp(){
            return faceUp;
        }

/**
    flip()
    Changes the faceUp value of the card
*/        
        void card::flip(){
            faceUp = true;
        }
        
/**
    getFaceUp()
    returns a char with the value of a caard's faceup status
    
    @return char 'Y' or 'N'
*/        
        char card::getFaceUp(){
            if(faceUp==true)
                return 'Y';
            return 'N';
        }

