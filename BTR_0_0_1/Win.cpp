#include "Win.h"
#include "MiniGame2.h"
#include "GameState.h"
/**
 * \brief Konstruktor Win
 */
Win::Win()
{
	std::cout << "CONSTRUCTOR OF MINIGAME2 HAS BEEN COLD" << "\n";

}
/**
 * \brief Konstruktor klasy Win z parametrami
 */
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
/**
 * \brief Dekonstruktor klasy Win
 */
Win::~Win()
{
	std::cout << "DECONSTRUCTOR OF MINIGAME2 HAS BEEN COLD" << "\n";
}
/**
 * \brief Metoda przesuwania gracza
 */
void Win::movePlayer(sf::Vector2f delta)
{
	this->playerSprite.move(delta);
	this->nextFrame();
}

/**
 * \brief Metoda aktualizujaca interface 
 */
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
/**
 * \brief Metoda renderuje tekstur
 */
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
/**
 * \brief Metoda renderuje tekstury wlasne
 */
void Win::renderSelfStateObject()
{
	this->updateInterface();
	std::cout << "change" << std::endl;
}

void Win::createBTNs()
{
}
/**
 * \brief Metoda wykrywajaca myszke
 */
void Win::updateMouse()
{
	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
}
/**
 * \brief Wykrywanie klikniec na elementy klikalne
 */
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
/**
 * \brief Aktualizacja Date Time
 */
void Win::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds();
}
