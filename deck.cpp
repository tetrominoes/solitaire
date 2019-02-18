// class to represent the Deck object
#include <iostream>
#include <vector>
#include "card.h"
#include "deck.h"

//resources for shuffle
#include <algorithm>
#include <iterator>
#include <random>

using namespace std;
//class Deck: consists of a vector of cards.


deck::deck(){
    
}
    char SUITS[4] = {'S','C','D','H'};
    int VALUES[13]= {1,2,3,4,5,6,7,8,9,10,11,12,13};
    bool COLORS[2] = {true,false};
    //TRUE = BLACK
    //FALSE = RED
    vector<card> cardsDeck;
    
    //Method to generate a new deck of cards. The deck consists of a standard deck of 52 cards, minus the Jokers.
    vector<card> generateDeck(){
        cout<<"DECK";
        bool temp = false;
        //For each suit in the deck, generate all 13 cards.
        for(int i = 0; i<4;i++){
            char currentSuit = SUITS[i];
            if(i<2)
                temp = true;
            else
                temp = false;
            for(int j = 0; j<13;j++){
                int cardValue = VALUES[j];
                
                card singleCard(cardValue, currentSuit, temp);
                //singleCard.setcardValue(VALUES[j]);
                //singleCard.setColor(temp);
                //singleCard.setSuit(currentSuit);
                //singleCard.faceUp = false;
                cardsDeck.push_back(singleCard);
            }
        }
        cout<<"DECK HAS BEEN GENERATED";
        return cardsDeck;
    }
    //using fisher yates method algorthim to shuffle cards
    vector<card> shuffle(){
        vector<card> shuffledcards;
        for(int n = cardsDeck.size() - 1; n> 0; --n){
            int k = rand() % n + 1;

            card temp = cardsDeck.at(k);
            shuffledcards.push_back(temp);
            cardsDeck.erase(cardsDeck.begin() + k);
        }
        return shuffledcards;
    }
    




/*int main(){
    Deck deck;
    vector<card> cards = deck.generateDeck();
    cards = deck.shuffle();
    cout << "cards shuffled";

    for(int i = 0; i < cards.size();i++)
    {
        cards.at(i).printcard();
    }

}**/
