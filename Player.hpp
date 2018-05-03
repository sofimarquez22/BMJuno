#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"
#include <string>
#include <iostream>
using namespace std;

class Player
{
    public:
        Player();
        void addCard(vector<Card> cards);// get cards when you don’t have the card you need
        void addCard(Card c); //?? I was thinking player get one card at a time
        Card putCard(string color, int number);// send card back
        void seeMyCard():

    protected:
    
        vector<Card> hand;
    
    
};

#endif
