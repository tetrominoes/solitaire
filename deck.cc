//Deck implementation

#include <iostream>
#include <vector>
#include <srdlib.h>

using namespace std;

int main(){


    return 0;
}
//using fisher yates method algorthim to shuffle cards
vector<card> shuffle(vector<card> deck){
    auto currentIndexCounter = deck.size();
    for (auto iter = elements.rbegin(); iter != elements.rend();
        ++iter, --currentIndexCounter)
    {
        // get int distribution with new range
        std::uniform_int_distribution<> dis(0, currentIndexCounter);
        const int randomIndex = dis(mt);

        if (*iter != elements.at(randomIndex))
        {
            std::swap(elements.at(randomIndex), *iter);
        }
    }
    
    std::cout << "\nAfter: ";
    std::copy(elements.cbegin(), elements.cend(),
        std::ostream_iterator<int>(std::cout, " "));


return deck
}

int generateDeck(){
    vector<Card> temp;
    for(int i = 0; i < 52; ++i){
        Card singleCard;
        singleCard.cardValue = ;//something
        singleCard.color

        temp.
    }

}
int getDeck(){

}
int getNextCard(){

}