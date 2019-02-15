#include <iostream>
#include <vector>
#include "Deck.cpp"

using namespace std;
int numGames = 0;
vector<>

int main(){
    cout << "Solitaire initialized";
    cout << "Enter number of games to play";
    cin >> numGames;

    return 0;
}

void newGame(){
    Deck gameCards;
    vector<Card> newPlayer = gameCards.generateDeck();
    newPlayer = gameCards.shuffle();

}