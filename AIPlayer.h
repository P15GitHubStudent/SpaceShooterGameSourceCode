#pragma once

#include<SFML\Graphics.hpp>
#include"Update.h"
#include"Entity.h"
#include"Animation.h"
#include<list>
#include<memory>


class AiPlayer : public Entity 
{
public:
	static std::list<Entity *>laserShoots;
	static std::list<std::unique_ptr<Entity>> LaserShoots;
	AiPlayer(const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity);
	AiPlayer();
	~AiPlayer();
	virtual void Update();
	static void LoadTextures();
	void CreateAiPlayer(const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity);

	private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	//std::list<Entity *>laserShoots;
	Delay AiDelay;
	enum {AiPlayerSize=4};
	static sf::Texture AiPlayerTextureArray[AiPlayerSize];
};

