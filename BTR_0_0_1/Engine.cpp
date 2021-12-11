#include "Engine.h"

Engine::Engine()
{
	this->initWindow();
	this->renderIcon();
	this->initStack();

}


Engine::~Engine()
{
	delete this->window;
}

void Engine::initWindow()
{
	this->video = sf::VideoMode(1920, 1080);
	this->window = new sf::RenderWindow(this->video, "BEAT THE ROBRCIK");
}

void Engine::initStack()
{
	this->statesStack.push(new MenuState(this->window));
}

void Engine::renderIcon()
{
	sf::Image sorce;
	sorce.loadFromFile("assets/icon.png");
	this->window->setIcon(32, 32, sorce.getPixelsPtr());
}

void Engine::checkClicking()
{
	switch (this->statesStack.top()->handleBTNpresseing())
	{
	case 1:
		std::cout << "PLAY" << std::endl;
		this->statesStack.push(new GameState(this->statesStack.top()->window));
		break;
	case 2:
		// here is "while" loop, bc'f we can play then go to menu then play and then click empty
		// and in this case stack will be filled of meny state objects.
		std::cout << "EXIT" << std::endl;
		while (!this->statesStack.empty())
		{
			this->statesStack.pop();
			std::cout << "CLEARING STASCK OF STATES" << std::endl;
		}
		break;
	case 3:
		std::cout << "CLICK ON SHAPE" << std::endl;
		break;
	default:
		break;
	}
}

void Engine::updateSFMLEvents()
{
	while (this->window->pollEvent(this->ev) && !this->statesStack.empty())
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			// when stack is elilled for egz. when we are in game state wee need to clear this sytack to bottom 
			// becouse only then winndow is propelly closed:: memory lakes.
			while (!this->statesStack.empty())
			{
				this->statesStack.pop();
				std::cout << "CLEARING STASCK OF STATES" << std::endl;
			}
			this->window->close();
			break;
		case sf::Event::MouseMoved:
			this->statesStack.top()->updateMouse();
			break;
		case sf::Event::MouseButtonPressed:
			std::cout << "CLICK OCCURED" << "\n";
			this->checkClicking();
			break;
		case sf::Event::KeyPressed:
			/*if (this->ev.key.code == sf::Keyboard::Right)
			{
				this->statesStack.top()->movePlayer(sf::Vector2f(10.f, 0.f));
			}
			else if (this->ev.key.code == sf::Keyboard::Left)
			{
				this->statesStack.top()->movePlayer(sf::Vector2f(-10.f, 0.f));
			}
			else if (this->ev.key.code == sf::Keyboard::Down)
			{
				this->statesStack.top()->movePlayer(sf::Vector2f(0.f, -10.f));
			}
			else if (this->ev.key.code == sf::Keyboard::Up)
			{
				this->statesStack.top()->movePlayer(sf::Vector2f(0.f, 10.f));
			}*/
		break;
		default:
			break;
		}
	}
}

void Engine::update()
{
	this->statesStack.top()->update();
	this->updateSFMLEvents();

}

void Engine::render()
{
	this->window->clear();
	this->statesStack.top()->render();
	this->window->display();
}

void Engine::run()
{
	while (this->window->isOpen() && !this->statesStack.empty())
	{
		this->statesStack.top()->updateDT();
		this->render();
		this->update();
	}

	this->window->close();
}



