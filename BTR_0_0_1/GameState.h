#pragma once
#include "Map.h"
class GameState :
    protected States, protected Map
{
public://CONSTRUCTOR AND DESTRUCTOR 
    GameState();
    GameState(sf::RenderWindow* target);
    ~GameState() override;
public: // VARIABLES


public: // METHODS


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

