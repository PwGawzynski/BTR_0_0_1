#pragma once
#include "MenuState.h"

class Map
{
protected:
	Map(int);
	Map();
	~Map();

	void updateMap();
protected:
	std::vector<std::vector<int>> obiectsINFO;
	std::list<sf::RectangleShape> mapObjects;

	std::vector<std::vector<int>> objectInfoArr2I;

	int mapNO;
};


