#include"../header_file/Game.h"

// private functions
void Game::initVariables(){
    this->window = nullptr;
}

void Game::initWindow(){
    // Horizontal and vertical of the window
    this->videoMode.width = 800;
    this->videoMode.height = 600;
    this->window = new sf::RenderWindow(this->videoMode, "Game");
}

// accessors
const bool Game::running() const{
    return this->window->isOpen();
}

// constructer // destructer
Game::Game(){
    this->initVariables();
    this->initWindow();
}

Game::~Game(){
    delete this->window;
}

//functions
void Game::PollEvent(){
    // Event polling
    while(this->window->pollEvent(this->ev)){
        switch (this->ev.type){
            case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
            case sf::Event::Closed:
                this->window->close();
                break;
        }
        
    }
}

void Game::update(){
    this->PollEvent();
}


void Game::render(){
    /*
        Clear old frame
        Render object
        Display frame in window
    */
    this->window->clear(sf::Color::Blue);
    this->window->display();
}