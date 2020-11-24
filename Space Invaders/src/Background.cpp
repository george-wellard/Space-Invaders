#include "Background.h"

Background::Background(GameDataRef data) : _data(data)
{

	background.setTexture(_data->assets.GetTexture("Background Texture"));
}

void Background::Draw()
{
	_data->window.draw(background);
}

sf::Sprite Background::getSprite()
{
	return background;
}
