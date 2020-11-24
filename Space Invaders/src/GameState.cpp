#include "GameState.h"

GameState::GameState(GameDataRef data) : _data(data)
{
}

void GameState::Init()
{
	_data->assets.LoadTexture("Player Texture", PLAYER_TEX);
	_data->assets.LoadTexture("Background Texture", BACKGROUND_TEX);
	_data->assets.LoadTexture("Invader Texture", INVADER_TEX);
	_data->assets.LoadTexture("Bullet Texture", BULLET_TEX);
	_data->assets.LoadTexture("Shield Texture", SHIELD_TEX);

	_data->assets.LoadFont("Font", FONT);

	background = new Background(_data);
	player = new Player(_data);
	hud = new HUD(_data);

	Invader invader1(_data);
	Invader invader2(_data);
	Invader invader3(_data);
	Invader invader4(_data);
	Invader invader5(_data);
	Invader invader6(_data);

	invader1.setPos(100, 50);
	invader2.setPos(100, 100);
	invader3.setPos(200, 50);
	invader4.setPos(200, 100);
	invader5.setPos(300, 50);
	invader6.setPos(300, 100);

	invaders.push_back(invader1);
	invaders.push_back(invader2);
	invaders.push_back(invader3);
	invaders.push_back(invader4);
	invaders.push_back(invader5);
	invaders.push_back(invader6);

	Shield shield1(_data);
	Shield shield2(_data);
	Shield shield3(_data);

	shield1.setPos(150, 700);
	shield2.setPos(450, 700);
	shield3.setPos(750, 700);

	shields.push_back(shield1);
	shields.push_back(shield2);
	shields.push_back(shield3);
}

void GameState::HandleInput()
{

	while (_data->window.pollEvent(event))
	{

		if (sf::Event::Closed)
		{
			_data->window.close();
		}

		if (sf::Event::KeyPressed)
		{
			player->Move(event);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			isFiring = true;
		}
	}
}

void GameState::Update(float dt)
{
	if (player->getSprite().getPosition().x > 900 || player->getSprite().getPosition().x < 0)
	{
		player->Stop(event);
	}

	for (int i = 0; i < invaders.size(); i++)
	{
		invaders[i].Move(event);

	}

	if (isFiring)
	{
		Bullet newBullet(_data);
		newBullet.setPos(player->getSprite().getPosition().x, player->getSprite().getPosition().y);
		bullets.push_back(newBullet);
		isFiring = false;
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].Fire(-10);
	}

	if (_clock.getElapsedTime().asSeconds() > rand() % 3000)
	{
		Bullet badBullet(_data);
		badBullet.setPos(invaders.at(0).getSprite().getPosition().x, invaders.at(0).getSprite().getPosition().y);
		badBullets.push_back(badBullet);
		_clock.restart();
	}

	if (_clock.getElapsedTime().asSeconds() > rand() % 3000)
	{
		Bullet badBullet2(_data);
		badBullet2.setPos(invaders.at(1).getSprite().getPosition().x, invaders.at(1).getSprite().getPosition().y);
		badBullets.push_back(badBullet2);
		_clock.restart();
	}

	if (_clock.getElapsedTime().asSeconds() > rand() % 3000)
	{
		Bullet badBullet3(_data);
		badBullet3.setPos(invaders.at(2).getSprite().getPosition().x, invaders.at(3).getSprite().getPosition().y);
		badBullets.push_back(badBullet3);
		_clock.restart();
	}

	if (_clock.getElapsedTime().asSeconds() > rand() % 3000)
	{
		Bullet badBullet4(_data);
		badBullet4.setPos(invaders.at(3).getSprite().getPosition().x, invaders.at(3).getSprite().getPosition().y);
		badBullets.push_back(badBullet4);
		_clock.restart();
	}

	if (_clock.getElapsedTime().asSeconds() > rand() % 3000)
	{
		Bullet badBullet5(_data);
		badBullet5.setPos(invaders.at(4).getSprite().getPosition().x, invaders.at(4).getSprite().getPosition().y);
		badBullets.push_back(badBullet5);
		_clock.restart();
	}

	if (_clock.getElapsedTime().asSeconds() > rand() % 3000)
	{
		Bullet badBullet6(_data);
		badBullet6.setPos(invaders.at(5).getSprite().getPosition().x, invaders.at(5).getSprite().getPosition().y);
		badBullets.push_back(badBullet6);
		_clock.restart();
	}

	for (int i = 0; i < badBullets.size(); i++)
	{
		badBullets[i].Fire(5);
	}

	for (int i = 0; i < invaders.size(); i++)
	{
		for (int j = 0; j < bullets.size(); j++)
		{
			if (collision.CheckSpriteCollision(invaders[i].getSprite(), bullets[j].getSprite()))
			{
				invaders.erase(invaders.begin() + i);
				bullets.erase(bullets.begin() + j);
			}
		}
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].getSprite().getPosition().y < 0)
		{
			bullets.erase(bullets.begin() + i);
		}
	}

	for (int i = 0; i < badBullets.size(); i++)
	{
		if (collision.CheckSpriteCollision(player->getSprite(), badBullets[i].getSprite()))
		{
			badBullets.erase(badBullets.begin() + i);
			lives--;
		}
	}

	for (int i = 0; i < shields.size(); i++)
	{
		for (int j = 0; j < bullets.size(); j++)
		{
			if (collision.CheckSpriteCollision(shields[i].getSprite(), bullets[j].getSprite()))
			{
				bullets.erase(bullets.begin() + j);
			}
		}
	}

	for (int j = 0; j < badBullets.size(); j++)
	{
		if (collision.CheckSpriteCollision(shields.at(0).getSprite(), badBullets[j].getSprite()))
		{
			badBullets.erase(badBullets.begin() + j);
			shieldLife1--;
		}
	}

	for (int j = 0; j < badBullets.size(); j++)
	{
		if (collision.CheckSpriteCollision(shields.at(1).getSprite(), badBullets[j].getSprite()))
		{
			badBullets.erase(badBullets.begin() + j);
			shieldLife2--;
		}
	}

	for (int j = 0; j < badBullets.size(); j++)
	{
		if (collision.CheckSpriteCollision(shields.at(2).getSprite(), badBullets[j].getSprite()))
		{
			badBullets.erase(badBullets.begin() + j);
			shieldLife3--;
		}
	}

	for (int i = 0; i < badBullets.size(); i++)
	{
		if (badBullets[i].getSprite().getPosition().y > 900)
		{
			badBullets.erase(badBullets.begin() + i);
		}
	}

	hud->Update(lives);

	if (lives == 0)
	{
		player->Death();
	}

	if (shieldLife1 == 0)
	{
		//shields.erase(shields.begin());
		shields.at(0).setPos(-100, -100);
	}

	if (shieldLife2 == 0)
	{
		//shields.erase(shields.begin() + 1);
		shields.at(1).setPos(-100, -100);
	}

	if (shieldLife3 == 0)
	{
		//shields.erase(shields.begin() + 2);
		shields.at(2).setPos(-100, -100);
	}
}

void GameState::Draw(float dt)
{
	_data->window.clear();

	background->Draw();

	player->Draw();

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].Draw();
	}

	for (int i = 0; i < invaders.size(); i++)
	{
		invaders[i].Draw();
	}

	for (int i = 0; i < badBullets.size(); i++)
	{
		badBullets[i].Draw();
	}

	for (int i = 0; i < shields.size(); i++)
	{
		shields[i].Draw();
	}

	hud->Draw();

	_data->window.display();
}