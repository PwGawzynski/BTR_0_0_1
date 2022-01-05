#pragma once
#include "Map.h"
#include "Player.h"
class Win :
    protected States, protected Map, protected Player
{
public://CONSTRUCTOR AND DESTRUCTOR 
    Win();
    Win(sf::RenderWindow* target);
    ~Win() override;
    void updateDT();

public: // VARIABLES
    void movePlayer(sf::Vector2f delta);

public: // METHODS
    void movePlayer();
    void update_interface(int);


protected: // VARIABLES 


protected: // METHODS
    int update() override;
    void render() override;
    void renderSprites() override;
    void renderSelfStateObject() override;
    void createBTNs() override;
    void updateMouse() override;
    int handleBTNpresseing() override;
    void pop_interface_states() override;
private: // VARIABLES
    sf::RenderWindow* window;


private: // METHODS


};