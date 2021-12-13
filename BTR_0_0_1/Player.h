#pragma once
#include "Map.h"
class Player
{
public:
	Player();
	~Player();
	void nextFrame();
protected:
	sf::Texture playerTX;
	sf::Sprite playerSprite;
	int frameCounter;
	int width;
	int hight;
	int framecuter;
	int animationStartX;
	int animationStartY;
};

