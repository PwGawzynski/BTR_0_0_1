#include "MenuState.h"

MenuState::MenuState()
{
	std::cout << "DEFOULT CONSTRUCTOR OF MENUSTATE CLASS HAS BEEN COLD" << std::endl;
}


MenuState::MenuState(sf::RenderWindow* target)
	:States(1)
{
	std::cout << "OVERLADED CONSTRUCTOR OF MENUSTATE HAS BEEN COLD" << "\n";
	this->window = target;
	this->createBTNs();

}

MenuState::~MenuState()
{

}

void MenuState::update()
{

}

void MenuState::render()
{
	this->renderSprites();
	this->renderSelfStateObject();
}

void MenuState::renderSprites()
{
	for (sf::Texture sorce : this->textures) {
		sf::Sprite TS;
		TS.setTexture(sorce);
		this->window->draw(TS);
	}
}

void MenuState::renderSelfStateObject()
{
	this->window->draw(this->playBTN);
	this->window->draw(this->exitBTN);
}

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

void MenuState::updateMouse()
{
	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
}



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

void MenuState::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds();
}
