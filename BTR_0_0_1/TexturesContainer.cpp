#include "TexturesContainer.h"

using json = nlohmann::json;
/**
 * \brief Konstruktor klasy tekstur
 */
TexturesContainer::TexturesContainer()
{
	std::cout << "DEFOULT CONSTRUCTOR TEXTURECONTAINER USED" << std::endl;
}
/**
 * \brief Konstruktor klasy tekstur z parametrami
 */
TexturesContainer::TexturesContainer(int state)
{
	this->imgStart = 0;

	std::ifstream d("config/assetsConfig.json");
	json j = j.parse(d);

	this->updateCTR(state); 

	this->renderStateNO();
}
/**
 * \brief Metoda odpowiadajaca za przelaczanie stanow 
 */
void TexturesContainer::renderStateNO()
{
		sf::Texture tmp;
		tmp.loadFromFile(this->paths[this->imgStart]);
		this->textures.push_back(tmp);

}
/**
 * \brief Dekonstruktor klasy tekstur
 */
TexturesContainer::~TexturesContainer()
{
	std::cout << "TextureContainer Deconstructor is called" << "\n";
}
/**
 * \brief Metoda odpowiadajaca za pobieranie odpowiednich informacji z pliku json
 */
void TexturesContainer::updateCTR(int state)
{
	std::ifstream i("config/assetsConfig.json");
	json j = j.parse(i);
	switch (state)
	{
	case 1:
		j.at("pathsArrMenu").get_to(this->paths);
		this->imagesEnd = j.at("menuElements");
		break;
	case 2: // SPAWN GAME STATE TEXTURES
		j.at("pathsArrGame").get_to(this->paths);
		this->imagesEnd = j.at("gameElements");
		break;
	case 3:
		// HERE GOES ALL ABOUT MINIGAME 1 PATHS 
		j.at("MiniGame1Paths").get_to(this->paths);
		this->imagesEnd = j.at("MiniGame1Elements");
		break;
	case 4:
		// HERE GOES ALL ABOUT MINIGAME 1 PATHS 
		j.at("MiniGame2Paths").get_to(this->paths);
		this->imagesEnd = j.at("MiniGame2Elements");
		break;
	case 5:
		j.at("WIN").get_to(this->paths);
		this->imagesEnd = j.at("WINElements");
		break;
	case 6:
		j.at("LOST").get_to(this->paths);
		this->imagesEnd = j.at("LOSTElements");
		break;
	default:
		break;
	}
}
