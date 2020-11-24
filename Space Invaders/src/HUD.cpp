#include "HUD.h"

HUD::HUD(GameDataRef data) : _data(data)
{
	text.setFont(_data->assets.GetFont("Font"));

	text.setString("3");

	text.setCharacterSize(44);

	text.setFillColor(sf::Color::White);

	text.setPosition(10, 10);
}

void HUD::Draw()
{
	_data->window.draw(text);
}

void HUD::Update(int lives)
{
	text.setString(std::to_string(lives));
}
