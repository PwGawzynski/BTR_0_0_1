#include "TexturesContainer.h"

using json = nlohmann::json;

TexturesContainer::TexturesContainer()
{
	std::cout << "DEFOULT CONSTRUCTOR TEXTURECONTAINER USED" << std::endl;
}

TexturesContainer::TexturesContainer(int state)
{
	std::ifstream d("config/assetsConfig.json");
	json j = j.parse(d);

	this->updateCTR(state);

	for (int i = 0; i < this->imagesEnd; i++)
	{
		sf::Texture tmp;
		tmp.loadFromFile(this->paths[i]);
		this->textures.push_back(tmp);

	}
}

TexturesContainer::~TexturesContainer()
{
	std::cout << "TextureContainer Deconstructor is called" << "\n";
}

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
	case 2:
		j.at("pathsArrGame").get_to(this->paths);
		this->imagesEnd = j.at("gameElements");
		break;
	default:
		break;
	}
}
