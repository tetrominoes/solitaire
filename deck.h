#pragma once
//#ifndef deck_h
//#define deck_

#include <vector>
#include "card.h"
class deck{
    public:
    std::vector<card> generateDeck();
    std::vector<card> shuffle();
    deck();
};