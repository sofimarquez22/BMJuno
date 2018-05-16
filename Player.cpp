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
    for(int i = 0; i < index; i++)
        it++;
    cards_hand.erase(it);
    cout << "sucessfully pulling card\n\n";
    return result_card;
}
bool Player::emptyHand(){
    if(cards_hand.size()==0){
        return true;
    }
    return false;
}
void Player::seeMyCard()
{
    cout << "***Cards on my Hand***\n";

    for(int i = 0; i < cards_hand.size(); i++)
    {
        cards_hand[i].displayCard();
    }
}
void Player::seeMyCardVisual(sf::RenderWindow &window){
    cout << "**Visual Card**\n";
    int pos = 0;
    for(int i = 0; i < cards_hand.size(); i++){
        cards_hand[i].displayVisualCard(window, pos, 10);
        pos += 100;
    }
}

