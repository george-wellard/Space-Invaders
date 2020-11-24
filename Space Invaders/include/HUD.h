#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
#include <iostream>

class HUD
{
public:

	HUD(GameDataRef data);

	void Draw();

	void Update(int lives);

private:

	GameDataRef _data;

	sf::Text text;

	sf::Font font;
};

