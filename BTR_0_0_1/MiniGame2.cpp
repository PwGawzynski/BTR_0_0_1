#include "MiniGame2.h"
#include "GameState.h"

MiniGame2::MiniGame2()
{
	std::cout << "CONSTRUCTOR OF MINIGAME2 HAS BEEN COLD" << "\n";

}

MiniGame2::MiniGame2(sf::RenderWindow* target)
// map 6 bo w mapobject6 w json damy od kabli 
	:States(4), Map(7)
{
	std::cout << "OVERLADED CONSTRUCTOR OF MINIGAME2 HAS BEEN COLD" << "\n";
	this->window = target;
	this->last_clicked_flag = 0;
	this->miniGame1Counter = 0;
	this->createBTNs();
	this->renderSelfStateObject();

}

MiniGame2::~MiniGame2()
{
	std::cout << "DECONSTRUCTOR OF MINIGAME2 HAS BEEN COLD" << "\n";
}

void MiniGame2::movePlayer(sf::Vector2f delta)
{
	this->playerSprite.move(delta);
	this->nextFrame();
}


void MiniGame2::update_interface(int a)
{
	this->miniGame1Counter_map++;
	std::cout << this->miniGame1Counter_map << "map" << std::endl;
	this->InterfaceObiectsINFO.emplace_back("assets/interface1.PNG");
}

int MiniGame2::update()
{

	return 0;
}

void MiniGame2::render()
{
	this->renderSprites();
}

void MiniGame2::renderSprites()
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

void MiniGame2::renderSelfStateObject()
{
	this->updateInterface();
	std::cout << "change" << std::endl;
}

void MiniGame2::createBTNs()
{
}

void MiniGame2::updateMouse()
{
	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
}

int MiniGame2::handleBTNpresseing()
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
					return 6;
				}
				return 5;
			}
		}
		ctr++;
	}

	return 0;
}

void MiniGame2::pop_interface_states()
{
}

void MiniGame2::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds();
}
