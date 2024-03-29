#pragma once
//#include "MenuState.h"
#include "GameState.h"
#include "MiniGame1.h"
#include "MiniGame2.h"
#include "Win.h"
#include "Lost.h"
/**
 * \class Engine
 * \brief Glowna klasa gry
 */
class Engine
	:protected MenuState, protected GameState, protected MiniGame1, protected MiniGame2, protected Win, protected  Lost
{
public:/*CONSTRUCTOR DESTRUCTOR*/
	Engine();
	virtual ~Engine();

public:/*METHODS*/
	void updateSFMLEvents();
	int update();
	void render();
	void run();
	
public:/*VARIABLES*/

	int minigame_number;
	int accomplished;
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

