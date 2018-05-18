#ifndef SFML_HPP
#define SFML_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Font.hpp"
#define MAX_NUMBER 3
using namespace std;

class Menu{
    public:
        Menu(){};
        Menu(int w, int h);
        ~Menu(){};
        void draw(sf::RenderWindow &window);
        void moveUp();
        void moveDown();
        int getSelectedItemIndex()const{return selectedItemIndex;}
    private:
        sf::Font font;
        sf::Text menu[MAX_NUMBER];
        int selectedItemIndex;

};

#endif //SFML_HPP
