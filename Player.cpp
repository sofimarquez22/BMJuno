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

Card Player::putCard(int index)
{
    Card result_card;
    vector<Card>::iterator it = cards_hand.begin(); 
    for(int i = 0; i < cards_hand.size(); i++)
    {
        if( i == index)
            result_card = cards_hand[i];
    }
    for(int i = 0; i <= index; i++)
        it++;
    cards_hand.erase(it);
    return result_card;
}

void Player::seeMyCard()
{
    for(int i = 0; i < cards_hand.size(); i++)
    {
        cards_hand[i].displayCard() ;
    }
}

