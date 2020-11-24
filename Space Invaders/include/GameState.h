#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "State.h"
#include "StateMachine.h"
#include "Game.h"
#include "Definitions.h"
#include "AssetManager.h"
#include "Background.h"
#include "Player.h"
#include "Bullet.h"
#include "Invader.h"
#include "Collision.h"
#include "HUD.h"
#include "Shield.h"

class GameState : public State
{
public:

	GameState(GameDataRef data); 

	void Init();

	void HandleInput();

	void Update(float dt);

	void Draw(float dt);

private:

	GameDataRef _data;

	sf::Event event;

	sf::RenderWindow* window;
	sf::Clock _clock;

	Background* background;
	Player* player;
	Bullet* bullet;
	Invader* invader;
	Collision collision;
	HUD* hud;
	Shield* shield;

	std::vector<Bullet> bullets;
	std::vector<Bullet> badBullets;
	std::vector<Invader> invaders;
	std::vector<Shield> shields;

	bool isFiring = false;

	const int iInvader = 6;
	const int iShield = 3;

	int lives = 3;
	int shieldLife1 = 3;
	int shieldLife2 = 3;
	int shieldLife3 = 3;

};