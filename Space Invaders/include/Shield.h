#pragma once
#include "SFML/Graphics.hpp"
#include "Definitions.h"
#include "Game.h"
#include <iostream>

class Shield
{
public:

	Shield(GameDataRef data); 

	void setPos(float x, float y);

	void removeLife();

	void Draw();

	sf::Sprite& getSprite();

private:

	GameDataRef _data;

	sf::Sprite shield; 

	sf::Texture shieldTex;

	sf::IntRect shieldCut = sf::IntRect(0, 0, 60, 50);

	int life = 3;
};

