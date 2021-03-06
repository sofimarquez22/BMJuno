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

using namespace std;

class Card{
private:
    int num; //number on card
    string color; //the color of the card
public:
    Card();
    Card(int n, string c);
    int getNum()const{return num;}
    void setNum(int nomer);
    void setColor(string color);
    string getColor()const{return color;}
    void displayCard();
    void displayVisualCard(int num, string color);
};
#endif /* Card_hpp */

