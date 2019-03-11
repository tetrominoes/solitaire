#pragma once
//#include "pile.h"
#include <vector>
#include "card.h"
class tableau{
    public:
        std::vector<card> singleTableau;
        bool canRecieve(card aCard);
        tableau();
        std::vector<card> & getCards();
        int topOfTableau();
};