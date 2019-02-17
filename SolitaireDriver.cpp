// Solitaire Game Driver
// built by tetrominoes Spring 2019
#include <iostream>
#include <vector>
#include "Deck.h"
#include "FoundationPile.cpp"
#include "Tableau.cpp"

using namespace std;
//variables
int numGames = 0;
vector<FoundationPile> foundation;
vector<Tableau> tableau; //group of 7 tableaus
vector<Card> deck; //game cards
int deckIndex;
int timesCycled;
int gamesWon = 0;
bool gameWon = false;
double winPercentage;




//initialize a new game each time
void newGame(){
    cout << "new game started";
    Deck gameCards;
    vector<Card> newPlayer = gameCards.generateDeck();
    newPlayer = gameCards.shuffle();
    setupTable(newPlayer);
}

//distribute cards for each of the games
void setupTable(vector<Card> deck){
  //create all tableau's
  cout << "setting up table";
  for(int i = 0; i < 7; ++i){
      Tableau slot;
      tableau.push_back(slot);
  }
  
  //flip cards for setup
  int makefaceup [] = {0, 7, 13, 18, 22, 25, 27};
  for (const int& i : makefaceup) { 
        deck.at(i).flip();
    }
  
  //Tableau 1
    int tab1 [] = {0};
    Tableau slot1;
    for (const int& i : tab1) { 
        Card temp = deck.at(i);
        cout << "Tableau 1: Card" << i << " = " << temp.getCardValue() << "/n";
        slot1.push(temp);
    }
  //Tableau 2  
  int tab2 [] = {1, 7};
  Tableau slot2;
    for (const int& i : tab2) { 
        Card temp = deck.at(i);
        cout << "Tableau 2: Card" << i << " = " << temp.getCardValue() << "/n";
        slot2.push(temp);
    }
  //Tableau 3  
  int tab3 [] = {2, 8, 13};
  Tableau slot3;
    for (const int& i : tab3) { 
        Card temp = deck.at(i);
       cout << "Tableau 3: Card" << i << " = " << temp.getCardValue() << "/n";
        slot3.push(temp);
    }
  //Tableau 4  
  int tab4 [] = {3, 9, 14, 18};
  Tableau slot4;
    for (const int& i : tab4) { 
        Card temp = deck.at(i);
       cout << "Tableau 4: Card" << i << " = " << temp.getCardValue() << "/n";
        slot4.push(temp);
    }
    
  //Tableau 5   
  int tab5 [] = {4, 10, 15, 19, 22};
  Tableau slot5;
    for (const int& i : tab5) { 
        Card temp = deck.at(i);
        cout << "Tableau 5: Card" << i << " = " << temp.getCardValue() << "/n";
        slot5.push(temp);
    }
    
  //Tableau 6 
  int tab6 [] = {5, 11, 16, 20, 23, 25};
  Tableau slot6;
    for (const int& i : tab6) { 
        Card temp = deck.at(i);
       cout << "Tableau 6: Card" << i << " = " << temp.getCardValue() << "/n";
        slot6.push(temp);
    }
    
  //Tableau 7  
  int tab7 [] = {6, 12, 17, 21, 24, 26, 27};
  Tableau slot7;
    for (const int& i : tab7) { 
        Card temp = deck.at(i);
       cout << "Tableau 7: Card" << i << " = " << temp.getCardValue() << "/n";
        slot7.push(temp);
    }
    
    //removes first 28 cards that were used for making tableaus
    for(int i = 0; i < 28; ++i){ deck.erase(deck.begin()); }
    
    cout << "table is set up";
}
//check times cycled.
bool checkTimesCycled(){
    if(timesCycled==3)
        return true;
    return false;
}
//return if the game was completed before cycling 3 times thru deck
 bool checkWin(){
     int count = 0;
      for(int i = 0; i<4;i++){
          vector<Card> cards = foundation.at(i).getCards();
          if(cards.at(0).getCardValue() == 13)
                count++;
      }
      if(count == 4)
        return true;
      return false;
 }
// check if cards from tableaus can go to foundation
 void scanTableauToFoundation(){
     int size;
     for(int i = 0; i<7;i++){
         vector<Card> cards = tableau.at(i).getCards();

            
         size = cards.size()-1;
        for(int j = 0; j<4;j++){
            if(foundation.at(j).canReceieve(cards.at(0),foundation.at(j))){
                Card card = cards.at(size-1);
                cards.pop_back();
                foundation.at(j).push(card);
                flipTopCards();
            }
        }
     }
 }
// check if current card from draw pile can go to foundation
 void scanDrawPileToFoundation(){
     for(int i = 0; i<4;i++){
        if(foundation.at(i).canReceieve(deck.at(deckIndex),foundation.at(i)))
        {
            Card card = deck.at(deckIndex);
            deck.erase(deck.begin()+deckIndex);
            foundation.at(i).push(card);
        }
     }
 }
// moving stacks of cards between tableaus
// from - location of target card | tableauIndexFrom location in its tableau
// to - destination of target card | tableauIndexTo destination of new tableau
 void moveStackOfCards(int from, int to, int tableauIndexTo, int tableauIndexFrom){
        //WHAT WE WANT TO MOVE
        vector<Card> cardsFrom = tableau.at(tableauIndexFrom).getCards();
        //WHERE
        vector<Card> cards = tableau.at(tableauIndexTo).getCards();
        for(int i = 0; i<to;i++){
            cards.push_back(cardsFrom.at(from+i));
        }
         cardsFrom.erase(cards.begin()+from,cards.begin()+to);


 }
// check if a tableau is open to recieve a card
 bool checkOpenTableau(){
     int size;
     int x=0;
     bool faceUp = true;
     bool moveCard = false;
     //LOOP THROUGH WHOLE TABLE
     for(int i = 0; i < 7; i++){
         vector<Card> cards = tableau.at(i).getCards();
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
                    if(tableau.at(q).canRecieve(cards.at(size-k)))
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
// check card
 void checkCardFromDeck(){
     if(deck.size()<deckIndex){
         timesCycled++;
         deckIndex = 0;
     }
     else
        deckIndex++;
     //Check Foundation
     for(int i = 0;i<4;i++){
         if(foundation.at(i).canReceieve(deck.at(deckIndex),foundation.at(i))){
             foundation.at(i).push(deck.at(deckIndex));
             deck.erase(deck.begin()+deckIndex);
             deckIndex--;
         }
     }
    //CHECK TABLEAU
     for(int j = 0; j<7;j++){
         if(tableau.at(j).canRecieve(deck.at(deckIndex))){
             tableau.at(j).push(deck.at(deckIndex));
             deck.erase(deck.begin()+deckIndex);
             deckIndex--;
         }
     }
 }

void flipTopCards(){
    for(int i = 0;i<7;i++){
        vector<cards> cards = tableau.at(i).getCards();
        if(!cards.at(cards.size()-1).faceUp()){
            cards.at(cards.size()-1).flip();
         }
    }
}
//this vector will prob be a collection of vectors that
//represent each 'pile'
//also known as table for a single game
int main(){
    cout << "Solitaire initialized";
    //cout << "Enter number of games to play";
    //cin >> numGames;
    
    /* play numGames Games
    for (int i=0; i<numGames; i++){
        //playGame
        if (playGame() = true){
            gamesWon++;
        }
    }
    
    winPercentage = gamesWon / numGames;
    cout << "Win Percentage: " < winPercentage;
    */
    cout << "begining new game";
    newGame();
    while(checkTimesCycled()){
        if(checkWin())
            return 2;//win
        flipTopCards();
        scanTableauToFoundation();
        scanDrawPileToFoundation();
        checkOpenTableau();
        checkCardFromDeck();
    }
    return 0;
}