#include <iostream>
#include <vector>
#include "Deck.cpp"

using namespace std;
int numGames = 0;
vector<>
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
