#pragma once
//#include "MenuState.h"
#include "GameState.h"

class Engine
	:protected MenuState, protected GameState
{
public:/*CONSTRUCTOR DESTRUCTOR*/
	Engine();
	virtual ~Engine();

public:/*METHODS*/
	void updateSFMLEvents();
	void update();
	void render();
	void run();
	
public:/*VARIABLES*/


private:/*VARIABLES*/
	sf::VideoMode video;
	sf::Event ev;
	sf::Image icon;
	sf::RenderWindow* window;
	std::stack<States*> statesStack;
	
private:/*METHODS*/
	void initWindow();
	void initStack();
	void renderIcon();
	void checkClicking();

};

