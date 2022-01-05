#include "MiniGame1.h"
#include "GameState.h"

MiniGame1::MiniGame1()
{
	std::cout << "CONSTRUCTOR OF MINIGAME1 HAS BEEN COLD" << "\n";

}

MiniGame1::MiniGame1(sf::RenderWindow* target)
// map 6 bo w mapobject6 w json damy od kabli 
	:States(3), Map(6)
{
	std::cout << "OVERLADED CONSTRUCTOR OF MINIGAME1 HAS BEEN COLD" << "\n";
	this->window = target;
	this->last_clicked_flag = 0;
	this->miniGame1Counter = 0;
	this->createBTNs();
	this->renderSelfStateObject();

}

MiniGame1::~MiniGame1()
{
	std::cout << "DECONSTRUCTOR OF MINIGAME1 HAS BEEN COLD" << "\n";
}

void MiniGame1::movePlayer(sf::Vector2f delta)
{
	this->playerSprite.move(delta);
	this->nextFrame();
}


void MiniGame1::update_interface(int a)
{
	this->miniGame1Counter_map++;
	std::cout << this->miniGame1Counter_map << "map" << std::endl;
	this->InterfaceObiectsINFO.emplace_back("assets/interface1.PNG");
}

int MiniGame1::update()
{
	
	return 0;
}

void MiniGame1::render()
{
	this->renderSprites();
}

void MiniGame1::renderSprites()
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

void MiniGame1::renderSelfStateObject()
{
		this->updateInterface();
		std::cout << "change" << std::endl;
}

void MiniGame1::createBTNs()
{
}

void MiniGame1::updateMouse()
{
	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
}

int MiniGame1::handleBTNpresseing()
{
	int ctr = 0;

	for (sf::RectangleShape shape : this->mapObjects) {
		// jak ma -1 to mozna klikac
		if(this->obiectsINFO[ctr][8] == 10)
		{
			if (shape.getGlobalBounds().contains(this->mousePositionView))
			{
				std::cout << "shape click" << std::endl;
				int new_clicked = this->obiectsINFO[ctr][9];
				std::cout << this->last_clicked_flag << "  " << new_clicked << std::endl;
				if (!this->last_clicked_flag) this->last_clicked_flag = new_clicked;
				else if (new_clicked == this->last_clicked_flag)
				{
					/*
					 * w tym JSON te 2 tablice musza byc 
					 */
					int i = 0;
					for (sf::RectangleShape &texture : this->mapObjects)
					{
						if (i == this->last_clicked_flag)
						{
							// tu if na kolory
							if (i == 8)
							texture.setFillColor(sf::Color(0, 0, 0));
							else if (i == 9)
								texture.setFillColor(sf::Color(54, 255, 0));
							else if (i == 10)
								texture.setFillColor(sf::Color(202, 40, 18));
							else if (i == 11)
								texture.setFillColor(sf::Color(0, 180, 255));
						}
						i++;
					}
					// to last clicked ma odpowiadc nr tablicy w mapOBj6 ktora opisuje kabel  loczac od 0 
					std::cout<<" rowne " << this->last_clicked_flag << "   " << new_clicked << std::endl;
					std::cout << "CLICK : " << this->last_clicked_flag << std::endl;
					//tu tworzenie kabli i push do listy z obiektami do rysowania do koloru mozna sie dobrac przez object info

					return 4;
				}
				
			}
		}
		ctr++;
	}

	return -1;
}

void MiniGame1::pop_interface_states()
{
}

void MiniGame1::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds();
}
