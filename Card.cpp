//Class to represent a card object.
#include <iostream>
using namespace std;

//Card object, which represents a standard playing card in a deck. There are 50 cards (minues jokers) for the game of Solitaire.
class Card{
    public:
    int cardValue;
    char suit;
    bool color;
    bool faceUp;

    //method printCard: Prints all card attribute information to output.
    void printCard(){
        cout<<"Card: " << color<< "-" << suit << "-"<< cardValue<< "-"<< faceUp<<"\n";
    }
    //method getSuit: returns the char representing the suit of the card.
    char getSuit(){
        return this->suit;
    }
    //method setSuit: sets a char to represent the suit of the card.
    void setSuit(char suit){
        this->suit = suit;
    };
    //method getColor: returns a bool representing the color of the card.
    char getColor(){
        return this->color;
    }
    //method setColor: sets a bool to represent the color of the card.
    void setColor(char color){
        this->color = color;
    }
    //method getCardValue: returns an int representing the value of the card.
    int getCardValue(){
        return this->cardValue;
    }
    //method setCardValue: sets an int to represent the value of the card.
    void setCardValue(int cardValue){
        this->cardValue = cardValue;
    }
};

/*int main(){
    Card card1;
    card1.cardValue = 1;
    card1.suit = 'S';
    card1.faceUp = true;
    card1.printCard();
    return 0;
}**/