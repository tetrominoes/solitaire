#pragma once
//#include "pile.h"
#include <vector>

class tableau : public pile{
    public:
        bool canRecieve(card aCard);
        //pile singlePile;
        tableau();
        std::vector<card> getCards();

};