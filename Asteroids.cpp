#include "Asteroids.h"
#include"Exceptions.h"

sf::Texture Asteroids::AsteroidText;




Asteroids::Asteroids(const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity) :Entity("asteroid", Pos, EntityVelocity, AsteroidText)
{
	EntAnimation.CreateAnimation(0.3, AsteroidText, EntSprite);

	for (int c = 0; c < 14 ; c++)
	{
		EntAnimation.AddAnimFrame(sf::IntRect(95 * c, 0, 95, 95));
	}
	
	EntSprite.setTextureRect(EntAnimation.GetFrameIndex(0));

	EntSprite.setPosition(Pos);

}


void Asteroids::initTextures()
{
	if (!AsteroidText.loadFromFile("images/asteroid-1-96.png"))throw FAILED_TO_LOAD_TEXTURE("ASTEROIDS-1-96.png");

	AsteroidText.setSmooth(true);
}


void Asteroids::Update()
{
	Entity::Update();
	EntAnimation.Play();
	if (EntPos.x <= 0)entityAlive = false;

}


void Asteroids::Update2(const sf::Vector2f &  PlayerPos)
{
	Entity::Update();
	EntAnimation.Play();
	if (EntPos.x < PlayerPos.x && PlayerPos.x-EntPos.x >100)
	{
		EntPos.x = PlayerPos.x +750;
	}
}


Asteroids::~Asteroids()
{
}
