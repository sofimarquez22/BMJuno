//
//  Card.cpp
//
//  Created by Sofia Marquez on 4/20/18.
//  Copyright © 2018 Sofia Marquez. All rights reserved.
//

#include "Card.hpp"

Card::Card(){
    num = 0;
    color = " ";
}
Card::Card(int n, string c){
    num = n;
    color = c;
}
void Card::setNum(int nomer){
    num = nomer;
}
void Card::setColor(string color){
    for(int i=0; i < color.length(); i++){
        assert(isalpha(color[i]));
    }
    this->color = color;
}
void Card::displayCard(){
    cout << "-------------" << endl;
    cout << "|"<<color<<"|"<< endl;
    cout << "|           |" << endl;
    cout << "|"<<num << "|"<< endl;
    cout << "|           |" << endl;
    cout << "|           |" << endl;
    cout << "-------------" << endl;
    //displayVisualCard(num, color);
}
void Card::displayVisualCard(sf::RenderWindow &window, int x, int y){
    string cardStr = ""; 
    string dirStr = "/Users/mariahernandez/Desktop/Uno/Uno/cards/";
    string number = "0";
    number[0] += getNum();
    cardStr = dirStr + getColor() + number + ".png";
    cout << cardStr << endl;
    
    if(!cardTexture.loadFromFile(cardStr)){
        cout << "Error loading image" << endl;
    }
    cardSprite.setTexture(cardTexture);
    cardSprite.setPosition(10 + x, y);
    window.draw(cardSprite);
}
