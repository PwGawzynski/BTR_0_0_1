#pragma once
#include "Map.h"
#include "Player.h"
    class MiniGame1 :
    protected States, protected Map, protected Player
{
public://CONSTRUCTOR AND DESTRUCTOR 
    MiniGame1();
    MiniGame1(sf::RenderWindow* target);
    ~MiniGame1() override;
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