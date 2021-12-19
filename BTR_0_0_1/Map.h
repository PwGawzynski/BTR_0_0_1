#pragma once
#include "MenuState.h"

class Map
{
protected:
	Map(int);
	Map();
	~Map();

	void updateMap();
	void updateInterface();
protected:
	std::vector<std::vector<int>> obiectsINFO;
	std::vector<std::string> InterfaceObiectsINFO;
	std::list<sf::RectangleShape> mapObjects;
	std::list<sf::Texture> interfaceObjects;

	std::vector<std::vector<int>> objectInfoArr2I;

	int mapNO;
};


