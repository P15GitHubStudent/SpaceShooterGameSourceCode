#include "Player.h"
#include"Exceptions.h"
#include<iostream>
#include"AIPlayer.h"

//na do ftaikso mia klassi me static member kai katastrepsoume tin klassi

std::list<Entity *> Player::laserShots;
int Player::pScore = 0;
int Player::pLives = 10;

Player::Player(const sf::Vector2f & Pos, const sf::Vector2f & Velocity) :invisibilitySecsMax(0.15f), immortalitySecsMax(1.5)
{
	PTexture.setSmooth(true);
	CreatePlayer(Pos, Velocity);
	pScore = 0;
	pLives = 10;
	
}

Player::Player() :invisibilitySecsMax(0.15f), immortalitySecsMax(0.6)
{

}

int Player::getPlayerScore()
{
	return pScore;
}

void Player::increasePlayerScore(int times)
{
	pScore+=times;
}

void Player::decreasePlayerLive()
{
	pLives--;
}

int Player::getPlayerLives()
{
	return pLives;
}

void Player::increasePlayerLive()
{
	pLives++;
}

void Player::CreatePlayer(const sf::Vector2f & Pos,const sf::Vector2f & EntVelocity)
{

	if (!PTexture.loadFromFile("images/Spritesheet.png"))throw FAILED_TO_LOAD_TEXTURE("images/Spritesheet.png");

	Entity::CreateEntity("player", Pos,EntVelocity,PTexture);

	EntAnimation.CreateAnimation(0.1f,PTexture,EntSprite);

	for (int c = 0; c < 4; c++)
	{
		EntAnimation.AddAnimFrame(sf::IntRect(0, 29 * c, 64, 29));
	}

	EntSprite.setTextureRect(EntAnimation.GetFrameIndex(0));

	invisibilityDelay.SetUpdateTime(0);

	currentinvisibilitySecs = 0;

	currentImortalitySecs = 0;

	immortalityEffectDelay.SetUpdateTime(0);

	invisibilityDelay.SetUpdateTime(0);


}




void Player::Update()
{
	Entity::Update();	

	if (EntPos.y <= 0)
	{
		EntPos.y = 0;	
		//EntSprite.setPosition(EntPos.x, 0);
	}
	if (EntPos.y >= 550)
	{
		EntPos.y = 550;
	}
	if (EntPos.x <= 0)
	{
		EntPos.x = 0;
	}
	if (EntPos.x >= 630)
	{
		EntPos.x = 630;
	}

	updateEntityList(laserShots);

	immortalityEffectDelay.IncreaseTime();


	//στην αρχή αμα περάσουν 0 δευτερόλεπτα 
	if (immortalityEffectDelay.IsTimeToUpdate())
	{
		currentImortalitySecs = 0;
		immortalityEffectDelay.SetUpdateTime(currentImortalitySecs);

		//κοιτά για collision
		for (auto i : AiPlayer::laserShoots)
		{

			//currentImortalitySecs = immortalitySecsMax;
			//immortalityEffectDelay.SetUpdateTime(currentImortalitySecs);
			
			//αμα υπάρξει collision τότε  μπές σε invisibillity mod
			if (Entity::Collide(this, i)) //sukrouontai sfaira me ai paiktes laser !		
			{
				i->entityAlive = false;
				currentinvisibilitySecs = invisibilitySecsMax;
				invisibilityDelay.SetUpdateTime(invisibilitySecsMax);
				currentImortalitySecs =immortalitySecsMax;
				immortalityEffectDelay.SetUpdateTime(immortalitySecsMax);
				decreasePlayerLive();
			}
		}
	}

}


void Player::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	invisibilityDelay.IncreaseTime();

	if (invisibilityDelay.IsTimeToUpdate())
	{
		Entity::draw(target, states);

		if (currentImortalitySecs == 0)
		{
			currentinvisibilitySecs = 0;
			invisibilityDelay.SetUpdateTime(currentinvisibilitySecs);
		}
	}

	for (auto i : laserShots)
	{
		target.draw(*i);
	}

}

Player::~Player()
{
	Entity::deleteEntityList(laserShots);
	laserShots.clear();
}
