#include "Win.h"
#include "MiniGame2.h"
#include "GameState.h"

Win::Win()
{
	std::cout << "CONSTRUCTOR OF MINIGAME2 HAS BEEN COLD" << "\n";

}

Win::Win(sf::RenderWindow* target)
// map 6 bo w mapobject6 w json damy od kabli 
	:States(5), Map(8)
{
	std::cout << "OVERLADED CONSTRUCTOR OF MINIGAME2 HAS BEEN COLD" << "\n";
	this->window = target;
	this->last_clicked_flag = 0;
	this->miniGame1Counter = 0;
	this->createBTNs();
	this->renderSelfStateObject();

}

Win::~Win()
{
	std::cout << "DECONSTRUCTOR OF MINIGAME2 HAS BEEN COLD" << "\n";
}

void Win::movePlayer(sf::Vector2f delta)
{
	this->playerSprite.move(delta);
	this->nextFrame();
}


void Win::update_interface(int a)
{
	this->miniGame1Counter_map++;
	std::cout << this->miniGame1Counter_map << "map" << std::endl;
	this->InterfaceObiectsINFO.emplace_back("assets/interface1.PNG");
}

int Win::update()
{

	return 0;
}

void Win::render()
{
	this->renderSprites();
}

void Win::renderSprites()
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

void Win::renderSelfStateObject()
{
	this->updateInterface();
	std::cout << "change" << std::endl;
}

void Win::createBTNs()
{
}

void Win::updateMouse()
{
	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
}

int Win::handleBTNpresseing()
{
	int ctr = 0;

	for (sf::RectangleShape shape : this->mapObjects) {
		// jak ma -1 to mozna klikac
		if (this->obiectsINFO[ctr][8] == 10)
		{
			if (shape.getGlobalBounds().contains(this->mousePositionView))
			{
				// jak = 1 to wygral
				if (this->obiectsINFO[ctr][9] == 11)
				{
					return 7;
				}
				return 0;
			}
		}
		ctr++;
	}

	return 0;
}

void Win::pop_interface_states()
{
}

void Win::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds();
}
