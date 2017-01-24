#pragma once

#include<SFML\Graphics.hpp>

class Map:public sf::Drawable
{
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const = 0;
public:
	virtual void createMap() = 0;
	virtual void update()=0;
	virtual ~Map(){}
};



