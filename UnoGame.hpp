//  created by Juhi Park.
//  copyright © 2018 Juhi Park. all rights reserved.

#ifndef UNOGAME_HPP
#define UNOGAME_HPP
#include "Card.hpp"
#include "Player.hpp"
#include "Font.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WIDTH= 2000;
const int HEIGHT = 1500;

class UnoGame{
protected:
    sf::RenderWindow window;
    static const Card deck_total[76];
    Player user;
    Player comp;
    vector<Card> face_up;
    vector<Card> face_down;
    

public:
    UnoGame();
    ~UnoGame();
    //sfml related method
    void run();
    void start();
    void play();
    void shuffle(vector<Card>& cards);
    bool end_game();
    void add_to_faceup(Card c);
    void check_facedown();
    int getUserInput(sf::RenderWindow &window);
    void comp_turn(string deck_color, int deck_num);
    
};

#endif //UNOGAME_HPP 
