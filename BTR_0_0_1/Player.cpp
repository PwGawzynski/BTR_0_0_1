#include "Player.h"

Player::Player()
{

	std::cout << "PLAYER DEFAULT CONSTRUCTOR(ONLY ONE) HAS BEEN COLD" << std::endl;


	std::string playerP;


	std::ifstream d("config/assetsConfig.json");
	nlohmann::json j = j.parse(d);
	j.at("playerPATH").get_to(playerP);


	sf::Texture tmp;
	tmp.loadFromFile(playerP);
	this->playerTX = tmp;
	sf::Sprite player;
	player.setTexture(this->playerTX);
	this->playerSprite = player;
}

Player::~Player()
{
}
