#include "Player.h"

Player::Player()
{
	std::cout << "PLAYER DEFAULT CONSTRUCTOR(ONLY ONE) HAS BEEN COLD" << std::endl;
	this->width = 133;
	this->hight = 189;
	this->animationStartY = 0;
	this->animationStartX = 0;
	this->frameCounter = 0;

	this->frameCounter = 0;

	std::string playerP;


	std::ifstream d("config/assetsConfig.json");
	nlohmann::json j = j.parse(d);
	j.at("playerPATH").get_to(playerP);


	sf::Texture tmp;
	tmp.loadFromFile(playerP);
	this->playerTX = tmp;
	sf::Sprite player;
	player.setTexture(this->playerTX);
	player.setTextureRect(sf::IntRect(0, 0, this->width, this->hight));
	this->playerSprite = player;
	this->playerSprite.setPosition(sf::Vector2f(500.f, 500.f));

}
Player::~Player()
{

}

void Player::nextFrame()
{
	if (this->framecuter == 20)
	{
		std::cout << this->framecuter << std::endl;
		if (this->frameCounter < 8)
		{
			this->animationStartX += this->width;

			this->frameCounter++;

			this->playerSprite.setTextureRect(sf::IntRect(
				this->animationStartX, 0, this->width, this->hight
			));
		}
		else
		{
			this->frameCounter = 0;
			this->animationStartX = 0;
		}

		this->framecuter = 0;
	}
	else this->framecuter++;
}


