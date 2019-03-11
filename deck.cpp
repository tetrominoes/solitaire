/**
    deck.cpp
    Purpose: Creates a deck of cards

    @author tetrominoes
    @version 1.0 Feb. 2019
*/

#include <iostream>
#include <vector>
#include "card.h"
#include "deck.h"

//resources for shuffle
#include <algorithm>
#include <iterator>
#include <random>

using namespace std;



    char SUITS[4] = {'S','C','D','H'};
    int VALUES[13]= {1,2,3,4,5,6,7,8,9,10,11,12,13};
    bool COLORS[2] = {true,false};
    //TRUE = BLACK
    //FALSE = RED
    vector<card> cardsDeck;
    
    /**
     * deck::deck()
     * Establish each card in the deck.
     * 
 */
    
    deck::deck(){
    }
    
/**
     * generateDeck()
     * Method to generate a new deck of cards. The deck consists of a standard deck of 52 cards, minus the Jokers.
     * 
     * @return cardsDeck : a vector of cards representing our generated deck
 */
 
    vector<card> deck::generateDeck(){
        cout<<"DECK";
        bool temp = false;
        //For each suit in the deck, generate all 13 cards.
        for(int i = 0; i<4;i++){
            char currentSuit = SUITS[i];
            //assign the color to the card depending on its suit
            if(i<2)
                temp = true;
            else
                temp = false;
            //for all 13 cards in each suit, assign a new card its value, suit, and faceUp status. Push the card into the deck.
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
/**
 * shuffle()
    * Method to shuffle our deck of cards using the Fisher-Yates algorithm.
    * 
    * 
    * @return shuffledcared : a deck of shuffled cards
*/ 
    
    vector<card> deck::shuffle(){
        vector<card> shuffledcards;
        //ACE GETS LOST IN FOR LOOP!
        for(int n = cardsDeck.size()-1; n> 0; --n){
            //cout<<"HERE1111\n";
            int k = rand() % n+1;

            card temp = cardsDeck.at(k);
            //cout<< temp.getCardValue()<<temp.getSuit()<<"\n";
            shuffledcards.push_back(temp);
            cardsDeck.erase(cardsDeck.begin() + k);
        }
        //cout<<cardsDeck.at(0).getCardValue()<<cardsDeck.at(0).getSuit();
        shuffledcards.push_back(cardsDeck.at(0));
        cardsDeck.erase(cardsDeck.begin()+0);
        //cout<<"HERE22222\n";
        //for(int i = 0;i<shuffledcards.size();i++){
       //     cout<<i+1<<" "<<shuffledcards.at(i).getCardValue()<<shuffledcards.at(i).getSuit()<<"\n";
       // }
        
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
