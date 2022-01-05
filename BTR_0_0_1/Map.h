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
	void updateEntity();
public:
	std::vector<std::string> InterfaceObiectsINFO;
	int miniGame1Counter_map;
protected:
	std::vector<std::vector<int>> obiectsINFO;
	
	std::list<sf::RectangleShape> mapObjects;
	std::list<sf::Texture> interfaceObjects;

	std::vector<std::vector<int>> objectInfoArr2I;

	int mapNO;
	
};


