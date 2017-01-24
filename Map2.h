

#pragma once

#include<SFML\Graphics.hpp>
#include"BackGrounds.h"
#include"AbstactMap.h"

class Map2:public Map
{
public:
	Map2();
	~Map2();
	static void InitializeMap();
	void createMap();
	void update();
private:
	sf::Vector2f bgVelocity;
	sf::Vector2f MgVelocity;
	BackGrounds BG;
	BackGrounds MG;
	BackGrounds FG;
	virtual  void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	static sf::Texture BGText;
	static sf::Texture MGText;
	static sf::Texture FGText;
};
