#include <iostream>
using namespace std;

class Card{
    public:
    int cardValue;
    char suit;
    char color;
    bool faceUp;


    void printCard(){
        cout<<"Card: " << suit << cardValue<< "FaceUp:"<< faceUp<<"\n";
    }

    char getSuit(){
        return this->suit;
    }
    void setSuit(char suit){
        this->suit = suit;
    };

    char getColor(){
        return this->color;
    }
    void setColor(char color){
        this->color = color;
    }
    int getCardValue(){
        return this->cardValue;
    }
    void setCardValue(int cardValue){
        this->cardValue = cardValue;
    }



};

int main(){
    Card card1;
    card1.cardValue = 1;
    card1.suit = 'S';
    card1.faceUp = true;
    card1.printCard();
    return 0;
}