#include "deck.cpp"
#include "foundationPile.cpp"
#include "tableau.cpp"
#include "card.cpp"
#include "pile.cpp"
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include "catch2.hpp"
//#include "solDriver.cpp"


using namespace std;


deck gameCards, gameCards2;
 
//solDriver game;

/**
 * DECK Test Cases:
 * 1. Deck of cards is generated with all 52 cards.
 * 2. Deck has been shuffled, still has 52 cards.
 */
 
TEST_CASE( "Deck of cards is generated" ) {
    REQUIRE(gameCards.generateDeck().size() == 52);
    //could also check if cards are unique ?
}

//Deck has been shuffled and stayed the same size 
TEST_CASE( "Deck has been shuffled" ) {
    
    gameCards2.getDeck();
    REQUIRE(gameCards.shuffle().size() == 52);
    //REQUIRE_FALSE(gameCards2.getDeck() == gameCards.getDeck());
}


//28 cards have been placed into the tableau piles
/**TEST_CASE( "Tableau piles have been filled", "[classic]" ) {
    game.newGame();
    game.setupTable();
    REQUIRE(game.gameCards.size() == 24);
}
*/
//Each tableau pile has a different starting amount from 1-7
/**TEST_CASE( "Tableau piles have been filled", "[classic]" ) {
    game.newGame();
    game.setupTable();
    REQUIRE(game.table.at(0).getCards().size() == 1);
    REQUIRE(game.table.at(1).getCards().size() == 2);
    REQUIRE(game.table.at(2).getCards().size() == 3);
    REQUIRE(game.table.at(3).getCards().size() == 4);
    REQUIRE(game.table.at(4).getCards().size() == 5);
    REQUIRE(game.table.at(5).getCards().size() == 6);
    REQUIRE(game.table.at(6).getCards().size() == 7);
}
*/
//Top card of each tableau is flipped
/**TEST_CASE( "Top card of each tableau is face up", "[classic]" ) {
    game.newGame();
    game.setupTable();
    REQUIRE(game.table.at(0).getCards().topCard().isFaceUp() == true);
    REQUIRE(game.table.at(1).getCards().topCard().isFaceUp() == true);
    REQUIRE(game.table.at(2).getCards().topCard().isFaceUp() == true);
    REQUIRE(game.table.at(3).getCards().topCard().isFaceUp() == true);
    REQUIRE(game.table.at(4).getCards().topCard().isFaceUp() == true);
    REQUIRE(game.table.at(5).getCards().topCard().isFaceUp() == true);
    REQUIRE(game.table.at(6).getCards().topCard().isFaceUp() == true);
}
*/

//4 Foundation piles have been made
/**TEST_CASE( "Foundation Piles have been created", "[classic]" ) {
    game.newGame();
    game.setupTable();
    REQUIRE(game.foundation.at(0) != NULL);
    REQUIRE(game.foundation.at(1) != NULL);
    REQUIRE(game.foundation.at(2) != NULL);
    REQUIRE(game.foundation.at(3) != NULL);
  
}
*/
//Foundation pile can only accept an ace when empty
/**TEST_CASE( "Foundation Piles have been created", "[classic]" ) {
    game.newGame();
    game.setupTable();
    Card ace = new Card(1,'S',TRUE);
    REQUIRE(game.foundation.at(0).canReceive(ace);
  
}
*/
//Foundation can only accept same suit and ascending order
/**TEST_CASE( "foundation accepts correct cards", "[classic]" ) {
    game.newGame();
    game.setupTable();
    card ace (1,'S',TRUE);
    card two (2,'S',TRUE);
    card three (3,'S',TRUE);
    card four (4,'S',TRUE);
    card five (5,'S',TRUE);
    card six (6,'S',TRUE);
    card seven (7,'S',TRUE);
    card eight (8,'S',TRUE);
    card nine (9,'S',TRUE);
    card ten (10,'S',TRUE);
    card jack (11,'S',TRUE);
    card queen (12,'S',TRUE);
    card king (13,'S',TRUE);
    REQUIRE(game.foundation.at(0).canReceive(ace);
    game.foundation.at(0).push_back(ace);
    REQUIRE(game.foundation.at(0).canReceive(two);
    game.foundation.at(0).push_back(two);
    REQUIRE(game.foundation.at(0).canReceive(three);
    game.foundation.at(0).push_back(three);
    REQUIRE(game.foundation.at(0).canReceive(four);
    game.foundation.at(0).push_back(four);
    REQUIRE(game.foundation.at(0).canReceive(ace);
    game.foundation.at(0).push_back(ace);
    REQUIRE(game.foundation.at(0).canReceive(ace);
    game.foundation.at(0).push_back(ace);
    REQUIRE(game.foundation.at(0).canReceive(ace);
    game.foundation.at(0).push_back(ace);
    REQUIRE(game.foundation.at(0).canReceive(ace);
    game.foundation.at(0).push_back(ace);
    REQUIRE(game.foundation.at(0).canReceive(ace);
    game.foundation.at(0).push_back(ace);
    REQUIRE(game.foundation.at(0).canReceive(ace);
    game.foundation.at(0).push_back(ace);
    REQUIRE(game.foundation.at(0).canReceive(ace);
    game.foundation.at(0).push_back(ace);
    REQUIRE(game.foundation.at(0).canReceive(ace);
    game.foundation.at(0).push_back(ace);
    REQUIRE(game.foundation.at(0).canReceive(ace);
    game.foundation.at(0).push_back(ace);
  
}
*/
//Card can be moved from tableau to foundation only when same suit/ascending order
TEST_CASE( "tableau to foundation", "[classic]" ) {
    foundationPile foundation();
    tableau tableau();
    card ace (1,'S',TRUE);
    tableau.push_back(ace);
    foundation.push_back(tableau.topOfTableau());
    REQUIRE(foundation.topCard() == ace);
       
}
//Card can be moved from foundation to Tableau only when opposite color/descending order
TEST_CASE( "foundation to tableau", "[classic]" ) {
    foundationPile foundation();
    tableau tableau();
    card ace (1,'S',TRUE);
    tableau.push_back(ace);
    foundation.push_back(tableau.topOfTableau());
    REQUIRE(foundation.topCard() == ace);
       
}
//Draw Pile created from rest of cards
//Top card of draw pile can be flipped
//Top card from Draw Pile can be moved into foundation only when same suit/ascending order
//Top card from draw pile can be moved into Tableau only when opposite color/descending order
//Foundation cannot accept any other cards once a king has been placed
//Tableau cannot accept any other cards when an ace is the top card
//Group of cards can be moved between tableaus
//Cards moved are no longer in their original pile
//Game is finished when all foundation piles are filled

