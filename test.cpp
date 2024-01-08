#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/OpenGL.hpp>
int main(){
    sf::Clock clock; // starts the clock

    sf::Time elapsed1 = clock.getElapsedTime();
    std::cout << elapsed1.asSeconds() << std::endl;
    clock.restart();
    while(!(clock.getElapsedTime() >= sf::seconds(10))){

    }
    sf::Time elapsed2 = clock.getElapsedTime();
    std::cout << elapsed2.asMicroseconds() << std::endl;
    return 0;
}
