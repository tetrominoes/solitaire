#include <iostream>
#include <vector>
#include "deck.h"
#include "foundationPile.h"
#include "tableau.h"
#include "card.h"
#include "pile.h"
//#include "catch2.hpp"

using namespace std;
//using std::vector;
//variables
int numGames = 0;
vector<foundationPile> foundation;
vector<tableau> table; //group of 7 tableaus
vector<card> playerDeck; //game cards

int deckIndex = 0;
int timesCycled;
int gamesWon = 0;
bool gameCompleted = false;
double winPercentage;

class solDriver{
    
    public:
    //initialize a new game each time
    solDriver(){
        
    }
    
    void newGame(){
    cout << "new game started\n";
    deck gameCards;
    
    playerDeck = gameCards.generateDeck();
    //playerDeck = gameCards.shuffle();
    
    
}

    void setupTable(){
  //create all tableau's
  
  //flip cards for setup
  int makefaceup [] = {0, 7, 13, 18, 22, 25, 27};
  for(const int& i : makefaceup) { 
         playerDeck.at(i).flip();
    }
    
    for(int k = 0; k < 4 ; k++){
        foundationPile newPile;
        foundation.push_back(newPile);
    }
    
    for(int t = 0; t < 7; ++t){
        tableau temp;
        table.push_back(temp);
    }
  //make tableaus hete and add to table
  for( int i = 0; i < 7; ++i){
    for(int k = i; k < 7; ++k){
      
      table.at(k).getCards().push_back(playerDeck.at(deckIndex));
	// access each table and add card at current index
	++deckIndex; //increment to move to next working card
    }
  }

    //removes first 28 cards that were used for making tableaus
    for(int i = 0; i < 28; ++i)
    { 
        playerDeck.erase(playerDeck.begin()); 
    }
    deckIndex = 0;
    cout << "--table is set up--\n";
}  

    bool addToFoundation(card addCard){
        char suit = addCard.getSuit();
        cout << "CARD >> FOUNDATION\n";
        
        for(int i = 0; i < foundation.size(); i++){
            
            // add aces to foundation
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
                cout << "   added to foundation\n";
                return true;
            }// add other cards
            else if(!foundation.at(i).getCards().empty()){
                int val1 = foundation.at(i).getCards().back().getCardValue();
                int val2 = addCard.getCardValue();
 
                if(val2 - val1 == 1){ //remember to check that the 'front' card is flipped
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
                cout << "   added to foundation\n";
                return true;
                }
            }
            cout << "   !add to foundation\n";
            return false;
        }
    }
    
    bool addToTableau(card addCard){
        
        cout << "CARD >> TABLEAU \n";
        bool addCardColor = addCard.getColor();
        int addCardValue = addCard.getCardValue();
        cout << "card recieved: "; addCard.printCard();
        for(int i = 0; i < table.size(); i++){
            if(
            table.at(i).getCards().back().isFaceUp() && 
            addCardColor != table.at(i).getCards().back().getColor() && 
            table.at(i).getCards().back().getCardValue() - addCardValue == 1)
            {
                if (!addCard.isFaceUp()){addCard.flip();}
                table.at(i).getCards().push_back(addCard);
                cout << "   added to tableau no. " << i << "\n";
                return true;
            }
        }
        cout << "   !add to tableau\n";
        return false;
    }

    void tableuToFoundation(){
        cout << "TABLEAU >> FOUNDATION\n";
        for(int i = 0; i < 7; i++){
            card frontCard = table.at(i).getCards().back();
            if(frontCard.isFaceUp()){
                if (addToFoundation(frontCard)){table.at(i).getCards().erase(
                    table.at(i).getCards().end());}
            }
        }
    }

    void refreshTableau(){
        cout << "REFRESH TABLEAUS\n" ;
        for(int i = 0; i < 7; i++){
            if(!table.at(i).getCards().back().isFaceUp()){
                    table.at(i).getCards().at(0).flip();
                    cout << "REFRESHED TABLEAU NO. " << i << "\n" ;
            }
            //cout << "TABLEAUS ALREADY FRESH\n" ;
        }
    }

    void tableauToTableau(){
        cout << "TABLEAU >> TABLEAU\n";
        for(int t = 0; t < table.size(); ++t){
            int topOfStack = table.at(t).topOfTableau();
            if(addToTableau(table.at(t).getCards().at(topOfStack))){
                cout << "   moving tableau no. " << t << "\n";
                for(int k = topOfStack; k < table.at(t).getCards().size(); ++k){
                    addToTableau(table.at(t).getCards().at(k));
                    //remove cards from current tableau
                    table.at(t).getCards().erase(table.at(t).getCards().end());
                }
                cout << "   moved tableau no. " << t << "\n";
                refreshTableau();
            }else{
                cout << "   !move tableau\n";
            }
        }
    }
};

int main(int argc, char *argv[]){
    cout << "Solitaire initialized\n";
    cout << "beginning new game\n";
    solDriver game;
    game.newGame();
    game.setupTable();
    

    /*cout << "draw pile\n";
     debugging blocks dont uncomment 
    for(int j = 0; j < playerDeck.size(); ++j){
        playerDeck.at(j).printCard();
    }
    cout << "*****\n";
     //print cards in tableau
        for(int i = 0; i < 7; i++){
        vector<card> temp = table.at(i).getCards();
        cout << "--tableau no. " << i << "--\n";
        for(int j  = 0; j < temp.size(); ++j){
            temp.at(j).printCard();
        }
    }
    for(int i = 0; i < 7; i++){
        vector<card> temp = table.at(i).getCards();
        cout << "--tableau no. " << i << "--\n";
        for(int j  = 0; j < temp.size(); ++j){
            cout << "front of tableu: ";
            temp.front().printCard();
        }
    } */
    cout << "*****\n";
     //print cards in tableau
        for(int i = 0; i < 7; i++){
        vector<card> temp = table.at(i).getCards();
        cout << "--tableau no. " << i << "--\n";
        for(int j  = 0; j < temp.size(); ++j){
            temp.at(j).printCard();
        }
    }
    cout << "--game started--\n";
    while(timesCycled <= 3 ){
        cout << "active index: "<< deckIndex<< " :: "; playerDeck.at(deckIndex).printCard();
        card playerCard = playerDeck.at(deckIndex);
        game.tableauToTableau();
        game.refreshTableau();
        game.tableuToFoundation();
        game.refreshTableau();
        if(game.addToFoundation(playerCard) || game.addToTableau(playerCard)){
            playerDeck.erase(playerDeck.begin() + deckIndex);
            deckIndex--;
            game.refreshTableau();
        }else{
            deckIndex++;
        }
        if(deckIndex >= playerDeck.size()){
            ++timesCycled;
            deckIndex = 0;
        }
        
        cout << "drew another card | " << playerDeck.size() << " cards remain\n";
        
    }
    cout << "*****\n";
     //print cards in tableau
        for(int i = 0; i < 7; i++){
        vector<card> temp = table.at(i).getCards();
        cout << "--tableau no. " << i << "--\n";
        for(int j  = 0; j < temp.size(); ++j){
            temp.at(j).printCard();
        }
    }
    
    /*
    deckIndex = playerDeck.size()-1;
    cout << "deck index " << deckIndex << "\n";
    while(game.checkTimesCycled()){
        cout << "start whhile \n";
        if(game.checkWin())
        {
            gamesWon++;
            cout << "games won";
        }
        game.flipTopCards();
        game.scanTableauToFoundation();
        game.scanDrawPileToFoundation();
        game.checkOpenTableau();
        game.checkCardFromDeck();
        cout << "endof whhile \n";
    }
    cout << "games won" << gamesWon << "\n";
    */
    return 0; 
}

/*
method to check cards in piles
for(int i = 0; i < 7; i++){
        cout << "size of table" << ": "<< i << " "<< table.at(i).getCards().size() << " cards\n" ;
    }

*/

// legacy code
/*
    // check card
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
    // check if current card from draw pile can go to foundation
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
    // check if a tableau is open to recieve a card
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
 
 
    //legacy code block
    void flipTopCards(){
    for(int i = 0;i<7;i++){
        vector<card> cards = table.at(i).getCards();
        if(!cards.at(cards.size()-1).isFaceUp()){
            cards.at(cards.size()-1).flip();
         }
    }
}
    //legacy code block
    //return if the game was completed before cycling 3 times thru deck
    bool checkWin(){
     int count = 0;
      for(int i = 0; i<4;i++){
          vector<card> cards = foundation.at(i).getCards();
          if(cards.at(cards.size()-1).getCardValue() == 13)
                count++;
      }
      if(count == 4){
        return true;
      }
      return false;
 }
    */