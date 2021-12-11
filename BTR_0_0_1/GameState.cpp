#include "GameState.h"

GameState::GameState()
{
	std::cout << "CONSTRUCTOR OF GAMESTATE HAS BEEN COLD" << "\n";

}

GameState::GameState(sf::RenderWindow* target)
	:States(2), Map()
{
	std::cout << "OVERLADED CONSTRUCTOR OF GAMESTATE HAS BEEN COLD" << "\n";
	this->window = target;
	this->createBTNs();
	this->createPlayer();
}

GameState::~GameState()
{
	std::cout << "DECONSTRUCTOR OF GAMESTATE HAS BEEN COLD" << "\n";
}

void GameState::createPlayer()
{
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

void GameState::update()
{

}

void GameState::render()
{
	this->renderSprites();
}

void GameState::renderSprites()
{
	for (sf::Texture sorce : this->textures) {
		sf::Sprite TS;
		TS.setTexture(sorce);
		this->window->draw(TS);
	}
	for (sf::RectangleShape shape : this->mapObjects) {
		this->window->draw(shape);
	}


	/* DRAWING PLAYER SECTION THIS HAVE TO BE AT LEAST, OR PLAYER WOULD GO UNDER SOME SHAPES, SOMETIMES WE WOULD
	 * LIKE TO HANGE IT TO LET PLAYER BE COVER BY SOMETHING*/
	this->window->draw(this->playerSprite);
}

void GameState::renderSelfStateObject()
{

}

void GameState::createBTNs()
{
}

void GameState::updateMouse()
{
	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
}

int GameState::handleBTNpresseing()
{
	for (sf::RectangleShape shape : this->mapObjects) {
		if (shape.getGlobalBounds().contains(this->mousePositionView)) return 3;
	}
}
