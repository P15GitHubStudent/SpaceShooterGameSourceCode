#pragma once

#include<SFML\Graphics.hpp>
#include"Entity.h"


class Bullets:public Entity
{
private:
	sf::CircleShape bullets;
	static sf::Texture  bulletRedText;
	static sf::Texture bulletBlueText;

public:
	enum BulletsId{redfireBullet,blueFireBullet};
	static void loadTextures();
	Bullets();
	Bullets(BulletsId bulletId, const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity);
	Bullets(const sf::Vector2f & Pos, const sf::Vector2f & EntVelocity);
	 void Update();
	 void Update2(const sf::Vector2f & EntPos); 
	~Bullets();
};

