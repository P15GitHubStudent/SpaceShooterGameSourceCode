
#pragma once


#include"Entity.h"

class Explosion : public Entity
{
private:
	static sf::Texture explosionTexture;
public:
	static void loadTexture();
	Explosion(const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity);
	void Update();
	~Explosion();
};



