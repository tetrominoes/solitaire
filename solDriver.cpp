#include <iostream>
#include <vector>
#include "deck.h"
#include "foundationPile.h"
#include "tableau.h"
#include "card.h"
#include "pile.h"
//#include "catch2.hpp"

//efine CATCH_CONFIG_MAIN
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
    
    void newGame(int numShuff){
    cout << "new game started\n";
    deck gameCards;
    numShuff = (numShuff<1)? numShuff = 1: numShuff;
    playerDeck = gameCards.generateDeck();
    playerDeck = gameCards.shuffle(1);

    
    
}

    void setupTable(){
  //create all tableau's
  
  //flip cards for setup
  int makefaceup [] = {0, 7, 13, 18, 22, 25, 27};
  for(const int& i : makefaceup) { 
         playerDeck.at(i).flip();
    }
    foundation.reserve(4);
    for(int nb = 0; nb<4;nb++){
        foundationPile newPile;
        foundation.push_back(newPile);
    }
    table.reserve(7);
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
    for(int k = 0; k < playerDeck.size(); k++){
        playerDeck.at(k).flip();
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
                //if (!addCard.isFaceUp()){addCard.flip();}
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
                int val2 = addCard.getCardValue();
 
                if(val2 - foundation.at(i).getCards().back().getCardValue() == 1){ //&& addCard.getSuit() == foundation.at(i).getCards().at(foundation.size()-1).getSuit()){ //remember to check that the 'front' card is flipped
                    //if (!addCard.isFaceUp()){addCard.flip();}
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

        for(int i = 0; i < 7; i++){
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

            if(table.at(i).getCards().back().isFaceUp()){
                if (addToFoundation(table.at(i).getCards().back())){
                    table.at(i).getCards().erase(table.at(i).getCards().end());
                    refreshTableau();
                }
            }
        }
    }

    void refreshTableau(){
        cout << "REFRESH TABLEAUS\n" ;
        for(int i = 0; i < 7; i++){
            //vector<card> singleTableau = table.at(t).getCards();
                if(!table.at(i).getCards().back().isFaceUp()){
                    table.at(i).getCards().back().flip();
                    cout << "REFRESHED TABLEAU NO. " << i << "\n" ;
                }
        }
    }

    void tableauToTableau(){
        cout << "TABLEAU >> TABLEAU\n";
        for(int t = 0; t < 7; t++){
            //vector<card> singleTableau = table.at(t).getCards();
            //int topOfStack = table.at(t).topOfTableau();
            if(!table.at(t).empty() && addToTableau(table.at(t).getCards().at(table.at(t).topOfTableau()))){
                cout << "   moving tableau no. " << t << "\n";
                for(int k = table.at(t).topOfTableau(); k < table.at(t).getCards().size(); k++){
                    cout << "   moving rest of tableau no. " << t << "\n";
                    addToTableau(table.at(t).getCards().at(k));
                    //remove cards from current tableau
                    table.at(t).getCards().erase(table.at(t).getCards().end());
                }
                cout << "   moved tableau no. " << t << "\n";
                refreshTableau();
            }else{
                moveKings();
                refreshTableau();
                
                cout << "   !move tableau\n";
            }
        }
    }
    
    void moveKings(){
	    cout << "moving kings\n";
        for(int k = 0; k < 7; k++){
            if(table.at(k).getCards().empty()){
                for(int p = 0; p < 7; p++){
                    if(k!=p){
                    if (table.at(p).getCards().at(table.at(p).topOfTableau()).getCardValue() == 13){
                        table.at(k).getCards().push_back(table.at(p).getCards().at(table.at(p).topOfTableau()));
                        //table.at(p).getCards().erase(table.at(p).getCards().begin() + table.at(p).topOfTableau());
                        vector<card> temp = table.at(p).getCards();
			for(int m = table.at(p).getCards().topOfTableau(); m < table.at(p).getCards().size(); m++){
	table.at(k).getCards().push_back(temp.at(m);
	table.at(p).getCards().erase(table.at(p).getCards().end());
                    }
                    }
                }   
            }
        }
    }
    
    void printState(){
        string message;
        string foundations;
        for(int b = 0; b<4;b++){
            vector<card> foundationCards = foundation.at(b).getCards();
            for(int a = 0; a<foundationCards.size();a++){
               foundations = foundations + foundationCards.at(a).getSuit() + to_string(foundationCards.at(a).getCardValue())+foundationCards.at(a).getFaceUp()+" ";
            }
        cout<< "Foundation "<< to_string(b+1) <<" "<< foundations<<"\n";
        foundations = "";
        }

        for(int i = 0;i<7;i++){
            vector<card> currentCards = table.at(i).getCards();
            for(int j = 0;j<currentCards.size();j++){
                message = message+ " " + currentCards.at(j).getSuit() + to_string(currentCards.at(j).getCardValue()) + currentCards.at(j).getFaceUp()+" ";
            }
            cout<<"Tableau "<< i+1<< " " << message<<"\n";
            message ="";
        }
    string remaining;
    for(int q = 0; q<playerDeck.size();q++){
        remaining = remaining + playerDeck.at(q).getSuit()+to_string(playerDeck.at(q).getCardValue())+ " ";
        
    }
    cout<< remaining;
    }

};

int main(int argc, char *argv[]){
    cout << "Solitaire initialized\n";
    cout << "beginning new game\n";
    int victories;
    solDriver game;
    game.newGame(4);
    game.setupTable();
    game.printState();
    cout << "draw pile\n";
    cout << "--game started--\n";
    while(timesCycled <= 3 ){
        cout << "active index: "<< deckIndex<< " :: "; playerDeck.at(deckIndex).printCard();
        card playerCard = playerDeck.at(deckIndex);
        game.printState();
        game.tableauToTableau();
        game.printState();
        game.refreshTableau();
        game.printState();
        game.tableuToFoundation();
        game.printState();

        if(game.addToFoundation(playerCard) || game.addToTableau(playerCard)){
            playerDeck.erase(playerDeck.begin() + deckIndex);
            deckIndex--;
        }else{
            deckIndex++;
        }
        if(deckIndex >= playerDeck.size()){
            ++timesCycled;
            deckIndex = 0;
        }
        
        cout << "drew another card | " << playerDeck.size() << " cards remain\n";
        
    }
    cout<< "END\n";
    
    return 0; 
}
