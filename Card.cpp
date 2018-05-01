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
void Card::setColor(string colur){
    for(int i=0; i < colur.length(); i++){
        assert(isalpha(colur[i]));
    }
    color = colur;
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
