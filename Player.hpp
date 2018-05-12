#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Card.hpp"
#include <string>
#include <vector>
#include <iostream>
//include sprites and texture #include <>


using namespace std;

class Player
{
    public:

        Player() {};
        void addCard(Card c);
        Card putCard(int index);
        int checkCard(string color, int number);
        void seeMyCard();
        bool emptyHand();

    protected:
        vector<Card> cards_hand;
    
    
    };

#endif
