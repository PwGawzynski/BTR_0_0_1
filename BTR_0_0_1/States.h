#pragma once
#include "TexturesContainer.h"
/**
 * \class States
 * \brief Klasa abstrakcyjna stanow po ktorej dziedzicza klasy gry
 */
class States
	:protected TexturesContainer
{
public:/*CONSTRUCTOR DESTRUCTOR*/
	States();
	States(int);
	virtual ~States();


public:/*VARIABLES*/
	sf::RenderWindow* window;
	sf::VideoMode video;
	std::vector<std::string> paths;
	sf::Vector2f mousePositionView;
	sf::Vector2i mousePositionWindow;
	sf::Clock dtClock;
	float dt;


public:/*METHODS*/
	virtual int update() = 0;
	virtual void render() = 0;
	virtual void renderSelfStateObject() = 0;
	virtual void renderSprites() = 0;
	virtual void updateMouse() = 0;
	virtual void createBTNs() = 0;
	virtual int handleBTNpresseing() = 0;
	virtual void movePlayer(sf::Vector2f delta) = 0;
	virtual void updateDT() = 0;
	virtual void pop_interface_states() = 0;
public:/*VARIABLES*/
	int last_clicked_flag;
	int miniGame1Counter;


private:/*METHODS*/


private:/*VARIABLES*/


};

