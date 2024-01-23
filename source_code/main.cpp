#include<iostream>
#include"../header_file/Game.h"
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

//using namespace sf;

int main(){
    // Init game
    Game game;
    // Game loop
    while(game.running()){
        //Update 
        game.update();

        //Render
        game.render();
    }
    return 0;
}