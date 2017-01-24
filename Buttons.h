#pragma once

#include<SFML\Graphics.hpp>


enum class ButtonColors{Red,Green};

class Buttons : public sf::Drawable 
{

private:
	ButtonColors ButtonColor;
	sf::Sprite Sprite;
	sf::Texture texture;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
public:
	Buttons & operator () (const sf::Vector2f & Pos);
	void setButtonPos(const sf::Vector2f & Pos);
	Buttons(ButtonColors buttonColor);
	void setButtonColor(ButtonColors Button);
	~Buttons();
};

