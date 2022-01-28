#include "States.h"
/**
 * \brief Konstruktor klasy abstrakcyjnej States
 */
States::States()
{

}
/**
 * \brief Konstruktor klasy abstrakcyjnej States z parametrami
 */
States::States(int state)
	:TexturesContainer(state)
{
}
/**
 * \brief Dekonstruktor klasy abstrakcyjnej States
 */
States::~States()
{
	//delete this->window;
}


