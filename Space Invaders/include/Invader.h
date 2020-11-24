#pragma once
#include "SFML/Graphics.hpp"
#include "Definitions.h"
#include "Game.h"
#include <iostream>

class Invader
{
public:

	Invader(GameDataRef data);

	Invader();

	void setPos(float x, float y);

	void Move(sf::Event event);

	void Move2(sf::Event event);

	void Draw();

	sf::Sprite getSprite();

private:

	GameDataRef _data;

	sf::Sprite invader;

	sf::Texture invaderTex;

	float speed = 0.5f;

	float moveDown = 10.0f;


};

