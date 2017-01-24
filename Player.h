#pragma once

#include<SFML\Graphics.hpp>
#include"Entity.h"
#include<list>


class Player :public Entity
{
public:
	Player(const sf::Vector2f & Pos,const sf::Vector2f & Velocity);
	Player();
	void CreatePlayer(const sf::Vector2f & Pos,const sf::Vector2f & Velocity);
	virtual void Update();
	void Accelarate();
	static std::list<Entity *>laserShots;
	static void increasePlayerScore(int times);
	static int  getPlayerScore();
	static int getPlayerLives();
	static void increasePlayerLive();
	static void decreasePlayerLive();
	static void initStaticPlayerInfo();
	~Player();
private:
const float invisibilitySecsMax;
const float immortalitySecsMax;
mutable float currentinvisibilitySecs;
mutable float currentImortalitySecs;
mutable Delay invisibilityDelay;
mutable Delay immortalityEffectDelay;
mutable int invisibillityCounter;
static int pLives;
static int pScore;
virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
int counter;
	sf::Texture PTexture;
};


