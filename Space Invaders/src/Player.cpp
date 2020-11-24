#include "Player.h"

Player::Player(GameDataRef data) : _data(data)
{

	player.setTexture(_data->assets.GetTexture("Player Texture"));
	player.setPosition(450, 800);
	player.setOrigin(player.getGlobalBounds().width / 2, player.getGlobalBounds().height / 2);
}

void Player::Move(sf::Event event)
{

	if (sf::Keyboard::Key::Right == event.key.code)
	{
		player.move(speed, 0);
	}

	if (sf::Keyboard::Key::Left == event.key.code)
	{
		player.move(-speed, 0);
	}
}

void Player::Stop(sf::Event event)
{
	if (sf::Keyboard::Key::Right == event.key.code)
	{
		player.move(-speed, 0);
	}

	if (sf::Keyboard::Key::Left == event.key.code)
	{
		player.move(+speed, 0);
	}
}

void Player::Draw()
{
	_data->window.draw(player);
}

void Player::Death()
{
	player.setPosition(0, 1000);
}

sf::Sprite Player::getSprite()
{
	return player;
}
