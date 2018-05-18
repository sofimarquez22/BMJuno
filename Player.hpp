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
        ~Player() {};
        int getHandSize()const{return cards_hand.size();}
        void addCard(Card c);
        Card putCard(int index);
        int checkCard(string color, int number); 
        int checkCardIndex(int number);
        int checkCardColor(string color, int number);
        void seeMyCard();
        bool emptyHand();
        void seeMyCardVisual(sf::RenderWindow &window, int y);

    protected:
        vector<Card> cards_hand;
    
    
    };

#endif
