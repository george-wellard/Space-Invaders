#include "AssetManager.h"

void AssetManager::LoadTexture(std::string name, std::string filename)
{
	sf::Texture tex;

	if (tex.loadFromFile(filename))
	{
		this->_textures[name] = tex;
	}
}

sf::Texture& AssetManager::GetTexture(std::string name)
{
	return this->_textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string filename)
{
	sf::Font fon;

	if (fon.loadFromFile(filename))
	{
		this->_fonts[name] = fon;
	}
}

sf::Font& AssetManager::GetFont(std::string name)
{
	return this->_fonts.at(name);
}