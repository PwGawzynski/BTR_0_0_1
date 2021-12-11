#pragma once
#include "MenuState.h"

class Map
{
protected:
	Map();
	~Map();
protected:
	std::vector<std::vector<int>> obiectsINFO;
	std::list<sf::RectangleShape> mapObjects;
};


