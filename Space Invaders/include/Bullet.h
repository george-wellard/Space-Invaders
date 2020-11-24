#pragma once
#include "SFML/Graphics.hpp"
#include "Definitions.h"
#include "Game.h"
#include <iostream>

class Bullet
{
public:

	Bullet(GameDataRef data);

	void setPos(float x, float y);

	void Fire(float speed);

	void Draw(); 

	sf::Sprite getSprite();

	//sf::Texture bulletTex;

private:

	GameDataRef _data;

	sf::Sprite bullet;

	//sf::RectangleShape bullet;

};

