#include "AIPlayer.h"
#include"Exceptions.h"
#include<list>
#include"Bullets.h"


sf::Texture AiPlayer::AiPlayerTextureArray[AiPlayerSize];
std::list<Entity *> AiPlayer::laserShoots;



AiPlayer::AiPlayer(const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity):Entity("Ai_Player", Pos, EntityVelocity,AiPlayerTextureArray[rand()%4])
{
	CreateAiPlayer(Pos, EntVelocity);
}


void AiPlayer::CreateAiPlayer(const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity)
{

	EntPos = Pos;
	EntSprite.setPosition(Pos);
	EntAnimation.CreateAnimation(0.3, AiPlayerTextureArray[rand() % 4], EntSprite);
	EntSprite.setTexture(AiPlayerTextureArray[rand() % 4]);
	for (int c = 0; c < 6; c++)
	EntAnimation.AddAnimFrame(sf::IntRect(0, 30 * c, 40, 30));
	EntSprite.setTextureRect(EntAnimation.GetFrameIndex(0));
	int RandDelay = rand() % 11;
	AiDelay.SetUpdateTime(0.5 + RandDelay * 0.1);
}

AiPlayer::AiPlayer()
{

}

void AiPlayer::LoadTextures()
{
	if (!AiPlayerTextureArray[0].loadFromFile("images/e_f1.png"))throw FAILED_TO_LOAD_TEXTURE("e_f1.png");
	if (!AiPlayerTextureArray[1].loadFromFile("images/e_f2.png"))throw FAILED_TO_LOAD_TEXTURE("e_f2.png");
	if (!AiPlayerTextureArray[2].loadFromFile("images/e_f3.png"))throw FAILED_TO_LOAD_TEXTURE("e_f3.png");
	if (!AiPlayerTextureArray[3].loadFromFile("images/e_f4.png"))throw FAILED_TO_LOAD_TEXTURE("e_f4.png");
}

void AiPlayer::Update()
{

	//AccelarateEntity();

	Entity::Update();

	EntAnimation.Play();

	AiDelay.IncreaseTime();

	if (AiDelay.IsTimeToUpdate())
   {
	 
			
			for (int c = 0; c < 3; c++)
			{
				laserShoots.push_back(new Bullets(Bullets::redfireBullet,sf::Vector2f(EntPos.x - 5, EntPos.y), sf::Vector2f(-7, std::cos(60*c+c))));
			}

			EntVelocity.y = rand() % 2 == 0 ? 1 : -1;

			if (EntPos.y <= 0)
			{
				EntVelocity.y = 1;
				EntPos.y = 0;

			}

			else if (EntPos.y >=600)
			{
				EntVelocity.y = -1;
				EntPos.y = 600;
			}

			AiDelay.RestartClock();
		}

		
	}


void AiPlayer::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	Entity::draw(target, states);
	/*
	for (auto i : laserShoots)
	{
		target.draw(*i);
	}
	*/

}



AiPlayer::~AiPlayer()
{
}
