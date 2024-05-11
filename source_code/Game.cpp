#include"../header_file/Game.h"

// private functions
void Game::initVariables(){
    this->window = nullptr;

    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->points = 0;
    this->maxEnemies = 10;
    this->mouseHeld = false;
}

void Game::initWindow(){
    // Horizontal and vertical of the window
    this->videoMode.width = 800;
    this->videoMode.height = 600;
    this->window = new sf::RenderWindow(this->videoMode, "Game");
    this->window->setFramerateLimit(60);
}

// accessors
const bool Game::running() const{
    return this->window->isOpen();
}

// constructer // destructer
Game::Game(){
    this->initVariables();
    this->initWindow();

    // init the enemy variable
    this->initEnemies();
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
    this->updateMousePostions();
    this->updateEnemies();
}


void Game::render(){
    /*
        Clear old frame
        Render object
        Display frame in window
    */
    this->window->clear();

    //draw game objects
    //this->window->draw(this->enemy);
    //spawnEnemies();
    this->renderEnemies();

    this->window->display();
}

void Game::initEnemies(){
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Blue);
    this->enemy.setOutlineThickness(2);
}

void Game::updateEnemies(){
    /*
        updates the enemy spawn timer and spawns enemies
        when the total amount of enemies is smaller than the maximum.
        Moves the enemies downwards.
        Removes the enemies at the edge of the screen.
    */
   
   // Updating the timer for enemy spawning
   if(this->enemies.size() < this->maxEnemies){
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax){
            this->spawnEnemies();
            this->enemySpawnTimer = 0;
        }else{
            this->enemySpawnTimer += 1.f;
        }
   }

   //Move and update the enemies
   for(int i = 0 ; i < this->enemies.size() ; i++){
        this->enemies[i].move(0.f, 1.f); 

        if(this->enemies[i].getPosition().y > this->window->getSize().y)
            this->enemies.erase(this->enemies.begin() + i);
   }

    // check if clicked upon
   if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        bool deleted = false;
        for(size_t i = 0; i < this->enemies.size() ; i++){
            if(this->enemies[i].getGlobalBounds().contains(this->mousePosView)){
                deleted = true;
                 this->points += 5;
            }
        }    
    }
}

void Game::updateMousePostions(){
    /*
        mouse position relative to the window
    */

   this->mousePosWindow = sf::Mouse::getPosition(*this->window);
   this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::spawnEnemies(){
    /*
        spawns enemies and sets their colors and positions
        sets a random color
        add enemy to the vector

    */

   this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
   );
   this->enemy.setFillColor(sf::Color::Green);
   // Spawn enemies
   this->enemies.push_back(this->enemy);
}

void Game::renderEnemies(){
    // rendering all enemies
    for(auto &e : this->enemies){
        this->window->draw(e);
    }
}