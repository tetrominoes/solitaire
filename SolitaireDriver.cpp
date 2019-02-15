#include <iostream>
#include <vector>
#include "Deck.cpp"

using namespace std;
int numGames = 0;
vector<>
//this vector will prob be a collection of vectors that
//represent each 'pile'
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
  


}
