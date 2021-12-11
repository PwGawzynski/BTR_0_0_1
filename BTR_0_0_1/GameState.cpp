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

void GameState::movePlayer(sf::Vector2f delta)
{
	this->playerSprite.move(delta);
}


void GameState::update()
{
	/* GET NEXT MOVE OF PLAYER */
	sf::Vector2f movement = sf::Vector2f(0.f,0.f);

	float velocity = 300.f;
	/* PREDICTING */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= velocity * this->dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x +=velocity * this->dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -=velocity * this->dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y +=velocity * this->dt;

	sf::FloatRect playerNext = this->playerSprite.getGlobalBounds();
	playerNext.left += movement.x;
	playerNext.top += movement.y;

	for (auto& shape : this->mapObjects)
	{
		sf::FloatRect obstacle = shape.getGlobalBounds();
		

		if (obstacle.intersects(playerNext))
		{
			// tutaj akcje z kolizjami zwiazane
			std::cout << "COLISION" << std::endl;
			movement.x *= (-0.1);
			movement.y *= (-0.1);
			std::cout << movement.x << std::endl;
			this->movePlayer(movement);
			return;
		}

	}
	if(movement.y || movement.x)
	this->movePlayer(movement);
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

void GameState::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds();
}
