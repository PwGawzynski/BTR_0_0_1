#pragma once
#include "TexturesContainer.h"
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


public:/*METHODS*/
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void renderSelfStateObject() = 0;
	virtual void renderSprites() = 0;
	virtual void updateMouse() = 0;
	virtual void createBTNs() = 0;
	virtual int handleBTNpresseing() = 0;
public:/*VARIABLES*/


private:/*METHODS*/


private:/*VARIABLES*/


};

