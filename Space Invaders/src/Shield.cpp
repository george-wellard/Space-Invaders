#include "Shield.h"

Shield::Shield(GameDataRef data) : _data(data)
{
	shield.setTexture(_data->assets.GetTexture("Shield Texture"));

	shield.setTextureRect(shieldCut);

	shield.setOrigin(shield.getGlobalBounds().width / 2, shield.getGlobalBounds().height / 2);
}

void Shield::setPos(float x, float y)
{
	shield.setPosition(x, y);
}

void Shield::removeLife()
{
	shieldCut.left += 50;

	shield.setTextureRect(shieldCut);
}

void Shield::Draw()
{
	_data->window.draw(shield);
}

sf::Sprite& Shield::getSprite()
{
	return shield;
}
