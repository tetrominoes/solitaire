#pragma once
#include "card.h"
#include <vector>
class pile{
    
    public: 
    pile();
    //card pop();
    void push(card newCard);
    card topCard();
    bool empty();
    std::vector<card> getCards();

};