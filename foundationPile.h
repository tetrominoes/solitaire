#pragma once
#include "pile.h"
//foundationPile;
#include <vector>

class foundationPile: public pile{
    public:
        std::vector<card> singleFoundation;
        foundationPile();
        bool canReceieve(card currentCard);
        std::vector<card> & getCards();
};