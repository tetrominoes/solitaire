//Class to represent a Pile.
#include <iostream>
#include "Card.cpp"
#include <vector>
using namespace std;

class Pile{

   std::vector<Card> cards;
public:
Pile(){

}
Card pop(){//wrong
    Card temp = this->cards.front();
    this->cards.erase(this->cards.begin());
    return temp;
}

void push(Card card){
    this->cards.push_back(card);
}
Card topCard(){
    return this->cards.at(cards.size()-1);
}
bool empty(){
    if(this->cards.size()==0)
        return true;
    else
        return false;
}
vector<Card> getCards(){
    return this->cards;
}

};
