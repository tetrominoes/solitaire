#include <iostream>
using namespace std;

class Card{
public:
int cardValue;
char suit;
char color;
bool faceUp;

void printCard(){
    cout<<"Card: " << suit << cardValue;
}

};

int main(){
    Card card1;
    card1.cardValue = 1;
    card1.suit = 'S';
    card1.printCard();
    return 0;
}