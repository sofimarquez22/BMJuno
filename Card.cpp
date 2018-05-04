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
}
