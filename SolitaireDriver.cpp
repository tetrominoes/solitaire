#include <iostream>
#include <vector>
#include "Deck.cpp"
#include "FoundationPile.cpp"
#include "Tableau.cpp"

using namespace std;
//variables
int numGames = 0;
vector<FoundationPile> foundation;
vector<Tableau> tableau;
vector<Card> deck;
int deckIndex;
int timesCycled;
int gamesWon = 0;
bool gameWon = false;
double winPercentage;

//this vector will prob be a collection of vectors that
//represent each 'pile'
//also known as table for a single game
int main(){
    cout << "Solitaire initialized";
    cout << "Enter number of games to play";
    cin >> numGames;

    //play numGames Games
    for (int i=0; i<numGames; i++){
        //playGame
        if (playGame() = true){
            gamesWon++;
        }
    }

    winPercentage = gamesWon / numGames;
    cout << "Win Percentage: " < winPercentage;
    return 0;
}


//initialize a new game each time
void newGame(){
    Deck gameCards;
    vector<Card> newPlayer = gameCards.generateDeck();
    newPlayer = gameCards.shuffle();

}
//distribute cards for each of the games
void setupTable(vector<Card> deck){
  //cycle thru all tableau's
  for(int i = 0; i < 7; ++i){
    for(){//cycle thru all individual tableaus
      //add card to tableau
  }
  }
}

//method playGame: Runs through the algorithm to play a game of solitaire, and returns if the current game was won
bool playGame() {
    //setup a new game
    newGame();
    setUpTable();

    //For each Move
    while (checkWin() == false && timesCycled < 4){
        newMove();
    }
return gameWon;
}

//method move: follow the algorithm to make a new move
void newMove() {
    checkWin();
    scanTableauToFoundation();
    checkWin();
    scanTableauToTableau();
    checkWin();


}


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

 void scanTableauToFoundation(){
     int size;
     for(int i = 0; i<7;i++){
         vector<Card> cards = tableau.at(i).getCards();
         size = cards.size()-1;
        for(int j = 0; j<4;j++){
            if(foundation.at(j))

        }
     }
 }

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

 void scanTableauToFoundation(){
     int size;
     for(int i = 0; i<7;i++){
         vector<Card> cards = tableau.at(i).getCards();
         //size = cards.size()-1;
        for(int j = 0; j<4;j++){
            if(foundation.at(j).canReceieve(cards.at(0))){
                Card card = cards.at(size()-1);
                cards.pop_back();
                foundation.at(j).push(card);
            }
        }
     }
 }

 void scanDrawPileToFoundation(){
     for(int i = 0; i<4;i++){
        if(foundation.at(i).canReceieve(deck.at(deckIndex)))
        {
            Card card = deck.at(deckIndex);
            deck.erase(deck.begin()+deckIndex);
            foundation.at(j).push(card);
        }
     }
 }

 void checkOpenTableau(){
     int size;
     int j;
     bool faceUp = true;
     for(int i = 0; i < 7; i++){
         vector<Card> cards = tableau.at(i).getCards();
         size = cards.size();
         j = 0;
         while(j < size && faceUp){
            if(cards.at(size-1).isFaceUp())

         }

     }
 }