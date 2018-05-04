#include "Player.hpp"


void Player::addCard(Card c)
{
    cards_hand.push_back(c);
}
int Player::checkCard(string color, int number)
{
    for(int i = 0; i < cards_hand.size(); i++)
    {
         if(cards_hand[i].getNum() == number || cards_hand[i].getColor() == color)
             return i;
    }
    return -1;
}

Card putCard(int index)
{
    Card result_card;
    
    for(int i = 0; i < cards_hand.size(); i++)
    {
        if( i == index)
            result_card = cards_hand[i];
    }
    cards_hand.erase(index);
    return result_card;
}

void Player::seeMyCard()
{
    for(int i = 0; i < cards_hand.size(); i++)
    {
        cout << cards_hand[i].displayCard() ;
    }
}

