#pragma once
#include "States.h"
/**
 * \class MenuState
 * \brief Klasa bazowa menu 
 */
class MenuState
	:public States
{
public:/*CONSTRUCTOR DESTRUCTOR*/
	MenuState();
	MenuState(sf::RenderWindow* target);
	~MenuState() override;

public:/*VARIABLES*/


protected:/*METHODS*/
	int update() override;
	void render() override;
	void renderSprites() override;
	void renderSelfStateObject() override;
	void createBTNs() override;
	void updateMouse() override;
	int handleBTNpresseing() override;
	void movePlayer(sf::Vector2f delta) override;
	void updateDT() override;
	void pop_interface_states() override;


private:/*VARIABLES*/
	sf::RectangleShape playBTN;
	sf::RectangleShape exitBTN;


private:/*METHODS*/

};

