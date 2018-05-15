//
//  test.cpp
//  
//
//  Created by Maria Hernandez on 5/10/18.
//
#include <SFML/Graphics.hpp>

int main( )
{
    sf::RenderWindow window( sf::VideoMode( 640, 480 ), "Game");
    
    while( window.isOpen( ))
    {
        sf::Event event;
        
        while( window.pollEvent( event ))
        {
            switch ( event.type )
            {
                case sf::Event::Closed:
                    window.close( );
                    
                    break;
            }
        }
        window.clear( );
        //draw
        sf::CircleShape circleShape(200);
        circleShape.setOrigin(circleShape.getRadius(), circleShape.getRadius());
        // or you could have calculated the mid point like so:
        // circleShape.setOrigin(circleShape.getLocalBounds().width / 2.0f, circleShape.getLocalBounds().height / 2.0f);
        
        circleShape.setFillColor(sf::Color::Blue);
        window.draw( circleShape);
        window.display( );
    }
}
