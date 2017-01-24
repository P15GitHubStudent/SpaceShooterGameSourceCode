

#include "Explosion.h"
#include"Exceptions.h"

//Entity(const std::string & EntityName, const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity, const sf::Texture & EntTexture);

sf::Texture Explosion::explosionTexture;

Explosion::Explosion(const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity) : Entity("explosion", Pos, EntityVelocity, explosionTexture)
{

	EntSprite.setOrigin(sf::Vector2f(128 / 2, 128 / 2));

	EntAnimation.CreateAnimation(0.005, explosionTexture, EntSprite);

	sf::Vector2i AnimationCounter(0,0);

	for (int c = 0; c < 4; c++)
	{
		for (int j = 0; j < 8; j++)
		{
			EntAnimation.AddAnimFrame(sf::IntRect(j * 128, c * 128, 128, 128));
		}
	}

	EntSprite.setTextureRect(EntAnimation.GetFrameIndex(0));
	
}

void Explosion::loadTexture()
{
	if (!explosionTexture.loadFromFile("images/explosion.png")) throw FAILED_TO_LOAD_TEXTURE("explosion.png");
}

void Explosion::Update()
{
	Entity::Update();

	EntAnimation.Play();

	if (EntAnimation.IsOver())
	{
		entityAlive = false;
	}
	
}

Explosion::~Explosion()
{
}
