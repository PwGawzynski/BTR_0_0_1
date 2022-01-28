#include "GameState.h"


/**
 * \brief Konstruktor bez parametow
 */
GameState::GameState()
{
	std::cout << "CONSTRUCTOR OF GAMESTATE HAS BEEN COLD" << "\n";
}
/**
 * \brief Konstruktor z parametrami
 */
GameState::GameState(sf::RenderWindow* target)
	:States(2), Map(0)
{
	std::cout << "OVERLADED CONSTRUCTOR OF GAMESTATE HAS BEEN COLD" << "\n";
	this->window = target;
	this->createBTNs();
	this->renderSelfStateObject();
	
}
/**
 * \brief Dekonstruktor GameState
 */
GameState::~GameState()
{
	std::cout << "DECONSTRUCTOR OF GAMESTATE HAS BEEN COLD" << "\n";
}

/**
 * \brief Metoda obslugujaca ruch gracza
 */
void GameState::movePlayer(sf::Vector2f delta)
{
	this->playerSprite.move(delta);
	this->nextFrame();
}

/**
 * \brief Metoda wykrywajaca wcisniecie klawiszy sluzacych do poruszania sie oraz odpowiednio na nie reaguje
 */
int GameState::update()
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
	int shape_nr = 0;

	for (auto& shape : this->mapObjects)
	{
		sf::FloatRect obstacle = shape.getGlobalBounds();
		

		if (obstacle.intersects(playerNext))
		{
			// tutaj akcje z kolizjami zwiazane
			std::cout << "COLISION" << std::endl;
			/* CHEEK IF COLISION WITH WALL*/
			if (this->obiectsINFO[shape_nr][8]==1)
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
			else if (this->obiectsINFO[shape_nr][8]==2)
			{
				std::cout << "ROBERT" << std::endl;
				return 3;
			}
			else if (this->obiectsINFO[shape_nr][8] == 3)
			{
				
				std::cout << "PUSZKA" << std::endl;
				return 1;
			}
			else if (this->obiectsINFO[shape_nr][8] == 4)
			{
				std::cout << "KOMP" << std::endl;
				return 2;
			}

			movement.x *= (0.0);
			movement.y *= (0.0);
			std::cout << movement.x << std::endl;
			this->movePlayer(movement);
			return 0;
		}
		shape_nr++;
	}
	if(movement.y || movement.x)
	this->movePlayer(movement);
	return 0;
}
/**
 * \brief Nadpisuje metode z klasy abstrakcyjnej sluzacej do renderowania
 */
void GameState::render()
{
	
	this->renderSprites();
}
/**
 * \brief Nadpisuje metode z klasy abstrakcyjnej sluzacej do renderowania tekstur
 */
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

	for(sf::Texture sorce : this->interfaceObjects)
	{
		sf::Sprite TS;
		TS.setTexture(sorce);
		this->window->draw(TS);
	}
}
/**
 * \brief Metoda renderuje szczegolne obiekty dla klasy SelfState
 */
void GameState::renderSelfStateObject()
{
	this->updateInterface();
}

void GameState::createBTNs()
{
}

/**
 * \brief Metoda wykrywa pozycji myszki
 */
void GameState::updateMouse()
{
	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
}
/**
 * \brief Metoda wykrywa obiekt klikalny
 */
int GameState::handleBTNpresseing()
{
	for (sf::RectangleShape shape : this->mapObjects) {
		if (shape.getGlobalBounds().contains(this->mousePositionView)) return 3;
	}
}
/**
 * \brief Metoda aktualizujaca Data Time
 */
void GameState::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds();
}
/**
 * \brief Metoda odpowiedzialna aktualizacje interfejsu uzytkownika
 */
void GameState::pop_interface_states()
{
	this->pop_interface_map();
}
// marge

