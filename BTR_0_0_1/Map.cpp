#include "Map.h"

using json = nlohmann::json;

Map::Map(int map_nr)
{
	this->mapNO = map_nr;
	// INFO ABOUT CONSTRUCTOR
	std::cout << "OVERLOAD CONSTRUCTOR OF MAP CLASS HAS BEEN COLD" << std::endl;

	this->updateMap();
	
}

Map::Map()
{
	std::cout << "DEFAULT CONSTRUCTOR OF MAP CLASS HAS BEEN COLD" << std::endl;

}

Map::~Map()
{
}

void Map::updateMap()
{
	std::ifstream i("config/assetsConfig.json");
	json j = j.parse(i);

	std::string mapPath = "mapObjects" + std::to_string(this->mapNO);


	/* EACH TAB CONTAINS SUCH INFO
	 * t[0]	X-CORD,
	 * t[1]	Y-CORD,
	 * t[2]	X-SIZE,
	 * t[3]	Y-SIZE,
	 * t[4]	OBJECT-ID
	 * t[5] OBJECT-COLOR-R
	 * t[6] OBJECT-COLOR-G
	 * t[7] OBJECT-COLOR-B
	 * t[8] OBJECT-IS-WALL
	 * t[9] OBJECT-ID-NEXT-PICTURE ( This must be NO of el. in pathsArrGame arr in json (counted from 0))
	 * t[10] PLAYER NEXT POS X
	 * t[10] PLAYER NEXT POS Y
	 */
	j.at(mapPath).get_to(this->obiectsINFO);




	for (std::vector<int> tab : this->obiectsINFO) {
		sf::RectangleShape tmpShape;
		tmpShape.setPosition(sf::Vector2f(tab[0], tab[1]));
		tmpShape.setSize(sf::Vector2f(tab[2], tab[3]));
		tmpShape.setFillColor(sf::Color(tab[5], tab[6], tab[7]));
		this->mapObjects.push_back(tmpShape);
	}
}
