#pragma once
#include "States.h"

class MenuState
	:public States
{
public:/*CONSTRUCTOR DESTRUCTOR*/
	MenuState();
	MenuState(sf::RenderWindow* target);
	~MenuState() override;

public:/*VARIABLES*/


protected:/*METHODS*/
	void update() override;
	void render() override;
	void renderSprites() override;
	void renderSelfStateObject() override;
	void createBTNs() override;
	void updateMouse() override;
	int handleBTNpresseing() override;
	void movePlayer(sf::Vector2f delta) override;


private:/*VARIABLES*/
	sf::RectangleShape playBTN;
	sf::RectangleShape exitBTN;


private:/*METHODS*/

};

