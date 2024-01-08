#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

//using namespace sf;

int main(){

    //Window
    sf::Window window(sf::VideoMode(640,400), "My first project", sf::Style::Default);
    sf::Event ev;

    while(window.isOpen()){

        //Event polling
        while(window.pollEvent(ev)){
            switch(ev.type){
                case sf::Event::Closed:
                   // window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(ev.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
            }
        }
    }


    //Update


    //Render
    //window.clear(sf::Color::Blue);

    //Draw game
    //window.display();

    return 0;
}