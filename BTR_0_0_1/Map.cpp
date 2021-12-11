#include "Map.h"

using json = nlohmann::json;

Map::Map() {

	// INFO ABOUT CONSTRUCTOR
	std::cout << "DEFAULT CONSTRUCTOR(ONLY ONE) OF MAP CLASS HAS BEEN COLD" << std::endl;

	std::ifstream i("config/assetsConfig.json");
	json j = j.parse(i);

	j.at("mapObjects").get_to(this->obiectsINFO);
	//std::cout << this->obiectsINFO[0][0] << std::endl;

	for (std::vector<int> tab : this->obiectsINFO) {
		sf::RectangleShape tmpShape;
		tmpShape.setPosition(sf::Vector2f(tab[0], tab[1]));
		tmpShape.setSize(sf::Vector2f(tab[2], tab[3]));
		tmpShape.setFillColor(sf::Color(100, 10, 250));
		this->mapObjects.push_back(tmpShape);
	}
}

Map::~Map()
{
}
