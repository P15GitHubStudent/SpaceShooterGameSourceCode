#pragma once

#include<SFML\Graphics.hpp>
#include"BackGrounds.h"
#include"AbstactMap.h"

class Map1:public Map
{
public:
	Map1();
   ~Map1();
   static void InitializeMap();
   void createMap();
   void update();
private:
	sf::Vector2f bgVelocity;
	sf::Vector2f MgVelocity;
	sf::Vector2f FgVelocity;
	BackGrounds BG;
	BackGrounds MG;
	BackGrounds FG;
	virtual  void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	static sf::Texture BGText;
	static sf::Texture MGText;
	static sf::Texture FGText;
};
