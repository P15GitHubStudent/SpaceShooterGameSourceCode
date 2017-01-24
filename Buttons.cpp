#include "Buttons.h"
#include"Exceptions.h"


Buttons::Buttons(ButtonColors buttonColor)
{
	setButtonColor(buttonColor);

}

Buttons & Buttons::operator()(const sf::Vector2f & Pos)
{

	setButtonPos(Pos);

	return *this;
}

void Buttons::setButtonPos(const sf::Vector2f & Pos)
{
	Sprite.setPosition(Pos);
}

void Buttons::setButtonColor(ButtonColors ButtonColor)
{
	if (ButtonColor == ButtonColors::Red)
	{
		if (!texture.loadFromFile("images/greenButton.png"))throw FAILED_TO_LOAD_TEXTURE("images/greenButton.png");
	}
	else if (ButtonColor == ButtonColors::Green)
	{
		if (!texture.loadFromFile("images/redButton.png"))throw FAILED_TO_LOAD_TEXTURE("images/redButton.png");
	}
	
	Sprite.setTexture(texture);

}

void Buttons::draw(sf::RenderTarget & target, sf::RenderStates states)const
{
	target.draw(Sprite);
}

Buttons::~Buttons()
{
}
