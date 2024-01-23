#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

// game core

class Game{
private:
    // private variables
    /*
        Always delete the dynamic variable when use it
    */
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;

    // private functions
    void initVariables();
    void initWindow();
    
public:
    // constructer // destructer
    Game();
    virtual ~Game();
    /*
        First const make sure the return var won't change in the entire game
        Second const make sure the function doesn't change state of the object
    */
    const bool running() const;
    // functions
    void PollEvent();
    void update();
    void render();
};