#pragma once
//#include "pile.h"
#include <vector>
#include "card.h"
class tableau{
    public:
        bool canRecieve(card aCard);
        //pile singlePile;
        tableau();
        std::vector<card> getCards();
        void push(card theCard);

};