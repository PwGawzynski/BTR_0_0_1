#include "MenuState.h"
/**
 * \brief Kontruktor bez parametow klasy menu
 */
MenuState::MenuState()
{
	std::cout << "DEFOULT CONSTRUCTOR OF MENUSTATE CLASS HAS BEEN COLD" << std::endl;
}

/**
 * \brief Kontruktor z parametrami klasy menu
 */
MenuState::MenuState(sf::RenderWindow* target)
	:States(1)
{
	std::cout << "OVERLADED CONSTRUCTOR OF MENUSTATE HAS BEEN COLD" << "\n";
	this->window = target;
	this->createBTNs();
}
/**
 * \brief Dekonstruktor klasy menu
 */
MenuState::~MenuState()
{

}

int MenuState::update()
{
	return 0;
}
/**
 * \brief Renderowanie obiektow
 */
void MenuState::render()
{
	this->renderSprites();
	this->renderSelfStateObject();
}
/**
 * \brief Renderowanie tekstur
 */
void MenuState::renderSprites()
{
	for (sf::Texture sorce : this->textures) {
		sf::Sprite TS;
		TS.setTexture(sorce);
		this->window->draw(TS);
	}
}
/**
 * \brief Renderowanie wlasnych tekstur
 */
void MenuState::renderSelfStateObject()
{
	this->window->draw(this->playBTN);
	this->window->draw(this->exitBTN);
}
/**
 * \brief Tworzenie tekstur i szablonow dla przyciskow
 */
void MenuState::createBTNs()
{
	sf::RectangleShape playBtn;
	playBtn.setPosition(sf::Vector2f(293.f, 538.f));
	playBtn.setSize(sf::Vector2f(301.f, 165.f));
	playBtn.setFillColor(sf::Color(0, 0, 0, 0));
	this->playBTN = playBtn;
	sf::RectangleShape exitBtn;
	exitBtn.setPosition(sf::Vector2f(293.f, 710.f));
	exitBtn.setSize(sf::Vector2f(301.f, 165.f));
	exitBtn.setFillColor(sf::Color(0, 0, 0, 0));
	this->exitBTN = exitBtn;
}
/**
 * \brief Zczytywanie pozycji myszki
 */
void MenuState::updateMouse()
{
	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
}


/**
 * \brief Odczytywanie kliknienc
 */
int MenuState::handleBTNpresseing()
{
	if (this->playBTN.getGlobalBounds().contains(this->mousePositionView))
		return 1;
	if (this->exitBTN.getGlobalBounds().contains(this->mousePositionView))
		return 2;
}

void MenuState::movePlayer(sf::Vector2f delta)
{
}
/**
 * \brief Aktualizacja Data Time
 */
void MenuState::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void MenuState::pop_interface_states()
{
}
