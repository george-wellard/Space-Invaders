#include "Bullet.h"

Bullet::Bullet(GameDataRef data) : _data(data)
{
	bullet.setTexture(_data->assets.GetTexture("Bullet Texture"));
}

void Bullet::setPos(float x, float y)
{
	bullet.setPosition(x, y);
}

void Bullet::Fire(float speed)
{
	bullet.move(0, speed);
}

void Bullet::Draw()
{
	_data->window.draw(bullet);
}

sf::Sprite Bullet::getSprite()
{
	return bullet;
}
