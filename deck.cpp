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
#include <cstdlib>
//resources for shuffle
#include <algorithm>
#include <iterator>
#include <random>
#include <time.h>
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
                cardsDeck.push_back(singleCard);
            }
        }
        //cout<<"--deck gen--\n";
        return cardsDeck;
    }
    
/**
 * shuffle()
    * Method to shuffle our deck of cards using the Fisher-Yates algorithm.
    * 
    * @return shuffledcared : a deck of shuffled cards
*/ 
    vector<card> deck::shuffle(int numShuff){
        vector<card> shuffledcards = cardsDeck;
        
        for(int i = 0; i < numShuff; i++){
        //std::srand(time(0));
        std::random_shuffle ( shuffledcards.begin(), shuffledcards.end());
        }
        
        /*for(int i = 0; i < numShuff; i++){
        for(int n = 52 - 1; n > 0; --n){
            int k = rand() % n ;

            card temp = shuffledcards.at(k);
            shuffledcards.push_back(temp);
            shuffledcards.erase(shuffledcards.begin() + k);
        }
        
        //shuffledcards.push_back(shuffledcards.at(0));
    **/
    /*for(int j = 0; j < shuffledcards.size();j++)
         {
        cout<<j+1<<"\n";
        shuffledcards.at(j).printCard();
         }*/
         
        return shuffledcards;
    }
    
    
    vector<card> deck::winDeck(){
        
        vector<card> w;
        
        w.push_back(cardsDeck.at(0));
        w.push_back(cardsDeck.at(2));
        w.push_back(cardsDeck.at(5));
        w.push_back(cardsDeck.at(9));
        w.push_back(cardsDeck.at(14));
        w.push_back(cardsDeck.at(20));
        w.push_back(cardsDeck.at(27));
        w.push_back(cardsDeck.at(1));
        w.push_back(cardsDeck.at(4));
        w.push_back(cardsDeck.at(8));
        w.push_back(cardsDeck.at(13));
        w.push_back(cardsDeck.at(19));
        w.push_back(cardsDeck.at(26));
        w.push_back(cardsDeck.at(3));
        w.push_back(cardsDeck.at(7));
        w.push_back(cardsDeck.at(12));
        w.push_back(cardsDeck.at(18));
        w.push_back(cardsDeck.at(25));
        w.push_back(cardsDeck.at(6));
        w.push_back(cardsDeck.at(11));
        w.push_back(cardsDeck.at(17));
        w.push_back(cardsDeck.at(24));
        w.push_back(cardsDeck.at(10));
        w.push_back(cardsDeck.at(16));
        w.push_back(cardsDeck.at(23));
        w.push_back(cardsDeck.at(15));
        w.push_back(cardsDeck.at(22));
        w.push_back(cardsDeck.at(21));
        for(int i = 28;i<52;i++){
            w.push_back(cardsDeck.at(i));
        }
         return w;
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
