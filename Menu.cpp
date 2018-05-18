#include "Menu.hpp"

Menu::Menu(int w, int h){
    if (!font.loadFromFile("arial.ttf"))
    {
        return;
    }
    selectedItemIndex  = 1;
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Magenta);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(w / 2, h / (MAX_NUMBER + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(w / 2, h / (MAX_NUMBER + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(w / 2, h / (MAX_NUMBER + 1) * 3));

}

void Menu::moveUp(){
    if (MAX_NUMBER - 1 <= selectedItemIndex+1 && selectedItemIndex+1 <= MAX_NUMBER){
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Magenta);
    }
}

void Menu::moveDown(){
    if (MAX_NUMBER - 2 <= selectedItemIndex + 1 && selectedItemIndex + 1 <= MAX_NUMBER-1){
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Magenta);
    }
}
void Menu::draw(sf::RenderWindow &window){
    for(int i = 0; i < MAX_NUMBER; i++){
        window.draw(menu[i]);
    }

}
