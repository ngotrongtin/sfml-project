#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

//using namespace sf;

int main(){

    //Window
    sf::RenderWindow window(sf::VideoMode(640,400), "My first project", sf::Style::Default);
    sf::Event ev;
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Green);
    while(window.isOpen()){

        //Event polling
        while(window.pollEvent(ev)){
            switch(ev.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(ev.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
            }
        }

        window.clear(sf::Color::Blue);
        window.draw(circle);
        window.display();
    }


    //Update


   
 

    return 0;
}