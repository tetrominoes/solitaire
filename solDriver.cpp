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
//using std::vector;
//variables
int numGames = 0;
vector<foundationPile> foundation;
vector<tableau> table; //group of 7 tableaus
vector<card> playerDeck; //game cards

int deckIndex = 0;
int timesCycled=0;
int gamesWon = 0;
//bool gameWon = false;
double winPercentage;

/**
     * class solDriver()
     * consturcted method to run the game of Solitaire
 */

class solDriver{
    
    public:
    //initialize a new game each time
    solDriver(){
        
    }
    
/**
     * newGame()
     * Start a new game of Solitaire.
     * 1. Create a deck of cards
     * 2. Shuffle the deck of cards
     * 
 */    
    
 void newGame(){
    cout << "new game started\n";
    deck gameCards;
    cout<<"HERE1.1\n";
    playerDeck = gameCards.generateDeck();
    cout<<"HERE1.2\n";
    playerDeck = gameCards.shuffle();
    
}
    
/**
     * checkTimesCycled()
     * Check how mant times the deck has been cycled through. If the number is > 3 (and the foundation is not full), then the game is lost.
     * 
     * @return bool: true if the deck has not been cycled too many times
 */      
    
    bool checkTimesCycled(){
    if(timesCycled<=3){
        return true;
    }
    return false;
    }
    
/**
     * checkCardFromDeck()
     * Check the top card in the deck and edit deckIndex.
     * If the card is the last in the deck, then the deck needs to be reset.
     * Check to see if the card can be placed at the foundation, and tableau.
 */      
    
 void checkCardFromDeck(){
     if(deckIndex<-1){
         timesCycled++;
         deckIndex = 0;
     }
     else{
        deckIndex++;
     }
     //Check Foundation
     for(int i = 0;i<4;i++){
         if(foundation.at(i).canReceieve(playerDeck.at(deckIndex),foundation.at(i))){
             foundation.at(i).push(playerDeck.at(deckIndex));
             playerDeck.erase(playerDeck.begin()+deckIndex);
             deckIndex--;
         }
     }
    //CHECK TABLEAU
     for(int j = 0; j<7;j++){
         if(table.at(j).canRecieve(playerDeck.at(deckIndex))){
             table.at(j).push(playerDeck.at(deckIndex));
             playerDeck.erase(playerDeck.begin()+deckIndex);
             deckIndex--;
            }
        }
    }
    
    /**
     * scanDrawPileToFoundation()
     * check to see if the card at the top of the "draw" can be placed in the foundation pile.
 */  

 void scanDrawPileToFoundation(){
     for(int i = 0; i<4;i++){
        if(foundation.at(i).canReceieve(playerDeck.at(deckIndex),foundation.at(i)))
        {
            card singleCard = playerDeck.at(deckIndex);
            playerDeck.erase(playerDeck.begin()+deckIndex);
            foundation.at(i).push(singleCard);
        }
     }
 }
 
  /**
     * checkOpenTableau()
     * check if a tableau is open to recieve a card
     * 
     * @return bool moveCard: true if the card can move
 */ 
 
 bool checkOpenTableau(){
     int size;
     int x=0;
     bool faceUp = true;
     bool moveCard = false;
     //LOOP THROUGH WHOLE TABLE
     for(int i = 0; i < 7; i++){
         vector<card> cards = table.at(i).getCards();
         size = cards.size();
         //FINDS # OF FACEUP IN COLUMN
         for(int j = 0;j<size;j++){
             if(cards.at(j).isFaceUp()){
                x++;
             }
             else
                break;
         }
         //FOR EACH FACEUP CARD
        for(int k = x; k >= 0; --k){
            //FOR EACH 'OTHER COLUMN'
            for(int q = 0;q<7;q++){
                //not equal column
                if(i!=q){
                    //
                    if(table.at(q).canRecieve(cards.at(size-k)))
                    {
                        //vector<Card> toAdd = vector<Card>(cards.begin()+size-k, cards.begin()+size-1);
                        moveStackOfCards(size-k,size-1,q,i);
                        flipTopCards();
                        k=-1;
                        q=7;
                        //yikes
                        moveCard = true;
                    }
                }
            }
        }
     }
     return moveCard;
 }
 
   /**
     * checkOpenTableau()
     * moving stacks of cards between tableaus
     * 
     * @param from - location of target card 
     * @param tableauIndexFrom - location in its tableau
     * @param to - destination of target card 
     * @param tableauIndexTo - destination of new tableau
 */ 

 void moveStackOfCards(int from, int to, int tableauIndexTo, int tableauIndexFrom){
        //WHAT WE WANT TO MOVE
        vector<card> cardsFrom = table.at(tableauIndexFrom).getCards();
        //WHERE
        vector<card> cards = table.at(tableauIndexTo).getCards();
        for(int i = 0; i<to;i++){
            cards.push_back(cardsFrom.at(from+i));
        }
         cardsFrom.erase(cards.begin()+from,cards.begin()+to);


 }
 
   /**
     * flipTopCards()
     * change the value of faceUp to true for cards at the top of the pile
     * 
 */ 
 
 void flipTopCards(){
     
    for(int i = 0;i<7;i++){
        vector<card> cards = table.at(i).getCards();
        //cout<<cards.capacity()-1<<"\n";
        if(!cards.at(cards.size()-1).isFaceUp()){
            
            cards.at(cards.size()-1).flip();
         }
         
    }
}

   /**
     * setupTable()
      * Create a table of cards to represent the playing space, or all 7 tableaus.
 */ 
 
void setupTable(){
  //create all tableau's
  cout << "setting up table\n";
  
  //flip cards for setup
  int makefaceup [] = {0, 7, 13, 18, 22, 25, 27};
  for (const int& i : makefaceup) { 
         playerDeck.at(i).flip();
        //temp.flip();
    }
  
  //Tableau 1
    int tab1 [] = {0};
    int tab2 [] = {1, 7};
    int tab3 [] = {2, 8, 13};
    int tab4 [] = {3, 9, 14, 18};
    int tab5 [] = {4, 10, 15, 19, 22};
    int tab6 [] = {5, 11, 16, 20, 23, 25};
    int tab7 [] = {6, 12, 17, 21, 24, 26, 27};
    
    /* tableau slot1;
    for (const int& i : tab1) { 
        card temp = playerDeck.at(i);
        cout << "Tableau 1: Card"; //<< i << " = " << temp.printCard() << "\n";
        temp.printCard();
        slot1.push(temp);
    }
    */
    tableau slot3;
    slot3.push(playerDeck.at(2));
    slot3.push(playerDeck.at(8));
    slot3.push(playerDeck.at(13));
    
    /*cout << "size of tab3 " << slot3.getCards().size() ;
    for(int b = 0; b<table.size();b++){
        for(int c = 0; c<table.at(b).getCards().size();c++){
            cout<<table.at(b).getCards().at(c).getCardValue()<<" ";
        }
        cout<<"\n";
    }
    for(int i = 0 ; i<table.at(2).getCards().size(); i++){
        //cout<<"HEREHERE";
    cout<<table.at(2).getCards().at(i).getCardValue()<<"\n";
    }
    
    //removes first 28 cards that were used for making tableaus
    for(int i = 0; i < 28; ++i)
    { 
        playerDeck.erase(playerDeck.begin()); 
    }
    */
    foundationPile pile1;
    foundationPile pile2;
    foundationPile pile3;
    foundationPile pile4;
    foundation.push_back(pile1);
    foundation.push_back(pile2);
    foundation.push_back(pile3);
    foundation.push_back(pile4);
    cout << "tab3 is set up\n";
}

   /**
     * checkWin()
     * check if the game has been won. The foundation must be completed, the other piles empty, and the deck cycled <=3 times
     * 
     * @return bool true is game is won
 */ 
 bool checkWin(){
     
     int count = 0;
     
      for(int i = 0; i<4;i++){
          //cout<<"inside check win\n";
          
          vector<card> cards = foundation.at(i).getCards();
          if(!cards.empty()){
          if(cards.at(cards.size()-1).getCardValue() == 13)
                count++;
          }
      }
      
      if(count == 4){
        return true;
      }
      return false;
 }
 
    /**
     * checkWin()
     * check if cards from tableaus can go to foundation
     * 
 *//
 void scanTableauToFoundation(){
     int size;
     for(int i = 0; i<7;i++){
         vector<card> cards = table.at(i).getCards();

            
         size = cards.size()-1;
        for(int j = 0; j<4;j++){
            if(foundation.at(j).canReceieve(cards.at(size),foundation.at(j))){
                card singleCard = cards.at(size);
                cards.pop_back();
                foundation.at(j).push(singleCard);
                flipTopCards();
            }
        }
     }
 }
};

int main(int argc, char *argv[]){
    system("python banner.py");
    cout << "Solitaire initialized\n";
    cout << "beginning new game\n";
    solDriver game;
    
    game.newGame();
    game.setupTable();
    cout << "--table setup--\n" ;
    /* deckIndex = playerDeck.size()-1;
     cout << "deck index " << deckIndex << "\n";
    while(game.checkTimesCycled()){
        
        if(game.checkWin())
        {
            gamesWon++;
        }
        //cout<< "After If\n";
        game.flipTopCards();
        cout<<"HERE1\n";
        game.scanTableauToFoundation();
        game.scanDrawPileToFoundation();
        game.checkOpenTableau();
        game.checkCardFromDeck();
        //cout << "endof while \n";
    }
    
    for(int i; i< playerDeck.size(); ++i){
        playerDeck.at(i).printCard();
    }
    //cout << "games won: " << gamesWon << "\n"; */
    return 0; 
}