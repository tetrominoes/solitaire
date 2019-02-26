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
//class deck: {///consists of a vector of cards.

//deck::

    char SUITS[4] = {'S','C','D','H'};
    int VALUES[13]= {1,2,3,4,5,6,7,8,9,10,11,12,13};
    bool COLORS[2] = {true,false};
    //TRUE = BLACK
    //FALSE = RED
    vector<card> cardsDeck;
    deck::deck(){
        
    }
    //Method to generate a new deck of cards. The deck consists of a standard deck of 52 cards, minus the Jokers.
    vector<card> deck::generateDeck(){
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
                cardsDeck.push_back(singleCard);
            }
        }
        cout<<"--deck gen--\n";
        return cardsDeck;
    }
    //using fisher yates method algorthim to shuffle cards
    vector<card> deck::shuffle(int numShuff){
        vector<card> shuffledcards = cardsDeck;
        
        for(int n = 52 - 1; n> 0; --n){
            int k = rand() % n ;

            card temp = shuffledcards.at(k);
            shuffledcards.push_back(temp);
            shuffledcards.erase(shuffledcards.begin() + k);
        }
        shuffledcards.push_back(shuffledcards.at(0));
        
    /*for(int i = 0; i < shuffledcards.size();i++)
         {
        cout<<i+1;
        shuffledcards.at(i).printCard();
         }*/
        return shuffledcards;
    }
    




/*int main(){
    deck deck;
    vector<card> cards = deck.generateDeck();
    cards = deck.shuffle();
    cout << "cards shuffled";

    //for(int i = 0; i < cards.size();i++)
   // {
   //     cards.at(i).printcard();
   // }

}*/
