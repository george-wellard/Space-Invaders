#pragma once
#include "SFML/Graphics.hpp"
#include "Definitions.h"
#include "Game.h"
#include <iostream>

class Player
{
public:
	Player(GameDataRef data); 

	void Move(sf::Event event); 

	void Stop(sf::Event event);

	void Draw();

	void Death();

	sf::Sprite getSprite();

private:

	GameDataRef _data;

	float speed = 10.0f;

	sf::Sprite player;

	sf::Texture playerTex;
};

