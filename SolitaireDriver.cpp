#include <iostream>
#include <vector>
#include "Deck.cpp"
#include "FoundationPile.cpp"
#include "Tableau.cpp"
//#include "Pile.cpp"

using namespace std;
int numGames = 0;
vector<Tableau> tableau;
vector<FoundationPile> foundation;
vector<Card> deck;
int currentIndexOfDeck;
//this vector will prob be a collection of vectors that
//represent each 'pile'
//also known as table for a single game
int main(){
    cout << "Solitaire initialized";
    cout << "Enter number of games to play";
    cin >> numGames;

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


