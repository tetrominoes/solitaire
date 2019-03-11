/**
    solDriver.cpp
    Purpose: Simulate games of Solitaire, determine if a game was won, and give a rate of wins/games
    @author tetrominoes
    @version 1.0 Feb. 2019
*/
#include <iostream>
#include <vector>
#include "deck.h"
#include "foundationPile.h"
#include "tableau.h"
#include "card.h"
#include "pile.h"

using namespace std;

//variables
int numGames = 0;
vector<foundationPile> foundation;
vector<tableau> table; //group of 7 tableaus
vector<card> playerDeck; //game cards

int deckIndex = 0;
int timesCycled=0;
int gamesWon = 0;
bool gameCompleted = false;
double winPercentage;
deck gameCards;

/**
     * class solDriver()
     * constructed method to run the game of Solitaire
 */
class solDriver{
    
    public:
    //initialize a new game each time
    solDriver(){
        
    }

/**
 * initialSetup()
 * Provides the initial game deck setup for each game
 */
    void initialSetUp(){
        playerDeck = gameCards.generateDeck();
        //playerDeck = gameCards.winDeck();
    }

/**
     * newGame()
     * Start a new game of Solitaire.
     * 1. Create a deck of cards
     * 2. Shuffle the deck of cards
     * 
     * @param numShuff: the number of times to shuffle
 */     
    void newGame(int numShuff){
    cout << "new game started\n";
    
    numShuff = (numShuff<1)? numShuff = 1: numShuff;
    playerDeck = gameCards.shuffle(numShuff);
    
}

/**
     * setupTable()
      * Create a table of cards to represent the playing space, or all 7 tableaus.
 */ 
    void setupTable(){
  //create all tableau's
  
  //flip cards for setup
  int makefaceup [] = {0, 7, 13, 18, 22, 25, 27};
  for(const int& i : makefaceup) { 
         playerDeck.at(i).flip();
    }
    //foundation.reserve(4);
    for(int nb = 0; nb<4;nb++){
        foundationPile newPile;
        foundation.push_back(newPile);
    }
    //table.reserve(7);
    for(int t = 0; t < 7; t++){
        tableau temp;
        table.push_back(temp);
    }
  //make tableaus hete and add to table
  for( int i = 0; i < 7; i++){
    for(int k = i; k < 7; k++){
      
        table.at(k).getCards().push_back(playerDeck.at(deckIndex));
	    // access each table and add card at current index
	    ++deckIndex; //increment to move to next working card
    }
  }

    //removes first 28 cards that were used for making tableaus
    for(int i = 0; i < 28; i++)
    { 
        playerDeck.erase(playerDeck.begin()); 
    }
    
    //cout << "draw pile \n";
    for(int k = 0; k < playerDeck.size(); k++){
        playerDeck.at(k).flip();
        //cout << "card no. "<< k+1 << " " ;
        //playerDeck.at(k).printCard();
    }
    deckIndex = 0;
    //cout << "--table is set up--\n";
    cout << "### PRE - GAME ###\n";
    printState();
}  

/**
 *  addToFoundation()
 * Adds a given card to a foundation pile
 * 
 * @param addCard: the card to add to the foundation
 * @return bool whether or not the card was added
 */

    bool addToFoundation(card addCard){
        char suit = addCard.getSuit();
        char singleFoundSuit;

        
        //cout<< suit<<addCard.getCardValue()<<"\n";
        //cout << "CARD >> FOUNDATION\n";
        //cout<< "card recieved :: " << addCard.getCardValue() << addCard.getSuit() <<"\n";
        for(int i = 0; i < 4; i++){
 
            // add aces to foundation if the foundation is empty
            if(foundation.at(i).getCards().empty() && addCard.getCardValue() == 1){
                if (!addCard.isFaceUp()){addCard.flip();}
                switch (suit) { 
                    case 'S': foundation.at(0).getCards().push_back(addCard); 
                        break; 
                    case 'C': foundation.at(1).getCards().push_back(addCard);
                        break;
                    case 'D': foundation.at(2).getCards().push_back(addCard); 
                        break; 
                    case 'H': foundation.at(3).getCards().push_back(addCard); 
                        break; 
                    
                }
                
                //cout << "   added to foundation\n";
                return true;
            }// add other cards
            
            else if(!foundation.at(i).getCards().empty()){
                
                        /*if(addCard.getCardValue()==5 && addCard.getSuit() == 'D')
                            foundation.at(2).getCards().back().printCard();**/
                int val2 = addCard.getCardValue();
                if(val2 - foundation.at(i).getCards().back().getCardValue() == 1 && foundation.at(i).getCards().back().getSuit() == addCard.getSuit()){ 
                    //&& addCard.getSuit() == foundation.at(i).getCards().at(foundation.size()-1).getSuit()){ //remember to check that the 'front' card is flipped
                    if (!addCard.isFaceUp()){addCard.flip();}
                    //cout<<"adding "<< addCard.getCardValue()<<addCard.getSuit()<<" to foundation\n";
                    switch (suit) { 
                        case 'S': foundation.at(0).getCards().push_back(addCard);
                            break; 
                        case 'C': foundation.at(1).getCards().push_back(addCard);
                            break;
                        case 'D': foundation.at(2).getCards().push_back(addCard);
                            break; 
                        case 'H': foundation.at(3).getCards().push_back(addCard);
                            break; 
                    }

                //cout << "   added to foundation\n";
                return true;
                }
            }
        }
        //cout << "   !add to foundation\n";

        return false;
    }

/** 
    addToTableau()
    Adds a given card to the tableau, faceup.
    
    @param addCard: the card to add
    @return bool: whether or not the card was added
*/
 
    bool addToTableau(card addCard){
        
        //cout << "CARD >> TABLEAU \n";
        bool addCardColor = addCard.getColor();
        int addCardValue = addCard.getCardValue();
        //cout << "card recieved: "; addCard.printCard();

        for(int i = 0; i < 7; i++){
            
            if(
            !table.at(i).getCards().empty() &&
            table.at(i).getCards().back().isFaceUp() && 
            addCardColor != table.at(i).getCards().back().getColor() && 
            table.at(i).getCards().back().getCardValue() - addCardValue == 1)
            {
                if (!addCard.isFaceUp()){
                    addCard.flip();
                }
                table.at(i).getCards().push_back(addCard);
                //cout << "   added to tableau no. " << i << "\n";
                return true;
            }

        }
                                                   
        //cout << "   !add to tableau\n";
        return false;
    }

/**
 * tableuToFoundation()
 * 
 * Move cards from a tableau onto the foundation
 * 
 * @return bool whether or not the cards were moved
 */
 
    bool tableuToFoundation(){
        //cout << "TABLEAU >> FOUNDATION\n";


        
        for(int i = 0; i < 7; i++){
            //printState();
            if(!table.at(i).getCards().empty() && 
            table.at(i).getCards().back().isFaceUp()){
                
                if (addToFoundation(table.at(i).getCards().back())){ 
                    table.at(i).getCards().erase(table.at(i).getCards().end());
                    refreshTableau();
                    //cout<<"here\n";
                    //printState();
                    return true;
                }
            }
        }
        return false;
    }

/**
 * refreshTableau()
 * Refresh the state of the tableau, making sure cards are faceup.
 */
    void refreshTableau(){
        //cout << "REFRESH TABLEAUS\n" ;

        for(int i = 0; i < 7; i++){
            
            //vector<card> singleTableau = table.at(t).getCards();
                if(!table.at(i).getCards().empty() &&
                    !table.at(i).getCards().back().isFaceUp()){
                    table.at(i).getCards().back().flip();
                    //cout << "REFRESHED TABLEAU NO. " << i << "\n" ;
                }
        }
    }

/**
 * tableauToTableau()
 * 
 * Move cards from a tableau to another tableau

 */
    void tableauToTableau(){
        //cout << "TABLEAU >> TABLEAU\n";
        for(int t = 0; t < 7; t++){
            
            if(!table.at(t).getCards().empty() && addToTableau(table.at(t).getCards().at(table.at(t).topOfTableau()))){
                //cout << "   moving tableau no. " << t << "\n";
                for(int k = table.at(t).topOfTableau(); k < table.at(t).getCards().size(); k++){
                    //cout << "   moving rest of tableau no. " << t << "\n";
                    addToTableau(table.at(t).getCards().at(k));
                    //remove cards from current tableau
                    table.at(t).getCards().erase(table.at(t).getCards().end());
                }
                //cout << "   moved tableau no. " << t << "\n";
                refreshTableau();
            }
        }
    }
    /**
     * moveKings()
     * Move an aviable king (or stack starting with a king) to an empty tableau
     */
    void moveKings(){
	    //cout << "moving kings\n";
        for(int k = 0; k < 7; k++){
            
            if(table.at(k).getCards().empty()){
                
                for(int p = 0; p < 7; p++){
                    
                    if(k!=p){
                    if (!table.at(p).getCards().empty() && table.at(p).getCards().at(table.at(p).topOfTableau()).getCardValue() == 13){
                        
                        table.at(k).getCards().push_back(table.at(p).getCards().at(table.at(p).topOfTableau()));
                        table.at(p).getCards().erase(table.at(p).getCards().begin() + table.at(p).topOfTableau());
                        if(!table.at(p).getCards().empty() && table.at(p).getCards().at(table.at(p).topOfTableau()).getFaceUp()==true)
                        {
                            vector<card> temp = table.at(p).getCards();
                            int where = table.at(p).topOfTableau();
			                for(int m = table.at(p).topOfTableau(); m < table.at(p).getCards().size(); m++){
			                //cout<< table.at(p).getCards().at(where).getCardValue()<< "HERE\n";
	                            table.at(k).getCards().push_back(table.at(p).getCards().at(where));
	                            table.at(p).getCards().erase(table.at(p).getCards().begin()+where);
                            }
                        }    
                    }
                }   
            }
        }
    }
    //cout << "AFTER MOVING KINGS\n";
}
    
    /**
     * printState() 
     * 
     * Print the values of the cards in tableaus, foundations and deckafter each move
     */
    void printState(){
        string message;
        string foundations;
        for(int b = 0; b<4;b++){
            vector<card> foundationCards = foundation.at(b).getCards();
            for(int a = 0; a<foundationCards.size();a++){
               foundations = foundations + foundationCards.at(a).getSuit() + to_string(foundationCards.at(a).getCardValue())+foundationCards.at(a).getFaceUp()+" ";
            }
        cout<< "Foundation "<< b <<" "<< foundations<<"\n";
        foundations = "";
        }

        for(int i = 0;i<7;i++){
            vector<card> currentCards = table.at(i).getCards();
            if(!currentCards.empty()){
                for(int j = 0;j<currentCards.size();j++){
                
                    
                    message = message+ " " + currentCards.at(j).getSuit() + to_string(currentCards.at(j).getCardValue()) + currentCards.at(j).getFaceUp()+" ";
                    //cout<<"PRINT HERE\n";
                    
                }
            }
            
            cout<<"Tableau "<< i+1<< " " << message<<"\n";
            message ="";
            
        }
        
    string remaining;
    for(int q = 0; q<playerDeck.size();q++){
        //cout<<"here\n";
        remaining = remaining + playerDeck.at(q).getSuit() + to_string(playerDeck.at(q).getCardValue()) + " ";
        //cout<< playerDeck.at(q).getSuit() << playerDeck.at(q).getCardValue()<<"\n";
        
    }
    cout<< "PLAYER DECK PRINTED " << remaining<<"\n";
    }
 
 /**
  * gameReset() 
  *
  * resets the current game to begin a new game
  */
    void gameReset(){
        //clear table
        /*vector<card> temp;
        vector<foundationPile> tempFoundation;
        vector<tableau> tempTable; 
        
        playerDeck = temp;
        foundation = tempFoundation;
        table = tempTable;*/
        
        for(int p = 0;  p < playerDeck.size(); p++){
            playerDeck.pop_back();
        }
        // reset tableaus
        for(int o = 0; o < 7; o++){
            table.erase(table.begin() + o);
            /*vector<card> c = table.at(o).getCards();
            for(int g = 0;g<table.at(o).getCards().size();g++){
                c.pop_back();
            }**/
        }
        
        // reset foundation
        for(int r = 0; r < 4; r++){
            /*vector<card> f = foundation.at(r).getCards();
            for(int s = 0; s<f.size();s++){
                foundation.pop_back();
            }**/
            //foundation.erase(foundation.begin() + 0);
            foundation.pop_back();
        }
        cout << "game reset\n"; 
        deckIndex = 0;
        
    }
    
    /**
     * didIWIn()
     * 
     * Checks if the current game has been won
     * @return bool whether or not game has been won
     */
    bool didIWin(){
        //check that tableaus are empty
        //make sure that foundations have all their cards && in order
        if(foundation.at(0).getCards().size() == 13 &&
            foundation.at(1).getCards().size() == 13 &&
            foundation.at(2).getCards().size() == 13 &&
            foundation.at(3).getCards().size() == 13){
                return true;
            }else{
                return false;
            }
    }
    
    vector<card> getPlayerDeck(){
        
    }
};

int main(int argc, char *argv[]){
    system("python banner.py");
    cout << "Solitaire initialized\n";
    cout << "beginning new game\n";
    
    int victories = 0;
    int lose = 0;
    solDriver game;
    game.initialSetUp();
    
    for(int i = 0; i < 5;i++){
        
    cout << "--game no . " << i << "started-- \n";
    
    game.newGame(i);
    /*
    cout << "deck number : " << i << "\n";
    for(int o = 0; o < playerDeck.size(); o++){
        cout << "card no. " << o+1 << " :: ";
        playerDeck.at(o).printCard();
    }
    */
    game.setupTable();
    //game.printState();
        
    while(timesCycled <= 3 && !game.didIWin()){
        //cout << "active index: "<< deckIndex<< " :: "; playerDeck.at(deckIndex).printCard();
        //card that is drawn
        //game.printState();
        card playerCard = playerDeck.at(deckIndex);
        game.moveKings();
        game.tableauToTableau();

        game.refreshTableau();
        while(game.tableuToFoundation()){}
        
        
        if(game.addToFoundation(playerCard) || game.addToTableau(playerCard)){
            playerDeck.erase(playerDeck.begin() + deckIndex);
            deckIndex--;
        }else{
            deckIndex++;
        }
        
        
        //cout << "tableau >> tableau\n";
        if(deckIndex >= playerDeck.size()){
            ++timesCycled;
            deckIndex = 0;
        }
        if( deckIndex == -1){
            deckIndex = 0;
        }
        
        //cout << "drew another card | " << playerDeck.size() << " cards remain and current index "<< deckIndex<<"\n";
    //game.printState();
    }
    
    //Checks foundations for kings.
    //game.printState();
    if (game.didIWin()){
        victories++;
    }else{
        lose++;
    }
    cout << "### POST - GAME ###\n";
    game.printState();
    game.gameReset();
    timesCycled=0;
    }
    
    cout<< "victories :: " << victories << "\n";
    cout<<"losses :: " << lose << "\n";
    
    return 0; 

}