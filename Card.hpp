//
//  Card.hpp
//
//  Created by Sofia Marquez on 4/20/18.
//  Copyright © 2018 Sofia Marquez. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp
#include <stdio.h>
#include <string>
#include <iostream>
#include <cassert>
#include <SFML/Graphics.hpp>

using namespace std;

class Card{
protected:
    sf::Texture cardTexture;
    sf::Sprite cardSprite;
    int num; //number on card
    string color; //the color of the card
public:
    Card();
    Card(int n, string c);
    ~Card() {};
    int getNum()const{return num;}
    void setNum(int nomer);
    void setColor(string color);
    string getColor()const{return color;}
    void displayCard();
    void displayVisualCard(sf::RenderWindow &window, int pos);

};
#endif /* Card_hpp */

