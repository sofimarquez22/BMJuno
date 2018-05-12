//  created by Juhi Park.
//  copyright © 2018 Juhi Park. all rights reserved.

#ifndef UNOGAME_HPP
#define UNOGAME_HPP
#include "Card.hpp"
#include "Player.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


class UnoGame{
protected:
    static const Card deck_total[76];
    Player user;
    Player comp;
    vector<Card> face_up;
    vector<Card> face_down;
    

public:
    UnoGame();
    void start();
    void play();
    void shuffle(vector<Card>& cards);
    bool end_game();
    void add_to_faceup(Card c);
    void check_facedown();
    
};

#endif //UNOGAME_HPP 
