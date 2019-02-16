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
  int[] tab1 = {1};
  int[] tab2 = {2,8};
  int[] tab3 = {3,9,14};
  int[] tab4 = {4,10,15,19}
  int[] tab5 = {5,11,16,20,23}
  int[] tab6 = {6,12,17,21,24,26}
  int[] tab7 = {7,13,18.22,25,27,28}
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
            if(foundation.at(j).canReceieve(cards.at(0),foundation.at(j))){
                Card card = cards.at(size-1);
                cards.pop_back();
                foundation.at(j).push(card);
            }
        }
     }
 }

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

 void checkOpenTableau(){
     int size;
     int j=0;
     bool faceUp = true;
     //LOOP THROUGH WHOLE TABLE
     for(int i = 0; i < 7; i++){
         vector<Card> cards = tableau.at(i).getCards();
         size = cards.size();
         //FINDS # OF FACEUP IN COLUMN
         for(int j = 0;j<size;j++){
             if(cards.at(j).isFaceUp()){
                j++;
             }
             else
                break;
         }
         //FOR EACH FACEUP CARD
        for(int k = j; k >= 0; --k){
            //FOR EACH 'OTHER COLUMN'
            for(int q = 0;q<7;q++){
                //not equal column
                if(i!=q){
                    //
                    if(tableau.at(q).canRecieve(cards.at(size-k)))
                        moveStackOfCards(,q)
                }
            }
        }
     }
 }


 void moveStackOfCards(vector<Card> toMove,int tableauIndex){
     for(int i = 0; i<toMove.size();i++){

     }
 }