#include "Invader.h"

Invader::Invader(GameDataRef data) : _data(data)
{
	invader.setTexture(_data->assets.GetTexture("Invader Texture"));
}

void Invader::setPos(float x, float y)
{
	invader.setPosition(x, y);
}

void Invader::Move(sf::Event event)
{
	invader.move(speed, 0);

	if (invader.getPosition().x > 890)
	{
		invader.move(--speed, 0);
		invader.setPosition(invader.getPosition().x, invader.getPosition().y + moveDown);
	}

	if (invader.getPosition().x < 0)
	{
		invader.move(++speed, 0);
		invader.setPosition(invader.getPosition().x, invader.getPosition().y + moveDown);
	}
}

void Invader::Move2(sf::Event event)
{
	invader.move(--speed, 0);
}

void Invader::Draw()
{
	_data->window.draw(invader);
}

sf::Sprite Invader::getSprite()
{
	return invader;
}
