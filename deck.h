#pragma once
//#ifndef deck_h
//#define deck_

#include <vector>
#include "card.h"
class deck{
    public:
    deck();
    std::vector<card> generateDeck();
    std::vector<card> shuffle(int numShuff);
    std::vector<card> winDeck();

};