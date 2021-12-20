#pragma once
#include "Map.h"
#include "Player.h"

class GameState :
    protected States, protected Map, protected Player
{
public://CONSTRUCTOR AND DESTRUCTOR 
    GameState();
    GameState(sf::RenderWindow* target);
    ~GameState() override;
    void updateDT();
    
public: // VARIABLES
    void movePlayer(sf::Vector2f delta);

public: // METHODS
    void movePlayer();
    

protected: // VARIABLES 


protected: // METHODS
    void update() override;
    void render() override;
    void renderSprites() override;
    void renderSelfStateObject() override;
    void createBTNs() override;
    void updateMouse() override;
    int handleBTNpresseing() override;
private: // VARIABLES
    sf::RenderWindow* window;
    

private: // METHODS
    

};

