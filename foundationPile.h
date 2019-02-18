#pragma once
#include "pile.h"
//foundationPile;
#include <vector>

class foundationPile: public pile{
    public:
    foundationPile();
    bool canReceieve(card currentCard, pile foundPile);
    std::vector<card> getCards();
};