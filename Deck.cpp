#include <iostream>
#include <vector>
#include "Card.cpp"

using namespace std;
class Deck{

    public:
    char SUITS[4] = {'S','C','D','H'};
    int VALUES[13]= {1,2,3,4,5,6,7,8,9,10,11,12,13};
    bool COLORS = {true,false};
    //TRUE = BLACK
    //FALSE = RED
    vector<Card> Cards;

    vector<Card> generateDeck(){

        for(int i = 0; i<4;i++){
            char currentSuit = this->SUITS[i];
            for(int j = 0; j<13;j++){
                Card* card=new Card();
                card->setCardValue(j);
                Cards.push_back(Card);
            }
        }
    }

};