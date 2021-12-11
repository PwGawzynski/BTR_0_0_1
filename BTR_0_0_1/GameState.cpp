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
}

GameState::~GameState()
{
	std::cout << "DECONSTRUCTOR OF GAMESTATE HAS BEEN COLD" << "\n";
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
