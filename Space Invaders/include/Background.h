#pragma once
#include "SFML/Graphics.hpp"
#include "Definitions.h"
#include "Game.h"
#include <iostream>

class Background
{
public:

	Background(GameDataRef data); 

	void Draw();

	sf::Sprite getSprite();

private:

	GameDataRef _data;

	sf::Sprite background;

	sf::Texture backgroundTex;
};

