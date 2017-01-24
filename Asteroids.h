#pragma once

#include"Entity.h"

class Asteroids : public Entity
{

private:
	static sf::Texture AsteroidText;	
public:
	static void initTextures();
	Asteroids(const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity);
	void Update();
	void Update2(const sf::Vector2f &  PlayersPosition);
	~Asteroids();
};

