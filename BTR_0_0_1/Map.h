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
	void pop_interface_map();
public:
	std::vector<std::string> InterfaceObiectsINFO;
	int miniGame1Counter_map;
	void pop_interface();
protected:
	std::vector<std::vector<int>> obiectsINFO;
	
	std::list<sf::RectangleShape> mapObjects;
	std::list<sf::Texture> interfaceObjects;

	std::vector<std::vector<int>> objectInfoArr2I;

	int mapNO;
	
};


