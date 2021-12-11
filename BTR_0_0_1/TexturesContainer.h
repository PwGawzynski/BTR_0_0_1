#pragma once
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <fstream>

#include <nlohmann/json.hpp>

class TexturesContainer
{
public:
	TexturesContainer();
	TexturesContainer(int);
	~TexturesContainer();
protected:
	int imagesEnd;
	std::vector<std::string> paths;
	std::list<sf::Texture> textures;
	std::list<sf::Sprite> spritees;
	void updateCTR(int);
};

