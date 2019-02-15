//Class to represent a Pile.
#include <iostream>
#include "Card.cpp"
#include <vector>
using namespace std;

class Pile{

   std::vector<Card> Cards;
public:
Pile(){

}
Card pop(){
    Card temp = this->Cards.front();
    this->Cards.erase(this->Cards.begin());
    return temp;
}

void push(Card card){
    this->Cards.push_back(card);
}
Card topCard(){
    return this->Cards.front();
}
bool empty(){
    if(this->Cards.size()==0)
        return true;
    else
        return false;
}
vector<Card> getCards(){
    return this->Cards;
}

};