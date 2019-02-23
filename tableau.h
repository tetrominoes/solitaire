#pragma once
//#include "pile.h"
#include <vector>

class tableau : public pile{
    public:
        std::vector<card> singleTableau;
        bool canRecieve(card aCard);
        //pile singlePile;
        tableau();
        std::vector<card> & getCards();

};