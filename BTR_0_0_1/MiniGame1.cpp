#include "MiniGame1.h"
#include "GameState.h"

MiniGame1::MiniGame1()
{
	std::cout << "CONSTRUCTOR OF GAMESTATE HAS BEEN COLD" << "\n";

}

MiniGame1::MiniGame1(sf::RenderWindow* target)
// map 6 bo w mapobject6 w json damy od kabli 
	:States(3), Map(6)
{
	std::cout << "OVERLADED CONSTRUCTOR OF GAMESTATE HAS BEEN COLD" << "\n";
	this->window = target;
	this->last_clicked_flag = 0;
	this->miniGame1Counter = 0;
	this->createBTNs();
	this->renderSelfStateObject();

}

MiniGame1::~MiniGame1()
{
	std::cout << "DECONSTRUCTOR OF GAMESTATE HAS BEEN COLD" << "\n";
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
	/* GET NEXT MOVE OF PLAYER */
	sf::Vector2f movement = sf::Vector2f(0.f, 0.f);

	float velocity = 300.f;
	/* PREDICTING */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= velocity * this->dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += velocity * this->dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= velocity * this->dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += velocity * this->dt;

	sf::FloatRect playerNext = this->playerSprite.getGlobalBounds();
	playerNext.left += movement.x;
	playerNext.top += movement.y;
	int shape_nr = 0;

	for (auto& shape : this->mapObjects)
	{
		sf::FloatRect obstacle = shape.getGlobalBounds();


		if (obstacle.intersects(playerNext))
		{
			// tutaj akcje z kolizjami zwiazane
			std::cout << "COLISION" << std::endl;
			/* CHEEK IF COLISION WITH WALL*/
			if (this->obiectsINFO[shape_nr][8])
			{
				std::cout << "DOOR" << std::endl;
				this->imgStart = this->obiectsINFO[shape_nr][9];
				this->renderStateNO();
				this->playerSprite.setPosition(sf::Vector2f(
					(float)this->obiectsINFO[shape_nr][10],
					(float)this->obiectsINFO[shape_nr][11]
				));

				// TUTAJ ZROBIC WYKRYWANIE Z OBIEKTAMI 

				// SWITH to render obiect of new map
				this->mapNO = obiectsINFO[shape_nr][9];
				while (!this->mapObjects.empty())
					this->mapObjects.pop_back();
				this->updateMap();

				// THIS CLEARS VECTOR FROM OLD BMT 
				this->textures.pop_front();
			}
			movement.x *= (0.0);
			movement.y *= (0.0);
			std::cout << movement.x << std::endl;
			this->movePlayer(movement);
			return 0;
		}
		shape_nr++;
	}
	if (movement.y || movement.x)
		this->movePlayer(movement);
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


	/* DRAWING PLAYER SECTION THIS HAVE TO BE AT LEAST, OR PLAYER WOULD GO UNDER SOME SHAPES, SOMETIMES WE WOULD
	 * LIKE TO HANGE IT TO LET PLAYER BE COVER BY SOMETHING*/
	this->window->draw(this->playerSprite);

	for (sf::Texture sorce : this->interfaceObjects)
	{
		sf::Sprite TS;
		TS.setTexture(sorce);
		this->window->draw(TS);
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
			std::cout << "jest -1" << ctr << std::endl;
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
							texture.setFillColor(sf::Color(255, 255, 255));
						}
						i++;
					}
					// to last clicked ma odpowiadc nr tablicy w mapOBj6 ktora opisuje kabel  loczac od 0 
					std::cout<<" rowne " << this->last_clicked_flag << "   " << new_clicked << std::endl;
					std::cout << "CLICK : " << this->last_clicked_flag << std::endl;
					//tu tworzenie kabli i push do listy z obiektami do rysowania do koloru mozna sie dobrac przez object info

					return this->last_clicked_flag;
				}
				
			}
		}
		ctr++;
	}

	return -1;
}

void MiniGame1::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds();
}
