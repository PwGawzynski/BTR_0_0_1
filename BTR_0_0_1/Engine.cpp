#include "Engine.h"

Engine::Engine()
{
	this->minigame_number = 0;
	this->accomplished = 0;
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
	int val_ret = this->statesStack.top()->handleBTNpresseing();
	switch (val_ret)
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
	case 4:
		std::cout << "CLICK ON SHAPE MINIGAME_KOMP" << std::endl;
			this->statesStack.top()->last_clicked_flag = 0;
			this->statesStack.top()->miniGame1Counter++;
			// tu sprawdzenie czy miniGameCounter == ilosc kabli i jesli tak to zdjecie minigame z stosu.
			if (this->statesStack.top()->miniGame1Counter == 4)
			{
				this->statesStack.pop();
				this->statesStack.top()->pop_interface_states();
				this->accomplished++;
			}
			this->statesStack.top()->renderSelfStateObject();
			std::cout << "match" << std::endl;
		
		// tutaj mozna zrobic do rysowania kabli tylko trzeba zwracac jakis nz z chandle
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

int Engine::update()
{
	// tu zmienianie minigier
	this->minigame_number = this->statesStack.top()->update();
	if (this->accomplished == 1 && this->minigame_number == 2) {
		this->statesStack.push(new MiniGame1(this->window));
		this->render();
		return 0;
	}
	else if (this->accomplished == 0 && this->minigame_number == 1)
	{
		this->statesStack.top()->pop_interface_states();
		this->accomplished++;
	}
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



