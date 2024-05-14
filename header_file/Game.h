#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

// game core

class Game{
private:
    // private variables
    /*
        Always delete the dynamic variable when use it
    */

   // window
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;

    // game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    // mouse position
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // game logic 
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    unsigned points;
    bool mouseHeld;
    int health;
    bool endGame;
    
    //resources
    sf::Font font;

    //text
    sf::Text uiText;

    // private functions
    void initVariables();
    void initWindow();
    void initEnemies();
    void initFonts();
    void initText();

public:
    // constructer // destructer
    Game();
    virtual ~Game();
    /*
        First const make sure the return var won't change in the entire game
        Second const make sure the function doesn't change state of the object
    */
    const bool running() const;
    const bool getEndGame() const;
    // functions

    void spawnEnemies();
    void updateEnemies();
    void renderEnemies();
    void PollEvent();
    void update();
    void render();
    void updateMousePostions();
    void renderText(sf::RenderTarget& target);
    void updateText();
};